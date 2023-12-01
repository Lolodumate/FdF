/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:57 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 18:55:17 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_map(t_mlx_data data, int size_y)
{
	clean_tab_int_map(data, size_y);
	clean_tab_colors(data, size_y);
}

void	clean_tab_int_map(t_mlx_data data, int size_y)
{
	int		y;

	y = 0;
	while (y <= size_y)
	{
		free(data.tab_map[y]);
		free(data.altitude_reset[y]);
		y++;
	}
	free(data.tab_map);
	free(data.altitude_reset);
}

void	clean_tab_colors(t_mlx_data data, int size_y)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y <= size_y)
	{
		while (x <= data.size_x)
		{
			free(data.tab_colors[y][x]);
			x++;
		}
		free(data.tab_colors[y]);
		x = 0;
		y++;
	}
	free(data.tab_colors);
}
