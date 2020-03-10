/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:27:04 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/14 18:22:57 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		size;

	size = 0;
	while (s1[size] != '\0')
		size++;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	size = 0;
	while (s1[size] != '\0')
	{
		dup[size] = s1[size];
		size++;
	}
	dup[size] = s1[size];
	return (dup);
}
