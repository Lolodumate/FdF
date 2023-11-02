/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:23:26 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 22:35:49 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_init(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		printf("Erreur allocation dynamique\n");
		return (NULL);
	}
	map->scale = 20;
	map->size_x = 0;
	map->size_y = 0;
	map->x = 0;
	map->y = 0;
	map->position_x = 300;
	map->position_y = 300;
	map->rotation = 0;
	map->tab_map[1000] = NULL;
	return (map);
}
