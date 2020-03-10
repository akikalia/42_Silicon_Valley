/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:36:00 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/15 23:37:07 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			alloc[15];
	int				i;
	int				neg;
	long			num;

	i = 13;
	num = (long)n;
	neg = 0;
	alloc[14] = '\0';
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		neg = 1;
		num *= -1;
	}
	while (num != 0)
	{
		alloc[i--] = num % 10 + '0';
		num /= 10;
	}
	if (neg == 1)
		alloc[i--] = '-';
	return (ft_strdup(&(alloc[++i])));
}
