/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akikalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:54:04 by akikalia          #+#    #+#             */
/*   Updated: 2019/05/12 17:54:05 by akikalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "libft.h"

typedef struct		s_map
{
	int				alloc_size;
	int				size;
	char			**values;
	char			**keys;
}					t_map;

t_map				*map_init();
void				arrtomap(t_map *mp, char **arr);
void				map_free(t_map *mp);
void				map_add(t_map *mp, char *key, char *value);
char				*map_get(t_map *mp, char *key);
char				**maptoarr(t_map *mp);
void				map_remove(t_map *mp, char *key);

#endif
