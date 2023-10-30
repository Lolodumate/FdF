/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:19:00 by laroges           #+#    #+#             */
/*   Updated: 2023/10/30 19:18:26 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawing_points(t_mlx_data data, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->size_y)
	{
		while (i < map->size_x)
		{
			mlx_pixel_put(data.mlx_ptr, data.window_ptr, i * map->scale, j * map->scale, 0xffffff);
			i++;
		}
		i = 0;
		j++;
	}
}

// Equation of a line : y = ax + b
void	drawing_line(t_mlx_data data, t_line *line)
{
	float	x;
	float	y;

	x = line->x1;
	y = 0;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
	line->a = line->dy / line->dx;
	line->b = line->y1 - (line->a * line->x1);
	while (x <= line->x2)
	{
		y = (line->a * x) + line->b;	
		mlx_pixel_put(data.mlx_ptr, data.window_ptr, x, y, 0xffffff);
		x++;
	}
}

void	drawing_web(t_mlx_data data, t_map *map, t_line *line)
{
	int		i;

	i = 0;
	while (i < map->size_y)
	{
		drawing_line(data, line);
		line->y1 -= map->scale;
		line->y2 -= map->scale;
		i++;
	}
	i = 0;
	while (i < map->size_x)
	{
		drawing_line(data, line);
		line->x1 += map->scale;
		line->x2 += map->scale;
		i++;
	}
}

t_line	*drawing_init_line(t_map *map)
{
	t_line	*line;

	if (map == NULL)
		return (NULL);
	line = malloc(sizeof(t_line));
	if (line == NULL)
		return (NULL);
	line->x1 = map->scale;
	line->y1 = map->size_y - map->scale;
	line->x2 = line->x1 + map->size_x;
	line->y2 = line->y1 - map->size_y;
	line->dx = 0;
	line->dy = 0;
	line->a = 0;
	line->b = 0;
	return (line);
}
