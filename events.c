/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:57:43 by laroges           #+#    #+#             */
/*   Updated: 2023/10/30 15:01:39 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	events_key(int key, t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	events_key_altitude(key, data);
	events_key_move(key, data);
	events_key_zoom(key, data);
	events_key_others(key, data);
	data->img.img_ptr = display_img_ptr(data, data->img.img_ptr, data->img.width, data->img.height);
	draw_web(data);
	menu(data);
	data->alt = 0;
	return (0);
}

int	events_key_others(int key, t_mlx_data *data)
{
	if (key == XK_b)
	{
		if (data->boost == 0)
			data->boost = 10;
		else
			data->boost = 0;
	}
	else if (key == XK_m)
		data->menu = values_reverse_bool(data->menu);
	else if (key == XK_i)
		data->iso = values_reverse_bool(data->iso);
	else if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		clean_map(*data, data->size_y);
		exit(0);
	}
	return (0);
}

int	events_key_zoom(int key, t_mlx_data *data)
{
	if (key == XK_F5)
		data->zoom += (2 + data->boost);
	else if (key == XK_F6)
		data->zoom += (-2 - data->boost);
	else if (key == XK_F7)
		data->zoom += (10 + data->boost);
	else if (key == XK_F8)
		data->zoom += (-10 - data->boost);
	return (0);
}

int	events_key_move(int key, t_mlx_data *data)
{
	if (key == XK_Down)
		data->up += (-1 - data->boost);
	else if (key == XK_Up)
		data->up += (1 + data->boost);
	else if (key == XK_Right)
		data->right += (1 + data->boost);
	else if (key == XK_Left)
		data->right += (-1 - data->boost);
	else if (key == XK_F1)
		data->upkp += (5 + data->boost);
	else if (key == XK_F2)
		data->upkp += (-5 - data->boost);
	else if (key == XK_F3)
		data->rightkp += (5 + data->boost);
	else if (key == XK_F4)
		data->rightkp += (-5 - data->boost);
	return (0);
}

int	events_key_altitude(int key, t_mlx_data *data)
{
	if (key == XK_u)
	{
		data->alt = 20;
		data->alt_top += data->alt;
		if (data->alt_top == 0)
			data->alt_top += data->alt; // Probleme pour la map plat.fdf
	}	
	else if (key == XK_d)
	{
		data->alt = -20;
		data->alt_top -= data->alt;
		if (data->alt_top == 0)
			data->alt_top -= data->alt; // Probleme pour la map plat.fdf
	}
	else if (key == XK_F12)
	{
		map_reset_map(data);
		data->alt_top = data->alt_top_reset;
	}
	return (0);
}
