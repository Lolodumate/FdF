/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:51:39 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 22:13:34 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_fdf_file(t_map *map)
{
	if (map == NULL)
		return ;
	map->y = 0;
	map->x = 0;
	while (map->y++ < map->size_y)
	{
		while (map->x++ < map->size_x)
		{
			printf("[%d]", map->tab_map[map->y][map->x]);
		}
		map->x = 0;
		printf("\n");
	}
}

void	display_int_array(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->size_y)
	{
		while (i < map->size_x)
		{
			ft_putnbr_fd(map->tab_map[j][i], 1);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
}

void	display_matrix(t_map *map)
{
	int		x;
	int		y;
	int		value;

	x = 0;
	y = 0;
	value = 0;
	while (y < map->size_y)
	{
		while (x < map->size_x)
		{
			while (value < 3)
			{
				printf("matrix[%d][%d][%d] = %d\n", y, x, value, map->matrix[y][x][value]);
				value++;
			}
			value = 0;
			x++;
		}
		x = 0;
		y++;
	}
}

void	display_map(t_map *map)
{
	printf("map->scale = %f\n", map->scale);
	printf("map->size_x = %d\n", map->size_x);
	printf("map->size_y = %d\n", map->size_y);
	printf("map->x = %d\n", map->x);
	printf("map->x = %d\n", map->x);
	printf("map->position_x = %d\n", map->position_x);
	printf("map->position_y = %d\n", map->position_y);
//	printf("map->rotation = %d\n", map->rotation);
	display_int_array(map);
}
/*
void	display_tab3(int tab[3])
{
	printf("Valeurs de tab[3] : tab[0] = %d, tab[1] = %d, tab[2] = %d\n", tab[0], tab[1], tab[2]);
}*/
