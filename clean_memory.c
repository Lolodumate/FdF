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
/*
void	clean_map_line(t_mlx_data *data, int size_y)
{
	clean_tab_int_map(data, size_y);
}
*/


void	clean_tab_int_map(t_mlx_data data, int size_y)
{
	int		y;

	y = 0;
	while (y <= size_y)
	{
		printf("clean_tab_int_map - free(data->tab_map[%d] OK\n", y);
		free(data.tab_map[y]);
		y++;
	}
	free(data.tab_map);
}
