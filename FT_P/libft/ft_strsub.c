/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:39 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 17:14:52 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*alloc;
	size_t		i;

	if (s == NULL)
		return (NULL);
	if ((alloc = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	alloc[len] = '\0';
	i = 0;
	while (i < len)
	{
		alloc[i] = s[start + i];
		i++;
	}
	return (alloc);
}
