/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:42:16 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 18:05:54 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delete_content(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *nlist;

	if (lst == NULL)
		return (NULL);
	if ((nlist = f(lst)) == NULL)
		return (NULL);
	temp = nlist;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((temp->next = f(lst)) == NULL)
		{
			ft_lstdel(&nlist, delete_content);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (nlist);
}
