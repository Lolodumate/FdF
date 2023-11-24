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
/*
t_line	*line_fdfdata(t_mlx_data data, t_line *points, int p_data[4][2])
{
	points.p1->x = p_data[0][0];
	points.p1->y = p_data[0][1];
	points.p2_p1right->x = p_data[1][0];
	points.p2_p1right->y = p_data[1][1];
	points.p3_p1bottom->x = p_data[2][0];
	points.p3_p1bottom->y = p_data[2][1];
	points.p4->x = p_data[3][0];
	points.p4->y = p_data[3][1];
	drawing_square(data, points);
	return (line);
}

t_line	*line_fdfdata_2(t_line *data, float x2, float y2)
{
	data->x2 = x2;
	data->y2 = y2;
	return (data);
}

t_line	*line_insert_node(t_line *line, t_map *map, char eol)
{
	t_line	*node;

	node = malloc(sizeof(t_line));
	if (node == NULL)
		return (NULL);
	node->p1 = NULL;
	node->p2_p1right = NULL;
	node->p3_p1bottom = NULL;
	node->dx = 0;
	node->dy = 0;
	node->a = 0;
	node->b = 0;
	node->map = map;
	node->end_of_line = eol;
	node->next = line;
	return (node);
}

t_line	*line_fill_data(t_line *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line->map->tab_map[j])
	{
		while (line->map->tab_map[j][i])
		{
			
		}
		i = 0;
		j++;
	}	
	return (line);
}

t_line	*line_clean_node(t_line *line)
{
	t_line	*node;

	node = line->next;
	free(line);
	return (node);
}
*/

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

int	line_setx(t_line *line, t_map *map, int x, int y)
{
	line->x1 = x * map->zoom;
	line->y1 = y * map->zoom;
	iso_view(&line->x1, &line->y1, map->tab_map[y][x], line->shift);
	x++;
	if (x < map->size_x)
	{
		line->x2 = x * map->zoom;
		line->y2 = y * map->zoom;
		iso_view(&line->x2, &line->y2, map->tab_map[y][x], line->shift);
	}
	return (x);
}

int	line_sety(t_line *line, t_map *map, int x, int y)
{
	line->x1 = x * map->zoom;
	line->y1 = y * map->zoom;
	iso_view(&line->x1, &line->y1, map->tab_map[y][x], line->shift);
	y++;
	if (y < map->size_y)
	{
		line->x2 = x * map->zoom;
		line->y2 = y * map->zoom;
		iso_view(&line->x2, &line->y2, map->tab_map[y][x], line->shift);
	}
	return (y);
}
/*
t_line	*line_set_web_y(t_line *web, t_map *map)
{
	web->x1 = map->position_x;
	web->y1 = map->position_y;
	web->x2 = map->position_x + map->scale;
	web->y2 = map->position_y;
	return (web);
}

t_line	*line_set_web_x(t_line *web, t_map *map)
{
	web->x1 = map->position_x;
	web->y1 = map->position_y;
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
		while (i < map->size_x - 1)
		{
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
		while (i < map->size_y - 1)
		{
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
}*/
