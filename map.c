/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:23:26 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 20:47:16 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_init(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->scale = 50;
	map->size_x = 0;
	map->size_y = 0;
	map->x = 0;
	map->y = 0;
	map->position_x = 200;
	map->position_y = 50;
	map->rotation = 0;
	map->tab_map = NULL;
	return (map);
}
/*
t_map	*map_init_matrix(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	map->matrix = malloc(sizeof(int **) * map->size_y); // Pour les lignes
	if (map->matrix == NULL)
		return (NULL);
	while (y < map->size_y) // Allocation memoire du nombre de colonnes necessaire pour chaque ligne
	{
		map->matrix[y] = malloc(sizeof(int *) * map->size_x);
		if (map->matrix[y] == NULL)
			return (NULL);
		while (x < map->size_x) // Pour les valeurs x, y et value du fichier fdf
		{
			map->matrix[y][x] = malloc(sizeof(int) * 3);
			if (map->matrix[y][x] == NULL)
				return (NULL);
			x++;
		}
		x = 0;
		y++;
	}
	printf("\n\n>>>>>>>>>>>>>>>>>  Creation Matrix OK  <<<<<<<<<<<<<<<<<<<<<\n\n");
	return (map);
}
*/

t_map   *map_init_matrix(t_map *map)
{
        int             y;

        y = 0;
        map->matrix = malloc(sizeof(t_data_matrix **) * map->size_y); // Pour les lignes
        if (map->matrix == NULL)
                return (NULL);
        while (y < map->size_y) // Allocation memoire du nombre de colonnes necessaire pour chaque ligne
        {
                map->matrix[y] = malloc(sizeof(t_data_matrix *) * map->size_x);
                if (map->matrix[y] == NULL)
                        return (NULL);
             y++;
        }
        printf("\n\n>>>>>>>>>>>>>>>>>  Creation Matrix OK  <<<<<<<<<<<<<<<<<<<<<\n\n");
        return (map);
}
/*
t_map	*map_data_matrix(t_map *map, int x, int y, int *tab)
{
	map->matrix[y][x][0] = tab[0];
	map->matrix[y][x][1] = tab[1];
	map->matrix[y][x][2] = tab[2];
	return (map);
}
*/
t_map	*map_fill_matrix(t_map *map, t_line *line)
{
	int		x;
	int		y;
	int		tmpx;
	int		tmpy;
//	int		tab[3];
	t_data_matrix	*matrix;

	x = 0;
	y = 0;
	tmpx = 0;
	tmpy = 0;
	map->rotation = iso_rotation(map->scale);
	printf("Valeur de map->rotation = %f\n", map->rotation);
	line->x1 = map->position_x;
	line->y1 = map->position_y;
	while (y < map->size_y)
	{
		tmpx = line->x1;
		tmpy = line->y1;
		while (x < map->size_x)
		{
			matrix = malloc(sizeof(t_data_matrix));
			if (matrix == NULL)
			{
				printf("Erreur allocation dynamique\n");
				return (NULL);
			}
			else
				printf("Allocation dynamique matrix OK\n");
			matrix->y = line->y1 + map->rotation;
			matrix->x = line->x1 + map->rotation;
			matrix->z = map->tab_map[y][x] * (1 + map->scale / 100);
			map->matrix[y][x] = matrix;
			line->y2 = line->y1 + map->rotation;
			line->x2 = line->x1 + map->rotation;
//			printf("#%2d - x1 = %3f y1 = %3f - x2 = %3f y2 = %3f\n", x, line->x1, line->y1, line->x2, line->y2);
//			printf("x[%d]y[%d]:", x, y);
			line->y1 = line->y2;
			line->x1 = line->x2;
			x++;
		}
	//	printf("#%d - x1 = %f y1 = %f - x2 = %f y2 = %f\n", x, line->x1, line->y1, line->x2, line->y2);
//		printf("\n-----------------------------------------------------------------------------\n");
		line->x1 = tmpx - map->scale + map->rotation;
		line->y1 = tmpy + map->rotation;
		x = 0;
		y++;
	}
//	display_matrix(map);
//	printf("********************map->size_y = %d \n", map->size_y);
	return (map);
}

/*
void	display_matrix(t_map *map)
{
	int		x;
	int		y;
	int		*data;

	x = 0;
	y = 0;
	while (y < map->size_y)
	{
		while (x < map->size_x)
		{
			data = malloc(sizeof(int) * 3);
			if (data == NULL)
				return ;
			data = map->matrix[y][x];
			printf("[%d][%d][%d] ", data[0], data[1], data[2]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}*/
