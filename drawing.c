/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:19:00 by laroges           #+#    #+#             */
/*   Updated: 2023/12/20 06:04:23 by laroges          ###   ########.fr       */
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
	void	*img;

	img = data->img.img_ptr;
	values_update_alt(data, data->alt);
	x = 0;
	y = -1;
	display_web_x(data, x, y);
	y = 0;
	x = -1;
	display_web_y(data, x, y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 0, 0);
}
