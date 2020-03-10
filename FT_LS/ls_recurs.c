/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:51:14 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/08 14:32:08 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*print_err(char *str, t_file *file)
{
	if (!ft_strcmp("Permission denied", strerror(errno)))
		print_denied(str);
	else if (!ft_strcmp("Bad file descriptor", strerror(errno)))
		print_not_dir(str);
	else if (!ft_strcmp("Not a directory", strerror(errno)))
		print_not_dir(str);
	free(file);
	return (NULL);
}

static void		*get_func(t_flag *f)
{
	int				(*cmp)(void*, void*);

	if (f->r && f->t)
		cmp = &cmprt;
	else if (f->r)
		cmp = &cmpr;
	else if (f->t)
		cmp = &cmpt;
	else
		cmp = &cmp_;
	return (cmp);
}

t_list			*read_dir(const char *str, t_flag *f, DIR **curr)
{
	struct dirent	*dir;
	t_file			*file;
	t_list			*head;

	head = NULL;
	file = malloc(sizeof(t_file));
	if (!(*curr = opendir(str)))
		return (print_err((char *)str, file));
	dir = readdir(*curr);
	while (dir != NULL)
	{
		if (dir->d_name[0] != '.' || f->a)
		{
			file->name = ft_strdup(dir->d_name);
			file->path = ft_straddfree(ft_straddfree(ft_strdup(str),
			ft_strdup("/")), ft_strdup(dir->d_name));
			if (get_lstat(file) == -1)
				return (NULL);
			ft_lstadd_sorted(&head, get_func(f), file, 1);
		}
		dir = readdir(*curr);
	}
	closedir(*curr);
	free(file);
	return (head);
}

static void		print_all_dirs(const char *str, t_list *head, t_flag *f)
{
	t_file			*file;
	char			*temp;

	while (head)
	{
		file = (t_file *)(head->content);
		temp = file->name;
		if ((file->type == 'd') && ft_strcmp(temp, ".")
		&& ft_strcmp(temp, ".."))
		{
			ft_printf("\n");
			temp = ft_straddfree(ft_straddfree(ft_strdup(str),
			ft_strdup("/")), ft_strdup(temp));
			ft_printf("%s:\n", temp);
			print_all(temp, f);
			free(temp);
		}
		head = head->next;
	}
}

void			print_all(const char *str, t_flag *f)
{
	t_list		*head;
	DIR			*curr;

	head = read_dir(str, f, &curr);
	if (head != NULL)
	{
		print_list(head, f);
		if (f->r_upper)
			print_all_dirs(str, head, f);
		free_all(head);
	}
}
