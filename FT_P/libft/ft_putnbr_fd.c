/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:24:12 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 17:18:57 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	alloc[15];
	int		i;
	int		neg;
	long	num;

	i = 13;
	num = (long)n;
	neg = 0;
	alloc[14] = '\0';
	if (num == 0)
		ft_putstr_fd("0", fd);
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
	ft_putstr_fd(&(alloc[++i]), fd);
}
