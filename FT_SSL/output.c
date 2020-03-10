/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 04:44:30 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/23 00:44:41 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char				*get_hash_name(t_flag *f)
{
	char			*arr[4];

	arr[MD5] = "MD5";
	arr[SHA256] = "SHA256";
	arr[SHA224] = "SHA224";
	return (arr[f->hash_alg]);
}

void				usage(int i, char *str)
{
	if (i == S_TRUE)
	{
		ft_printf("ft_ssl: option requires an argument -- s\n");
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	}
	else if (i == 0)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else if (i == 1)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", str);
		ft_printf("Standard commands:\n\n");
		ft_printf("Message Digest commands:\n");
		ft_printf("md5\n");
		ft_printf("sha256\n");
		ft_printf("sha224\n\n");
		ft_printf("Cipher commands:\n");
	}
	exit(0);
}

char				*hash(t_flag *flags, char *str)
{
	char			*(*f[4])(char *);

	f[MD5] = &md5;
	f[SHA256] = &sha256;
	f[SHA224] = &sha224;
	return (f[flags->hash_alg](str));
}

static void			print_one(t_list *head, t_flag *f)
{
	t_file			*file;
	char			*hash_name;
	char			*temp;

	hash_name = get_hash_name(f);
	file = head->content;
	if (file->fd == ISDIR)
		ft_printf("ft_ssl: %s: %s: Is a directory\n", hash_name, file->name);
	else if (file->fd < 0)
		ft_printf("ft_ssl: %s: %s: No such file or directory\n"
				, hash_name, file->name);
	else
	{
		temp = hash(f, file->content);
		if (f->q)
			ft_printf("%s\n", temp);
		else if (f->r)
			ft_printf("%s %s\n", temp, file->name);
		else
			ft_printf("%s (%s) = %s\n", hash_name,
					file->name, temp);
		free(temp);
	}
}

void				print_all(t_list *head, t_flag *f)
{
	while (head)
	{
		print_one(head, f);
		head = head->next;
	}
}
