/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:57 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 19:59:04 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_memory(t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	free(data->mlx_ptr);
	free(data->window_ptr);
}

void	clean_map_line(t_line *line, t_map *map, int size_y)
{
	free(line);
	clean_tab_int_map(map, size_y);
	clean_map_matrix(map, size_y);
	free(map);
}

void	clean_tab_int_map(t_map *map, int size_y)
{
	int		y;

	y = 0;
	printf("map->size_x = %d \n", map->size_x);
	printf("size_y = %d \n", size_y);
	display_int_array(map);
	while (y < size_y)
	{
		free(map->tab_map[y]);
		y++;
	}
	free(map->tab_map);
}

void	clean_map_matrix(t_map *map, int size_y)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < size_y)
	{
		while (map->size_x && x < map->size_x)
		{
			free(map->matrix[y][x]);
			x++;
		}
		free(map->matrix[y]);
		x = 0;
		y++;
	}
	free(map->matrix);
}
