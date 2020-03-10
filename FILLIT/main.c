/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 01:44:29 by akikalia          #+#    #+#             */
/*   Updated: 2019/03/06 14:33:20 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	char	**res;
	int		i;

	list  = NULL;
	if (argc != 2)
		return (usage());
	if ((fd = open(argv[1], O_RDONLY)) <= 1)
		return (error_output(&list));
	if (!get_input(fd, &list))
		return (error_output(&list));
	i = 2;
	create_board(&res, i);
	while (solve(list, &res, i) == 0)
	{
		free_arr(&res);
		create_board(&res, ++i);
	}
	ft_lstdel(&list, del);
	close(fd);
	print_res(res);
	return (0);
}
