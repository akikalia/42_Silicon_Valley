/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <akikalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:01:51 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/18 23:02:10 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned long		append(char **str, int i)
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
	if (i == SHA256)
		temp2 = orig * 8;
	else
		temp2 = orig * 8;
	memcpy(temp + orig + len, &temp2, 8);
	len = len + orig + 8;
	*str = temp;
	return (len);
}
