/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:42:35 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/07 23:37:50 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	place(t_node *n, t_list **alst, int *flag)
{
	n->temp->next = n->curr;
	if (n->prev != NULL)
		n->prev->next = n->temp;
	else
		*alst = n->temp;
	*flag = 0;
}

void		ft_lstadd_sorted(t_list **alst,
int (*cmp)(void*a, void*b), t_file *s, int flag)
{
	t_node		n;

	n.prev = NULL;
	n.temp = ft_lstnew((void*)s, sizeof(*s));
	n.curr = *alst;
	if (n.curr == NULL)
	{
		*alst = n.temp;
		flag = 0;
	}
	while (n.curr && flag)
	{
		if (cmp(n.curr->content, (void*)s) > 0)
			place(&n, alst, &flag);
		n.prev = n.curr;
		n.curr = n.curr->next;
	}
	if (n.curr == NULL && flag)
		n.prev->next = n.temp;
}

void		add_file_sorted(t_list **alst, char *name, int flag)
{
	t_node n;

	n.prev = NULL;
	n.temp = ft_lstnew(name, (ft_strlen(name) + 1) * sizeof(char));
	n.curr = *alst;
	if (n.curr == NULL)
	{
		*alst = n.temp;
		flag = 0;
	}
	while (n.curr && flag)
	{
		if (ft_strcmp(n.curr->content, name) > 0)
			place(&n, alst, &flag);
		n.prev = n.curr;
		n.curr = n.curr->next;
	}
	if (n.curr == NULL && flag)
		n.prev->next = n.temp;
}
