/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:00:15 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 18:00:47 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		arrtomap(t_map *mp, char **arr)
{
	int			i;
	char		*temp;

	i = 0;
	while (arr[i])
	{
		temp = ft_strchr(arr[i], '=');
		*temp = '\0';
		temp++;
		map_add(mp, ft_strdup(arr[i]), ft_strdup(temp));
		i++;
	}
}

char		*map_get(t_map *mp, char *key)
{
	int			i;

	i = 0;
	while (i < mp->size && ft_strcmp(mp->keys[i], key))
		i++;
	if (i != mp->size)
		return (mp->values[i]);
	else
		return (NULL);
}

char		**maptoarr(t_map *mp)
{
	int			i;
	int			m;
	char		**arr;

	arr = malloc(sizeof(char **) * (mp->size + 1));
	m = 0;
	i = 0;
	while (i < mp->size)
	{
		if (mp->keys[i][0] != '\0')
		{
			arr[m] = ft_stradd(ft_strjoin(mp->keys[i], "=")
					, ft_strdup(mp->values[i]));
			m++;
		}
		i++;
	}
	arr[m] = NULL;
	return (arr);
}
