/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:57:15 by akikalia          #+#    #+#             */
/*   Updated: 2019/02/16 16:42:14 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s != NULL)
	{
		if ((str = ft_strdup(s)) == NULL)
			return (NULL);
		i = 0;
		while (str[i] != '\0')
		{
			str[i] = f(str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
