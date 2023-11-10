/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:19:00 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 19:46:20 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
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
*/
// Equation of a line : y = ax + b
void	drawing_line(t_mlx_data data, t_line *line)
{
	float	x;
	float	y;

	x = line->x1;
	y = line->y1;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
	line->a = line->dy / line->dx;
	line->b = line->y1 - (line->a * line->x1);
	if (x < line->x2)
	{
		while (x <= line->x2)
		{
			y = (line->a * x) + line->b;	
			mlx_pixel_put(data.mlx_ptr, data.window_ptr, x, y, 0xffffff);
			x++;
		}
	}
	else if (x > line->x2)
	{
		while (x >= line->x2)
		{
			y = (line->a * x) + line->b;
			mlx_pixel_put(data.mlx_ptr, data.window_ptr, x, y, 0xffffff);
			x--;
		}
	}
	else if (x == line->x2)
	{
		while (y >= line->y2)
		{
			mlx_pixel_put(data.mlx_ptr, data.window_ptr, x, y, 0xffffff);
			y--;
		}	
	}
}

void	drawing_web(t_mlx_data data, t_map *map, t_line *line)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map->size_y)
	{
//		printf("map->size_x = %d \n", map->size_x);
//		printf("map->size_y = %d \n", map->size_y);
		while (x < map->size_x)
		{
/*			printf("Valeur de map->matrix[y%d][x%d] = %d\n", y, 0, map->matrix[y][x][0]);
			printf("Valeur de map->matrix[y%d][x%d] = %d\n", y, 1, map->matrix[y][x][1]);
			printf("Valeur de map->matrix[y%d][x%d] = %d\n", y, 2, map->matrix[y][x][2]);
*/			line->x1 = map->matrix[y][x][0];
			line->y1 = map->matrix[y][x][1] - map->matrix[y][x][2];
			x++;
			if (x < map->size_x)
			{
				printf("x[%d]y[%d] ", x, y);
				line->x2 = map->matrix[y][x][0];
				line->y2 = map->matrix[y][x][1] - map->matrix[y][x][2];
				drawing_line(data, line);
			}
			printf("\n");
		}
		x = 0;
		y++;
	}
	x = 0;
	y = 0;
	while (x < map->size_x)
	{
//		printf("map->size_x = %d \n", map->size_x);
//		printf("map->size_y = %d \n", map->size_y);
		while (y < map->size_y)
		{
/*			printf("Valeur de map->matrix[y%d][x%d] = %d\n", y, 0, map->matrix[y][x][0]);
			printf("Valeur de map->matrix[y%d][x%d] = %d\n", y, 1, map->matrix[y][x][1]);
			printf("Valeur de map->matrix[y%d][x%d] = %d\n", y, 2, map->matrix[y][x][2]);
*/			line->x1 = map->matrix[y][x][0];
			line->y1 = map->matrix[y][x][1] - map->matrix[y][x][2];
			y++;
			if (y < map->size_y)
			{
				printf("x[%d]y[%d] ", x, y);
				line->x2 = map->matrix[y][x][0];
				line->y2 = map->matrix[y][x][1] - map->matrix[y][x][2];
				drawing_line(data, line);
			}
			printf("\n");
		}
		y = 0;
		x++;
	}
}


/*
void	drawing_square(t_mlx_data data, t_line *points)
{
	int		x1;
	int			
}
*/

/* La variable rotation (dans t_map) permet d'incliner la carte.
 * Par convention un inclinaison de 30 degres implique une reduction de la taille des segments auxquels il faut appliquer un coefficient de 0.82.
 * Par ailleurs, une inclinaison de 30 degres d'un carre ou rectangle implique que, du fait de la perspective isometrique, l'angle rectangle s'elargisse a 120 degres. Nous avons donc trois angles de 30, 120 et 30 degres.
 * */

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
