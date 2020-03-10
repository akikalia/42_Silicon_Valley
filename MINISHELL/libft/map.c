/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:56:24 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 18:01:09 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map		*map_init(void)
{
	t_map *mp;

	mp = malloc(sizeof(t_map));
	mp->alloc_size = 100;
	mp->size = 0;
	mp->values = malloc(sizeof(char *) * mp->alloc_size);
	mp->keys = malloc(sizeof(char *) * mp->alloc_size);
	return (mp);
}

void		map_free(t_map *mp)
{
	int			i;

	i = 0;
	while (i < mp->size)
	{
		free(mp->values[i]);
		free(mp->keys[i]);
		i++;
	}
	free(mp->values);
	free(mp->keys);
	free(mp);
}

static void	grow(t_map *mp)
{
	int			i;
	char		**keys;
	char		**values;

	mp->alloc_size *= 2;
	values = malloc(sizeof(char *) * mp->alloc_size);
	keys = malloc(sizeof(char *) * mp->alloc_size);
	i = 0;
	while (i < mp->size)
	{
		values[i] = mp->values[i];
		keys[i] = mp->keys[i];
		i++;
	}
	free(mp->values);
	free(mp->keys);
	mp->values = values;
	mp->keys = keys;
}

void		map_add(t_map *mp, char *key, char *value)
{
	int			i;

	i = 0;
	while (i < mp->size && ft_strcmp(mp->keys[i], key))
		i++;
	if (i != mp->size)
	{
		free(mp->values[i]);
		mp->values[i] = value;
		free(key);
	}
	else
	{
		if (mp->size == mp->alloc_size)
			grow(mp);
		mp->values[mp->size] = value;
		mp->keys[mp->size] = key;
		mp->size++;
	}
}

void		map_remove(t_map *mp, char *key)
{
	int			i;

	i = 0;
	while (i < mp->size && ft_strcmp(mp->keys[i], key))
		i++;
	if (i != mp->size)
	{
		free(mp->keys[i]);
		free(mp->values[i]);
		mp->keys[i] = ft_strdup("");
		mp->values[i] = ft_strdup("");
	}
}
