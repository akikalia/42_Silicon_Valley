/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:02:52 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/15 22:53:26 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*alloc;
	size_t		i;

	i = 0;
	alloc = (char *)malloc(size + 1);
	if (alloc == NULL)
		return (NULL);
	while (i <= size)
	{
		alloc[i] = '\0';
		i++;
	}
	return (alloc);
}
