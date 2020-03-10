/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:53:17 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/07 21:08:07 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_lstat(t_file *file)
{
	file->stt = malloc(sizeof(struct stat));
	if (lstat(file->path, file->stt) < 0)
		return (-1);
	else
	{
		if (S_ISREG(file->stt->st_mode))
			file->type = '-';
		else if (S_ISDIR(file->stt->st_mode))
			file->type = 'd';
		else if (S_ISCHR(file->stt->st_mode))
			file->type = 'c';
		else if (S_ISBLK(file->stt->st_mode))
			file->type = 'b';
		else if (S_ISFIFO(file->stt->st_mode))
			file->type = 'p';
		else if (S_ISLNK(file->stt->st_mode))
			file->type = 'l';
		else
			file->type = 's';
	}
	return (0);
}

void	free_all(t_list *head)
{
	t_file	*file;
	t_list	*prev;

	while (head)
	{
		file = (t_file *)(head->content);
		prev = head;
		free(file->path);
		free(file->name);
		free(file->stt);
		free(file);
		head = head->next;
		free(prev);
	}
}

char	*ft_straddfree(char *a, char *b)
{
	char	*temp;

	if (a != NULL && b != NULL)
	{
		temp = ft_strjoin(a, b);
		free(a);
		free(b);
	}
	else
	{
		if (a == NULL)
			temp = b;
		else
			temp = a;
	}
	return (temp);
}

int		link_len(t_list *head)
{
	int		i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
