/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:51:09 by laroges           #+#    #+#             */
/*   Updated: 2023/12/13 18:33:33 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_init(t_mlx_data *data, t_img *img)
{
	data->x1 = 0;
	data->y1 = 0;
	data->x2 = 0;
	data->y2 = 0;
	data->up = 0;
	img->width = 1800;
	img->height = 1000;
	img->line_len = 1800;
	img->bpp = 32;
	img->addr = NULL;
	img->endian = 0;
}

int	line_setx(t_mlx_data *data, int x, int y)
{
	data->x1 = x * data->zoom;
	data->y1 = y * data->zoom;
	if (data->iso)
		iso_view(data, &data->x1, &data->y1, data->tab_map[y][x]);
	x++;
	if (x < data->size_x)
	{
		data->x2 = x * data->zoom;
		data->y2 = y * data->zoom;
	if (data->iso)
		iso_view(data, &data->x2, &data->y2, data->tab_map[y][x]);
	}
	return (x);
}

int	line_sety(t_mlx_data *data, int x, int y)
{
	data->x1 = x * data->zoom;
	data->y1 = y * data->zoom;
	if (data->iso)
		iso_view(data, &data->x1, &data->y1, data->tab_map[y][x]);
	y++;
	if (y < data->size_y)
	{
		data->x2 = x * data->zoom;
		data->y2 = y * data->zoom;
		if (data->iso)
			iso_view(data, &data->x2, &data->y2, data->tab_map[y][x]);
	}
	return (y);
}

int	line_bool(int x, int y, int width, int height)
{
	if (x >= 0 && x <= width)
		if (y >= 0 && y <= height)
			return (1);
	return (0);
}

int	line_in_the_screen(t_mlx_data *data)
{
	int		w;
	int		h;

	w = data->img.width;
	h = data->img.height;
	if (line_bool(data->x1, data->y1, w, h)
		|| line_bool(data->x2, data->y2, w, h))
			return (1);
	return (0);
}

void	line_update_alt(t_mlx_data *data, int up)
{
	int		x;
	int		y;
	int		a;

	x = -1;
	y = -1;
	a = 0;
	while (y++ < data->size_y)
	{
		while (x++ < data->size_x)
		{
			a = data->tab_map[y][x];
			if (a != 0 && a > (INT_MIN + 1) && a < (INT_MAX - 1))
			{
				data->tab_map[y][x] += up;
				if (data->tab_map[y][x] == 0)
					data->tab_map[y][x] += up;
			}
		}
		x = -1;
	}
}
