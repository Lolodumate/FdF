/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:13 by laroges           #+#    #+#             */
/*   Updated: 2023/12/20 06:06:00 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_move(t_mlx_data *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	if (data->menu == false)
		mlx_string_put(mlx, win, 10, 980, WHITE, "Menu - Press m");
	if (data->menu)
	{
		mlx_string_put(mlx, win, 50, 80, WHITE, data->map_name);
		mlx_string_put(mlx, win, 50, 120, WHITE, "Interactions :");
		mlx_string_put(mlx, win, 50, 140, WHITE, "- Descendre : F1");
		mlx_string_put(mlx, win, 50, 160, WHITE, "- Monter : F2");
		mlx_string_put(mlx, win, 50, 180, WHITE, "- Droite : F3");
		mlx_string_put(mlx, win, 50, 200, WHITE, "- Gauche : F4");
	}
}

void	menu_change(t_mlx_data *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	if (data->menu)
	{
		mlx_string_put(mlx, win, 50, 220, WHITE, "- Altitude : u/d");
		mlx_string_put(mlx, win, 50, 240, WHITE, "- Reset altitude : F12");
		mlx_string_put(mlx, win, 50, 260, WHITE, "- Zoom x2 : F5/F6");
		mlx_string_put(mlx, win, 50, 280, WHITE, "- Zoom x10 : F7/F8");
		mlx_string_put(mlx, win, 50, 300, WHITE, "- Boost : b");
		mlx_string_put(mlx, win, 50, 320, WHITE, "- Isometry : i");
		mlx_string_put(mlx, win, 50, 340, WHITE, "- Erase menu : m");
		if (data->boost == 0)
			mlx_string_put(mlx, win, 120, 300, RED, "OFF");
		else
			mlx_string_put(mlx, win, 120, 300, GREEN, "ON");
		if (data->iso == 0)
			mlx_string_put(mlx, win, 140, 320, RED, "OFF");
		else
			mlx_string_put(mlx, win, 140, 320, GREEN, "ON");
	}
}

void	menu(t_mlx_data *data)
{
	menu_move(data);
	menu_change(data);
}
