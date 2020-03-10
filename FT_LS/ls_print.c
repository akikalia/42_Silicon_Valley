/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:45:50 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/08 14:51:23 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static long long int	get_total(t_list *head)
{
	long long			i;
	long long int		temp;

	i = 0;
	while (head)
	{
		if (0 < (temp = ((t_file *)(head->content))->stt->st_blocks))
			i += temp;
		head = head->next;
	}
	return (i);
}

static void				print_attr(mode_t *md, t_file *f)
{
	struct passwd		*temp;

	ft_printf("%c", f->type);
	ft_printf((*md & S_IRUSR) ? "r" : "-");
	ft_printf((*md & S_IWUSR) ? "w" : "-");
	ft_printf((*md & S_IXUSR) ? "x" : "-");
	ft_printf((*md & S_IRGRP) ? "r" : "-");
	ft_printf((*md & S_IWGRP) ? "w" : "-");
	ft_printf((*md & S_IXGRP) ? "x" : "-");
	ft_printf((*md & S_IROTH) ? "r" : "-");
	ft_printf((*md & S_IWOTH) ? "w" : "-");
	ft_printf((*md & S_IXOTH) ? "x" : "-");
	ft_printf(" %3d", f->stt->st_nlink);
	if ((temp = getpwuid(f->stt->st_uid)) != NULL)
		ft_printf(" %-8.15s ", temp->pw_name);
	else
		ft_printf("%- 15d", f->stt->st_uid);
}

static void				print_long(t_file *f)
{
	char				*t;
	char				*link;

	t = ctime(&(f->stt->st_mtime));
	if (time(NULL) - f->stt->st_mtime > SIX_MONTHS
	|| f->stt->st_mtime - time(NULL) > SIX_MONTHS)
		t = ft_straddfree(ft_strsub(t, 4, 7), ft_strsub(t, 19, 5));
	else
		t = ft_strsub(t, 4, 12);
	print_attr(&(f->stt->st_mode), f);
	ft_printf(" %-12.15s ", getgrgid(f->stt->st_gid)->gr_name);
	ft_printf("%6lld %12.12s %-.300s", (f->stt->st_size), t, f->name);
	link = ft_strnew(100);
	if (f->type == 'l')
	{
		readlink(f->path, link, 100);
		link = ft_straddfree(ft_strdup(" -> "), link);
	}
	ft_printf("%s\n", link);
	free(t);
	free(link);
}

static void				print_entry(t_file *data, t_flag *f)
{
	if (f->l)
		print_long(data);
	else
		ft_printf("%s\n", data->name);
}

void					print_list(t_list *head, t_flag *f)
{
	if (f->l)
		ft_printf("total %lld\n", get_total(head));
	while (head)
	{
		print_entry(head->content, f);
		head = head->next;
	}
}
