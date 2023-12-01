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
/*
void	clean_memory(t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->window_ptr);
}
*/

void	clean_map(t_mlx_data data, int size_y)
{
	clean_tab_int_map(data, size_y);
	clean_tab_colors(data, size_y);
}



void	clean_tab_int_map(t_mlx_data data, int size_y)
{
	int		y;

	y = 0;
	while (y <= size_y)
	{
		printf("clean_tab_int_map - free(data->tab_map[%d] OK\n", y);
		free(data.tab_map[y]);
		free(data.altitude_reset[y]);
		y++;
	}
	free(data.tab_map);
	free(data.altitude_reset);
}

void	clean_tab_colors(t_mlx_data data, int size_y)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y <= size_y)
	{
		while (x <= data.size_x)
		{
			printf("clean_tab_colors - free(data.tab_colors[%d][%d] OK\n", y, x);
			free(data.tab_colors[y][x]);
			x++;
		}
		printf("clean_tab_colors - free(data.tab_colors[%d] OK\n", y);
		free(data.tab_colors[y]);
		x = 0;
		y++;
	}
	free(data.tab_colors);
}
