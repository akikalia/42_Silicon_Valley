/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:40:52 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/08 21:06:01 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int				i;
	int				n;
	int				wasc;

	n = 0;
	wasc = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			wasc = 1;
		if (wasc == 1 && s[i] != c)
		{
			wasc = 0;
			n++;
		}
		i++;
	}
	return (n);
}

static char	**split(char const *s, char c, char ***res)
{
	int				i;
	int				wasc;
	int				k;
	int				n;

	wasc = 1;
	i = 0;
	k = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			wasc = 1;
		if (wasc == 1 && s[i] != c)
		{
			n = 0;
			wasc = 0;
			while (s[i + n] != '\0' && s[i + n] != c)
				n++;
			(*res)[k++] = ft_strsub(s, i, n);
			i = i + n - 1;
		}
		i++;
	}
	return (*res);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = count_words(s, c);
	if ((res = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return (NULL);
	res[i] = NULL;
	return (split(s, c, &res));
}
