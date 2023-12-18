/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:51:39 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 19:11:16 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*display_img_ptr(t_mlx_data *data, void *img, int width, int height)
{
	img = mlx_new_image(data->mlx_ptr, width, height);
	if (data->img.img_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		clean_map(*data, data->size_y);
		exit(1);
	}
	return (img);
}

void	display_web_x(t_mlx_data *data, int x, int y)
{
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
}

void	display_web_y(t_mlx_data *data, int x, int y)
{
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
}
