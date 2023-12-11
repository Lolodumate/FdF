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

t_img	map_init(t_mlx_data *data, char **argv, t_img img)
{
	data->size_x = 0;
	data->size_y = 0;
	data->x = 0;
	data->y = 0;
	data->position_x = 500;
	data->position_y = 200;
	data->altitude = 0;
	data->rotation = 0;
	data->altitude_reset = NULL;
	data->map_contain_colors = false;
	data->tab_map = NULL;
	data->tab_colors = NULL;
	data->colorx = NULL;
	data->zoom = 5;
	data->color = 0xffffff;
	data->up = 0;
	data->upkp = 0;
	data->right = 0;
	data->rightkp = 0;
	data->shiftx = 800;
	data->shifty = -300;
	data->map_name = argv[1];
	data->mouse = 0;
	data->img = img;
	return (img);
}

void	map_resize_init(t_mlx_data *data)
{
	int		n;

	n = data->size_x;
	if (data->size_y >data->size_x)
		n = data->size_y;
	data->zoom = (1000 / n);
}

void    map_reset_map(t_mlx_data *data)
{
	int             x;
	int             y;

	x = 0;
	y = 0;
	while (y <= data->size_y)
	{
		while (x < data->size_x)
                {
			data->tab_map[y][x] = data->altitude_reset[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

t_img	map_initialisation(char **argv, t_mlx_data *data, t_img img, t_parsing *list)
{
	line_init(data, &img);
	img = map_init(data, argv, img);
	pm_read_map(data, argv, list);
	map_resize_init(data);
	return (img);
}
