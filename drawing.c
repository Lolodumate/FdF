/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:19:00 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 19:38:11 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_data	*drawing_init_data(t_mlx_data *data, double x, double y)
{
	data->xi = 1;
	data->yi = 1;
	data->ex = abs(data->x2 - data->x1);
	data->ey = abs(data->y2 - data->y1);
	data->tmpx = data->ex;
	data->tmpy = data->ey;
	data->dx = 2 * data->ex;
	data->dy = 2 * data->ey;
	if (x > data->x2)
		data->xi = -1;
	if (y > data->y2)
		data->yi = -1;
	return (data);
}

void	drawing_line_x(t_mlx_data *data, int z)
{
	int			i;
	double		x;
	double		y;

	i = 0;
	x = data->x1;
	y = data->y1;
	drawing_init_data(data, x, y);
	if (data->tmpx >= data->tmpy)
	{
		while (i <= data->tmpx)
		{
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, x, y, z);
			x += data->xi;
			data->ex -= data->dy;
			if (data->ex < 0)
			{
				y += data->yi;
				data->ex += data->dx;
			}
			i++;
		}
	}
}

void	drawing_line_y(t_mlx_data *data, int z)
{
	int			i;
	double		x;
	double		y;

	i = 0;
	x = data->x1;
	y = data->y1;
	drawing_init_data(data, x, y);
	if (data->tmpx < data->tmpy)
	{
		while (i <= data->tmpy)
		{
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, x, y, z);
			y += data->yi;
			data->ey -= data->dx;
			if (data->ey < 0)
			{
				x += data->xi;
				data->ey += data->dy;
			}
			i++;
		}
	}
}

t_mlx_data	*drawing_get_color(t_mlx_data *data, int z1, int z2)
{
	if (z1 == 0 && z2 == 0)
		data->color = 0xffffff;
	else if (z1 < 0 || z2 < 0)
		data->color = 0x00aaaa;
	else if (z1 > 8 || z2 > 8)
		data->color = 0xff0000;
	else if (z1 > 15 || z2 > 15)
		data->color = 0xff1000;
	else if (z1 > 14 || z2 > 14)
		data->color = 0xff2000;
	else if (z1 > 13 || z2 > 13)
		data->color = 0xff3000;
	else if (z1 > 12 || z2 > 12)
		data->color = 0xff4000;
	else if (z1 > 11 || z2 > 11)
		data->color = 0xff5000;
	else if (z1 > 10 || z2 > 10)
		data->color = 0xff6000;
	else if (z1 > 9 || z2 > 9)
		data->color = 0xff7000;
	else if (z1 > 8 || z2 > 8)
		data->color = 0xff8000;
	else if (z1 > 7 || z2 > 7)
		data->color = 0xff9000;
	else if (z1 > 6 || z2 > 6)
		data->color = 0xff0f00;
	else if (z1 > 5 || z2 > 5)
		data->color = 0xff1f00;
	else if (z1 > 4 || z2 > 4)
		data->color = 0xff2f00;
	else if (z1 > 3 || z2 > 3)
		data->color = 0xff3f00;
	else if (z1 > 2 || z2 > 2)
		data->color = 0xff4f00;
	else if (z1 > 1 || z2 > 1)
		data->color = 0xff5f00;
	return (data);
}

void	drawing_web(t_mlx_data *data)
{
	int		x;
	int		y;

	y = -1;
	printf("data->altitude = %d\n", data->altitude);
	while (++y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (data->tab_map[y][x] != 0)
			{
				data->tab_map[y][x] += data->altitude;
				if (data->tab_map[y][x] == 0 && data->altitude > 0)
					data->tab_map[y][x] = -1;
				if (data->tab_map[y][x] == 0 && data->altitude < 0)
					data->tab_map[y][x] = 1;
			}
			drawing_get_color(data, data->tab_map[y][x], data->tab_map[y][x + 1]);
			x = line_setx(data, x, y);
			drawing_line_x(data, data->color);
			drawing_line_y(data, data->color);
		}
	}
	x = -1;
	while (++x < data->size_x)
	{
		y = 0;
		while (y < data->size_y)
		{
			drawing_get_color(data, data->tab_map[y][x], data->tab_map[y + 1][x]);
			y = line_sety(data, x, y);
			drawing_line_x(data, data->color);
			drawing_line_y(data, data->color);
		}
	}
}
