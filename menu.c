/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:13 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 18:07:55 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_move(t_mlx_data *data)
{
	int		c;
	char	fct[50] = "Fonctions interactives :";
	char	md[50] = " - Monter/Descendre : F1/F2";
	char	gd[50] = " - Translation Gauche/Droite : F3/F4";

	c = 0xffffff;
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 80, c, data->map_name);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 120, c, fct);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 140, c, md);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 160, c, gd);
}

void	menu_change(t_mlx_data *data)
{
	int		c;
	char	alt[50] = " - Altitude +/- : u/d";
	char	zoom[50] = " - Zoom +/- : F5/F6";
	char	rs[50] = " - Reset altitude : F12";

	c = 0xffffff;
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 180, c, alt);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 200, c, zoom);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 220, c, rs);
}

void	menu(t_mlx_data *data)
{
	menu_move(data);
	menu_change(data);
}
