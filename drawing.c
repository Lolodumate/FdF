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
	data->ex = values_abs(data->x2 - data->x1);
	data->ey = values_abs(data->y2 - data->y1);
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

void	put_pixel(t_mlx_data *data, int x, int y, unsigned int color)
{
	char	*pixel;
	
	if (y >= data->img.height || x >= data->img.width || y < 0 || x < 0)
	{
		//printf("Erreur put_pixel\n");
		return ;
	}
	pixel = data->img.address + (y * data->img.line_len) + (x * data->img.bpp / 8);
	*(unsigned int *)pixel = color;
}

void	drawing_line_x(t_mlx_data *data, unsigned int z)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = data->x1;
	y = data->y1;
	drawing_init_data(data, x, y);
	if (data->tmpx >= data->tmpy)
	{
		while (i < data->tmpx)
		{
			put_pixel(data, x, y, z);
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

void	drawing_line_y(t_mlx_data *data, unsigned int z)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = data->x1;
	y = data->y1;
	drawing_init_data(data, x, y);
	if (data->tmpx <= data->tmpy)
	{
		while (i < data->tmpy)
		{
			put_pixel(data, x, y, z);
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

t_mlx_data	*drawing_get_color(t_mlx_data *data, unsigned int z1, unsigned int z2)
{
	int		m;

	m = 0;
	if (z1 + z2 != 0)
		m = (z1 + z2) / 2;
	if (m == 0)
		data->color = WHITE;
	else if (m < 0)
		data->color = BLUE;
	else if (m > 0)
		data->color = RED;
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
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->img.img_ptr, 0, 0);
}
