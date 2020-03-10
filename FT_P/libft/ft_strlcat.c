/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:52:55 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/15 22:43:55 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dstlen;
	size_t srclen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize == 0 || dstlen >= dstsize)
		return (srclen + dstsize);
	i = 0;
	while (i + dstlen + 1 < dstsize)
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}
