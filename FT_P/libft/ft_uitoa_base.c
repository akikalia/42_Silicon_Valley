/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 06:35:15 by akikalia          #+#    #+#             */
/*   Updated: 2019/04/19 06:37:17 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_uitoa_base(unsigned long long int num, int base)
{
	char			alloc[50];
	char			*res;
	int				i;

	res = "0123456789abcdef";
	if (num == 0)
		return (ft_strdup("0"));
	i = 48;
	alloc[49] = '\0';
	while (num != 0)
	{
		alloc[i--] = res[(num % base)];
		num /= base;
	}
	return (ft_strdup(&(alloc[++i])));
}
