/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:31:01 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 16:28:30 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && i < n - 1 && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (n == 0)
		return (0);
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
