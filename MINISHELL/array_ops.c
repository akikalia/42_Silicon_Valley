/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:42:45 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 17:43:43 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arr_dup(char ***arr)
{
	char	**dup;
	int		i;
	int		size;

	size = arr_size(*arr);
	i = 0;
	dup = malloc(sizeof(char *) * (size + 1));
	dup[size] = NULL;
	while ((*arr)[i])
	{
		dup[i] = ft_strdup((*arr)[i]);
		i++;
	}
	*arr = dup;
}

void	free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int		printstrarr(char arr_start, char spacec, char **argv)
{
	int		i;

	i = arr_start;
	while (argv[i])
	{
		if (i != arr_start)
			ft_putchar(spacec);
		ft_printf("%s", argv[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}

int		arr_size(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
