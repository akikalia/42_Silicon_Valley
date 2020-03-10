/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:56:56 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/19 06:30:23 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		elem->content = (void *)content;
		elem->content_size = content_size;
	}
	else
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	elem->next = NULL;
	return (elem);
}
