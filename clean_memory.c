/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:57 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 17:22:27 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_memory(t_mlx_data *data, t_line *line, t_map *map)
{
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->window_ptr);
	free(line);
	clean_tab_int_map(map);
	clean_map_matrix(map);
	free(map);
}

void	clean_tab_int_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->tab_map[i]);
		i++;
	}
	free(map->tab_map[1000]);
}

void	clean_map_matrix(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map->size_y)
	{
		while (x < map->size_x)
		{
			free(map->matrix[y][x]);
			printf("free(map->matrix[%d][%d] OK\n", y, x);
			x++;
		}
		free(map->matrix[y]);
		printf("free(map->matrix[%d] OK\n", y);
		x = 0;
		y++;
	}
	free(map->matrix);
}
