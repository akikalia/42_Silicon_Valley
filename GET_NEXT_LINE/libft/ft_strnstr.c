/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:07:51 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 12:06:18 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	i;
	int		n;

	i = 0;
	while (hay[i] != '\0' && len > i)
	{
		n = 0;
		if (ndl[0] == '\0')
			return ((char *)(&hay[i]));
		while (ndl[n] == hay[i + n] && i + n < len)
		{
			if (ndl[n + 1] == '\0')
				return ((char *)(&hay[i]));
			n++;
		}
		i++;
	}
	if (i == 0 && ndl[0] == '\0')
		return ((char*)hay);
	return (NULL);
}
