/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:31:49 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/14 13:15:01 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i != 0)
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i--;
	}
	if (s[i] == c)
		return ((char *)(&s[i]));
	return (NULL);
}
