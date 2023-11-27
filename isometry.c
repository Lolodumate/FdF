/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:16 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 19:02:01 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* https://www.letudiant.fr/college/methodologie-college/article/geometrie-comment-calculer-les-angles-dun-triangle-rectangle.html#:~:text=Dans%20un%20triangle%20rectangle%20ABC,AC2%20%3D%20AB2%20%2B%20BC2).
 *
 *  Triangle rectangle ABC avec AC = hypothenuse.
 *  Calcul d'un angle :
 *  	1. Calcul du Cosinus : AB / AC
 *  	2. Conversion en degres a l'aide de la fonction cos
 *
 *   Exemples de conversions Radians en degres : 
 *   	- Pi * Rad = 180 degres
 *   	- 1 * Rad = 57.29578 degres
 *   	- 1 degres = 0.0174533 radians (soit Pi / 180)
 *   	- 120 degres = (Pi / 180) * 120 = 2.09439510 radians
 */
/*
t_map	*iso_rotation(t_map *map, t_line *web)
{
	map->rotation = 0;
	
}*/

/* Cos 30 degres = 0.8660254
 * Conversion 30 degres en radians : 30 / 57.29578 = 0.52359771;
 * Cos 0.52359771 radians = 0.8660254
 * AB / AC = 0.8660254 -> AB = 0.8660254 * AC
 * 	
 *				|C
 *				|
 *				|
 *				|
 *				|
 *				|
 *	A_______________________|B
 */	

void	iso_view(t_mlx_data *data, int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.816540) + data->shift + data->right;
	*y = (*x + *y) * sin(0.816540) - z + data->shift - data->up;
}
/*
void	iso_map_update(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map->size_y)
	{
		while (x < map->size_x)
		{
			map->tab_map[y][x]++;
			if (map->tab_map[y][x] == 0)
				map->tab_map[y][x]--;
			x++;
		}
		x = 0;
		y++;
	}
}*/
