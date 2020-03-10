/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 03:48:55 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/22 20:06:14 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int		ch(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ ((~x) & z));
}

unsigned int		maj(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

unsigned int		convert(char *str, int size)
{
	unsigned int	res;
	int				i;
	char			c;

	i = 0;
	while (i < 2)
	{
		size--;
		c = str[i];
		str[i] = str[size];
		str[size] = c;
		i++;
	}
	res = *((unsigned int *)str);
	return (res);
}

unsigned long		appendsha(char **str)
{
	unsigned long	len;
	unsigned long	orig;
	char			c;
	char			*temp;
	unsigned long	temp2;

	orig = ft_strlen(*str);
	len = orig % 64;
	len = (len >= 56) ? (64 - len + 56) : (56 - len);
	temp = malloc(len + orig + 8 + 1);
	memcpy(temp, *str, orig);
	c = 0x80;
	memcpy(temp + orig, &c, 1);
	bzero(temp + orig + 1, len - 1);
	temp2 = orig * 8;
	convert((char*)&temp2, 8);
	memcpy(temp + orig + len, &temp2, 8);
	len = len + orig + 8;
	*str = temp;
	return (len);
}

char				*ap_z(char *str)
{
	int				i;

	i = 0;
	while (ft_strlen(str) < 8)
		str = ft_stradd(ft_strdup("0"), str);
	return (str);
}
