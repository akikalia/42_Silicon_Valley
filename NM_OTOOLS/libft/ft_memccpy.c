/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:33:06 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/14 13:49:35 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (((unsigned char *)src)[i] != (unsigned char)c)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (i == n - 1)
			return (NULL);
		i++;
	}
	((char *)dst)[i] = ((char *)src)[i];
	i++;
	return ((void *)&(((char *)dst)[i]));
}
