/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 02:07:18 by akikalia          #+#    #+#             */
/*   Updated: 2019/03/06 15:50:05 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		usage(void)
{
	ft_putstr("usage: fillit source_file\n");
	return (0);
}

void	del(void *content, size_t content_size)
{
	int			*block;

	(void)content_size;
	block = (int *)content;
	free(block);
	block = NULL;
}

int		error_output(t_list **list)
{
	ft_lstdel(list, del);
	ft_putstr("error\n");
	return (0);
}

void	free_arr(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr)[i] != NULL)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}

void	print_res(char **res)
{
	int i;

	i = 0;
	while (res[i] != NULL)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
		i++;
	}
	free_arr(&res);
}
