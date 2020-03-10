/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 02:07:11 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/26 03:14:58 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_board(char ***str, int size)
{
	char	**copy;
	int		i;
	int		n;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (size + 1));
	copy[size] = NULL;
	while (i != size)
	{
		n = 0;
		copy[i] = ft_strnew(size);
		while (n != size)
		{
			copy[i][n++] = '.';
		}
		i++;
	}
	*str = copy;
}

int		add(t_list *list, char ***str, t_point p, int size)
{
	int		*b;
	char	c;

	c = 'A' + ((int*)(list->content))[8] * ('b' - 'a');
	b = (int *)list->content;
	if (p.i + b[2] - b[0] < size && p.n + b[3] - b[1] < size
			&& p.i + b[4] - b[0] < size && p.n + b[5] - b[1] < size
			&& p.i + b[6] - b[0] < size && p.n + b[7] - b[1] < size)
		if (p.i + b[2] - b[0] >= 0 && p.n + b[3] - b[1] >= 0
				&& p.i + b[4] - b[0] >= 0 && p.n + b[5] - b[1] >= 0
				&& p.i + b[6] - b[0] >= 0 && p.n + b[7] - b[1] >= 0)
			if ((*str)[p.i][p.n] == '.' &&
					(*str)[p.i + b[2] - b[0]][p.n + b[3] - b[1]] == '.' &&
					(*str)[p.i + b[4] - b[0]][p.n + b[5] - b[1]] == '.' &&
					(*str)[p.i + b[6] - b[0]][p.n + b[7] - b[1]] == '.')
			{
				(*str)[p.i][p.n] = c;
				(*str)[p.i + b[2] - b[0]][p.n + b[3] - b[1]] = c;
				(*str)[p.i + b[4] - b[0]][p.n + b[5] - b[1]] = c;
				(*str)[p.i + b[6] - b[0]][p.n + b[7] - b[1]] = c;
				return (1);
			}
	return (0);
}

void	rem(t_list *list, char ***str, t_point p)
{
	int		*b;

	b = (int *)list->content;
	(*str)[p.i][p.n] = '.';
	(*str)[p.i + b[2] - b[0]][p.n + b[3] - b[1]] = '.';
	(*str)[p.i + b[4] - b[0]][p.n + b[5] - b[1]] = '.';
	(*str)[p.i + b[6] - b[0]][p.n + b[7] - b[1]] = '.';
}

int		solve(t_list *list, char ***str, int size)
{
	t_point p;

	p.i = 0;
	if (list == NULL)
		return (1);
	while (p.i != size)
	{
		p.n = 0;
		while (p.n != size)
		{
			if (add(list, str, p, size))
			{
				if (list == NULL)
					return (1);
				if (solve(list->next, str, size))
					return (1);
				rem(list, str, p);
			}
			p.n++;
		}
		p.i++;
	}
	return (0);
}
