/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:39:12 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/08 15:26:40 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_flag		*f;
	t_list		*head;
	t_list		*temp;
	int			l;

	head = NULL;
	f = parse_flags(&head, argc, argv);
	if (!head)
		print_all(".", f);
	l = link_len(head);
	print_invalid(&head);
	while (head)
	{
		if (l > 1)
			ft_printf("%s:\n", head->content);
		print_all(head->content, f);
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
		if (head)
			ft_printf("\n");
	}
	free(f);
	return (0);
}
