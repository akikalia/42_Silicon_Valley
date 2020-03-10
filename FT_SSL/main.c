/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:26:45 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/23 01:13:38 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int					get_hash(char *str, t_flag *f)
{
	char			*arr[4];
	int				i;

	i = 0;
	arr[MD5] = "md5";
	arr[SHA256] = "sha256";
	arr[SHA224] = "sha224";
	while (i < 3)
	{
		if (!ft_strcmp(str, arr[i]))
		{
			f->hash_alg = i;
			return (1);
		}
		i++;
	}
	f->hash_alg = -1;
	return (0);
}

void				parse(t_flag *f, t_list **head, char **argv, int argc)
{
	int				i;
	int				flag;
	int				s_flag;

	i = 1;
	f->r = 0;
	f->q = 0;
	f->p = 0;
	flag = 0;
	if (argc < 2)
		usage(0, NULL);
	if (!get_hash(argv[i++], f))
		usage(1, argv[i - 1]);
	while (i < argc)
	{
		if (!(s_flag = get_flag(argv[i], f, &flag)))
			ft_lstappend(head, ft_lstnew(get_file(argv[i], 0), 0));
		else if (s_flag == S_TRUE && !(i + 1 < argc))
			usage(S_TRUE, NULL);
		else if (s_flag == S_TRUE && i + 1 < argc)
			ft_lstappend(head, ft_lstnew(get_file(argv[++i], s_flag), 0));
		else if (s_flag == S_NEXT)
			ft_lstappend(head, ft_lstnew(get_file(argv[i], s_flag), 0));
		i++;
	}
}

void				print_stdin(t_flag *f)
{
	char			buf[10000];
	int				err;
	char			*temp;

	if ((err = read(0, buf, 999)) >= 0)
	{
		buf[err] = '\0';
		temp = hash(f, buf);
		if (f->p)
			ft_printf("%s%s\n", buf, temp);
		else
			ft_printf("%s\n", temp);
		free(temp);
	}
}

void				free_all(t_list *head)
{
	t_file *file;
	t_list *temp;

	while (head)
	{
		file = head->content;
		free(file->content);
		free(file->name);
		free(file);
		temp = head;
		head = head->next;
		free(temp);
	}
}

int					main(int argc, char **argv)
{
	t_flag			f;
	t_list			*files;

	files = NULL;
	parse(&f, &files, argv, argc);
	if (!files || f.p)
		print_stdin(&f);
	if (files)
		print_all(files, &f);
	free_all(files);
	return (0);
}
