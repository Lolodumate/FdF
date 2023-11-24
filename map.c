/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:23:26 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 20:47:16 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_init(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->scale = 5;
	map->size_x = 0;
	map->size_y = 0;
	map->x = 0;
	map->y = 0;
	map->position_x = 500;
	map->position_y = 200;
	map->greatest_z = 0;
	map->rotation = 0;
	map->tab_map = NULL;
	map->zoom = 3;
	return (map);
}

t_map	*map_scale(t_map *map)
{
	map->scale = (1000 / map->size_y) / 2;
//	map->position_x = 1800 / map->scale * (map->size_x * 2 / 3);
//	map->position_y = 1000 / map->scale * map->size_y;
	return (map);
}
