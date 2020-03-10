/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:57:54 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/23 00:50:25 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char				*add_quotes(char *str)
{
	return (ft_stradd(ft_strdup("\""), ft_stradd(str, ft_strdup("\""))));
}

static int				get_s(char c)
{
	if (!c)
		return (S_TRUE);
	else
		return (S_NEXT);
}

int						get_flag(char *str, t_flag *f, int *flag)
{
	int				i;

	i = 0;
	if (str[i++] != '-' || *flag)
	{
		*flag = 1;
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == 'r')
			f->r = 1;
		else if (str[i] == 's')
			return (get_s(str[i + 1]));
		else if (str[i] == 'p')
			f->p = 1;
		else if (str[i] == 'q')
			f->q = 1;
		else
			return (0);
		i++;
	}
	if (f->q)
		f->r = 0;
	return (1);
}

void					get_s_content(int s_flag, t_file *file, char *str)
{
	if (s_flag == S_NEXT)
		file->content = ft_strdup(ft_strchr(str, 's') + 1);
	else
		file->content = ft_strdup(str);
	free(file->name);
	file->name = add_quotes(ft_strdup(file->content));
	if (file->fd > 0)
		close(file->fd);
	file->fd = 1;
}

t_file					*get_file(char *str, int s_flag)
{
	t_file			*file;
	char			buf[10000];
	int				err;

	file = malloc(sizeof(t_file));
	file->content = NULL;
	file->name = ft_strdup(str);
	file->s_flag = s_flag;
	file->fd = open(str, O_RDWR);
	if (s_flag)
		get_s_content(s_flag, file, str);
	else if (file->fd > 0 && (err = read(file->fd, buf, 999)) >= 0)
	{
		buf[err] = '\0';
		file->content = ft_strdup(buf);
		close(file->fd);
	}
	if (!ft_strcmp("Is a directory", strerror(errno)) && file->fd < 0)
		file->fd = ISDIR;
	return (file);
}
