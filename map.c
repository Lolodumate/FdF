/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:23:26 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 20:14:32 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_data	map_init(t_mlx_data data, char **argv)
{
	data.size_x = 0;
	data.size_y = 0;
	data.x = 0;
	data.y = 0;
	data.position_x = 500;
	data.position_y = 200;
	data.altitude = 0;
	data.rotation = 0;
	data.altitude_reset = NULL;
	data.map_contain_colors = false;
	data.tab_map = NULL;
	data.tab_colors = NULL;
	data.colorx = NULL;
	data.zoom = 5;
	data.color = 0xffffff;
	data.up = 0;
	data.upkp = 0;
	data.right = 0;
	data.rightkp = 0;
	data.shiftx = 800;
	data.shifty = -300;
	data.map_name = argv[1];
	data.mouse = 0;
	return (data);
}

void	map_resize_init(t_mlx_data *data)
{
	int		n;

	n = data->size_x;
	if (data->size_y >data->size_x)
		n = data->size_y;
	data->zoom = (1000 / n);
}
