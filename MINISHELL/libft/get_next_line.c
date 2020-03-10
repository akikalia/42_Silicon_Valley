/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:48:42 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/23 00:01:07 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*curr_file(int fd, t_list **file)
{
	t_list			*temp;

	temp = *file;
	while (temp)
	{
		if ((int)(temp->content_size) == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(file, temp);
	return (*file);
}

int		get_line(t_list *curr, char **line)
{
	char			*temp;

	if ((temp = ft_strchr((char *)(curr->content), '\n')))
	{
		temp[0] = '\0';
		if ((*line = ft_strdup((char*)(curr->content))) == NULL)
			return (-1);
		if ((temp = ft_strdup(temp + 1)) == NULL)
			return (-1);
		free((char*)(curr->content));
		if (temp[0] == '\0')
		{
			free(temp);
			temp = NULL;
		}
		curr->content = (void *)temp;
	}
	else
	{
		if ((*line = ft_strdup((char*)(curr->content))) == NULL)
			return (-1);
		free((char*)(curr->content));
		curr->content = NULL;
	}
	return (1);
}

int		readline(int fd, t_list *curr)
{
	int				res;
	char			*buf;
	char			*temp;
	int				flag;

	if ((buf = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	flag = 1;
	while (flag && (res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		if (res < 0)
			return (-1);
		if (curr->content != NULL)
			temp = ft_strjoin((char *)(curr->content), buf);
		else
			temp = ft_strdup(buf);
		free(curr->content);
		curr->content = (void *)temp;
		if (ft_strchr((char *)(curr->content), '\n') != NULL)
			flag = 0;
	}
	free(buf);
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*curr;
	int				res;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || fd > MAX_FD)
		return (-1);
	if ((curr = curr_file(fd, &file)) == NULL)
		return (-1);
	res = readline(fd, curr);
	if (res < 0)
		return (-1);
	if (res == 0 && (curr->content == NULL))
		return (0);
	if ((get_line(curr, line)) == -1)
		return (-1);
	return (1);
}
