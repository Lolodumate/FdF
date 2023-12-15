/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:19:00 by laroges           #+#    #+#             */
/*   Updated: 2023/12/13 18:40:00 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_data	*draw_init_data(t_mlx_data *data, int x, int y)
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
	char	*pxl;

	if (y >= data->img.height || x >= data->img.width || y < 0 || x < 0)
		return ;
	pxl = data->img.addr + (y * data->img.line_len) + (x * data->img.bpp / 8);
	*(unsigned int *)pxl = color;
}

void	draw_line_x(t_mlx_data *data, int z)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = data->x1;
	y = data->y1;
	draw_init_data(data, x, y);
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

void	draw_line_y(t_mlx_data *data, int z)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = data->x1;
	y = data->y1;
	draw_init_data(data, x, y);
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

void	draw_web(t_mlx_data *data)
{
	int		x;
	int		y;

	y = -1;
	line_update_alt(data, data->alt);
	while (++y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			colors_get(data, data->tab_map[y][x], data->tab_map[y][x + 1]);
			x = line_setx(data, x, y);
			if (line_in_the_screen(data))
			{
				draw_line_x(data, data->color);
				draw_line_y(data, data->color);
			}
		}
	}
	x = -1;
	while (++x < data->size_x)
	{
		y = 0;
		while (y < data->size_y)
		{
			colors_get(data, data->tab_map[y][x], data->tab_map[y + 1][x]);
			y = line_sety(data, x, y);
			if (line_in_the_screen(data))
			{
				draw_line_x(data, data->color);
				draw_line_y(data, data->color);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}
