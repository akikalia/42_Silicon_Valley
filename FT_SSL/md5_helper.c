/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:16:53 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/19 06:16:55 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	rotate_left(unsigned int x, unsigned int s)
{
	return ((x << s) | (x >> (sizeof(s) * 8 - s)));
}

unsigned int	f(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) | ((~x) & z));
}

unsigned int	g(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & z) | (y & (~z)));
}

unsigned int	h(unsigned int x, unsigned int y, unsigned int z)
{
	return (x ^ y ^ z);
}

unsigned int	i(unsigned int x, unsigned int y, unsigned int z)
{
	return (y ^ (x | ~z));
}
