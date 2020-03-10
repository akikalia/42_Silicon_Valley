/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:13:55 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 12:04:34 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ndl)
{
	int i;
	int n;

	i = 0;
	while (hay[i] != '\0')
	{
		n = 0;
		if (ndl[0] == '\0')
			return (char *)(&hay[i]);
		while (ndl[n] == hay[i + n])
		{
			if (ndl[n + 1] == '\0')
				return (char *)(&hay[i]);
			n++;
		}
		i++;
	}
	if (i == 0 && ndl[0] == '\0')
		return ((char *)hay);
	return (NULL);
}
