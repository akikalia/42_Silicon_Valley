/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:54:36 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 13:35:39 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*alloc;
	size_t	i;

	i = 0;
	if ((alloc = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)alloc)[i] = 0;
		i++;
	}
	return (alloc);
}
