/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:15:32 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 13:22:39 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
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
		ft_putstr("0");
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
	ft_putstr(&(alloc[++i]));
}
