/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:51:09 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 22:38:29 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*line_init(t_line *line)
{
	line = malloc(sizeof(t_line));
	if (line == NULL)
		return (NULL);
	line->x1 = 0;
	line->y1 = 0;
	line->x2 = 0;
	line->y2 = 0;
	line->dx = 0;
	line->dy = 0;
	line->a = 0;
	line->b = 0;
	return (line);
}

t_line	*line_set_web_y(t_line *web, t_map *map)
{
/*	web->x1 = map->scale;
	web->y1 = (map->size_y * map->scale);
	web->x2 = (map->size_x * map->scale);
	web->y2 = (map->size_y * map->scale);
*/
	web->x1 = map->position_x;
	web->y1 = map->position_y/* + (map->size_y * map->scale)*/;
	web->x2 = map->position_x + map->scale;
	web->y2 = map->position_y/* + (map->size_y * map->scale)*/;
	return (web);
}

t_line	*line_set_web_x(t_line *web, t_map *map)
{
/*	web->x1 = map->scale;
	web->y1 = (map->size_y * map->scale);
	web->x2 = map->scale;
	web->y2 = 0;
*/
	web->x1 = map->position_x;
	web->y1 = map->position_y/* + (map->size_y * map->scale)*/;
	web->x2 = map->position_x;
	web->y2 = web->y1 - map->scale;
	return (web);
}

void	line_draw_map_tab_int_y(t_mlx_data data, t_line *line, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	line_set_web_y(line, map);
	while (j < map->size_y)
	{
		while (i < map->size_x)
		{
//			map->tab_map[j][i]
			line->x2 = line->x1 + map->scale;
			drawing_line(data, line);
			line->x1 = line->x2;
			i++;
		}
		line->x1 = map->position_x;
		line->y1 -= map->scale;
		line->y2 -= map->scale;
		i = 0;
		j++;
	}
}

void	line_draw_map_tab_int_x(t_mlx_data data, t_line *line, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	line_set_web_x(line, map);
	while (j < map->size_x)
	{
		while (i < map->size_y)
		{
//			map->tab_map[j][x]
			printf("Check\n");
			line->y2 = line->y1 - map->scale;
			drawing_line(data, line);
			line->y1 = line->y2;
			i++;
		}
		line->y1 = map->position_y;
		line->x1 += map->scale;
		line->x2 += map->scale;
		i = 0;
		j++;
	}
}
