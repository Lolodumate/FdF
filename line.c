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
	while (data->data->tab_map[j])
	{
		while (data->data->tab_map[j][i])
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

	node = data->next;
	free(line);
	return (node);
}
*/

void	line_init(t_mlx_data *data)
{
//	data->xi = 1;
//	data->yi = 1;
//	data->tmpx = 0;
//	data->tmpy = 0;
	data->x1 = 0;
	data->y1 = 0;
	data->x2 = 0;
	data->y2 = 0;
	data->up = 0;
//	data->dx = 0;
//	data->dy = 0;
//	data->a = 0;
//	data->b = 0;
//	data->ex = 0;
//	data->ey = 0;
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
/*
t_line	*line_set_web_y(t_line *web, t_map *map)
{
	web->x1 = data->position_x;
	web->y1 = data->position_y;
	web->x2 = data->position_x + data->scale;
	web->y2 = data->position_y;
	return (web);
}

t_line	*line_set_web_x(t_line *web, t_map *map)
{
	web->x1 = data->position_x;
	web->y1 = data->position_y;
	web->x2 = data->position_x;
	web->y2 = web->y1 - data->scale;
	return (web);
}

void	line_draw_map_tab_int_y(t_mlx_data data, t_line *line, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	line_set_web_y(line, map);
	while (j < data->size_y)
	{
		while (i < data->size_x - 1)
		{
			data->x2 = data->x1 + data->scale;
			drawing_line(data, line);
			data->x1 = data->x2;
			i++;
		}
		data->x1 = data->position_x;
		data->y1 -= data->scale;
		data->y2 -= data->scale;
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
	while (j < data->size_x)
	{
		while (i < data->size_y - 1)
		{
			data->y2 = data->y1 - data->scale;
			drawing_line(data, line);
			data->y1 = data->y2;
			i++;
		}
		data->y1 = data->position_y;
		data->x1 += data->scale;
		data->x2 += data->scale;
		i = 0;
		j++;
	}
}*/
