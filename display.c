/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:51:39 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 19:11:16 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_fdf_file(t_map *map)
{
	if (map == NULL)
		return ;
	map->y = 0;
	map->x = 0;
	while (map->y++ < map->size_y)
	{
		while (map->x++ < map->size_x)
		{
			printf("[%d]", map->tab_map[map->y][map->x]);
		}
		map->x = 0;
		printf("\n");
	}
}

void	display_int_array(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->size_y)
	{
		while (i < map->size_x)
		{
			printf("%3d", map->tab_map[j][i]);
			ft_putchar(' ');
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

void	display_map(t_map *map)
{
	printf("map->scale = %f\n", map->scale);
	printf("map->size_x = %d\n", map->size_x);
	printf("map->size_y = %d\n", map->size_y);
	printf("map->x = %d\n", map->x);
	printf("map->x = %d\n", map->x);
	printf("map->position_x = %d\n", map->position_x);
	printf("map->position_y = %d\n", map->position_y);
	printf("map->rotation = %f\n", map->rotation);
	display_int_array(map);
}
