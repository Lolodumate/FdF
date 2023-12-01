/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:51:09 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 18:54:56 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_init(t_mlx_data *data)
{
	data->x1 = 0;
	data->y1 = 0;
	data->x2 = 0;
	data->y2 = 0;
	data->up = 0;
}

int	line_setx(t_mlx_data *data, int x, int y)
{
	data->x1 = x * data->zoom;
	data->y1 = y * data->zoom;
	iso_view(data, &data->x1, &data->y1, data->tab_map[y][x]);
	x++;
	if (x < data->size_x)
	{
		data->x2 = x * data->zoom;
		data->y2 = y * data->zoom;
		iso_view(data, &data->x2, &data->y2, data->tab_map[y][x]);
	}
	return (x);
}

int	line_sety(t_mlx_data *data, int x, int y)
{
	data->x1 = x * data->zoom;
	data->y1 = y * data->zoom;
	iso_view(data, &data->x1, &data->y1, data->tab_map[y][x]);
	y++;
	if (y < data->size_y)
	{
		data->x2 = x * data->zoom;
		data->y2 = y * data->zoom;
		iso_view(data, &data->x2, &data->y2, data->tab_map[y][x]);
	}
	return (y);
}
