/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 02:07:02 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/26 03:17:53 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_bounds(char bl[5][5], int i, int n, int *blnum)
{
	int			m;

	m = 0;
	if (bl[i][n] == '#')
	{
		(*blnum)++;
		if (n < 3 && bl[i][n + 1] == '#')
			m++;
		if (i < 3 && bl[i + 1][n] == '#')
			m++;
		if (i == 0 && n == 0)
			return (m);
		if (n != 0 && bl[i][n - 1] == '#')
			m++;
		if (i != 0 && bl[i - 1][n] == '#')
			m++;
		return (m);
	}
	else if (bl[i][n] == '.')
		return (0);
	return (0);
}

int		test_input(char block[5][5])
{
	int		i;
	int		n;
	int		count;
	int		blnum;

	blnum = 0;
	i = 0;
	count = 0;
	while (i != 4)
	{
		n = 0;
		while (n != 4)
		{
			count += check_bounds(block, i, n, &blnum);
			n++;
		}
		i++;
	}
	if ((count != 6 && count != 8) || blnum != 4)
		return (0);
	return (1);
}

void	ft_lstappend(t_list **head, t_list *new)
{
	t_list	*temp;

	temp = *head;
	if (!*head)
		*head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int		split_test(int **arr, char buf[22], int l, int i)
{
	int		n;
	char	block[5][5];

	n = 0;
	while (i != 4)
	{
		while (buf[n] != '\n')
		{
			if (buf[i * 5 + 4] != '\n')
				return (0);
			block[i][n % 5] = buf[n];
			if (block[i][n % 5] == '#' && l <= 7)
			{
				(*arr)[l++] = i;
				(*arr)[l++] = n % 5;
			}
			else if (block[i][n % 5] != '.' || l == 7)
				return (0);
			n++;
		}
		n++;
		i++;
	}
	return (test_input(block));
}

int		get_input(int fd, t_list **list)
{
	char	buf[22];
	int		err;
	int		m;
	int		*arr;
	int		flag;

	m = 0;
	flag = 0;
	while ((err = read(fd, buf, 21)) > 0)
	{
		if ((err == 21 && buf[20] != '\n') || err < 20 || err > 21)
			return (0);
		if (err == 20)
			flag = 1;
		arr = (int *)malloc(sizeof(int) * 9);
		if (!split_test(&arr, buf, 0, 0))
			return (0);
		arr[8] = m;
		ft_lstappend(list, ft_lstnew((void*)arr, sizeof(int *) * 9));
		m++;
	}
	if ((err <= 0 && m == 0) || flag == 0)
		return (0);
	return (1);
}
