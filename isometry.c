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
 *   	- 1 * Rad = 57,29578 degres
 *   	- 1 degre = 0,0174533 (soit Pi / 180)
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

float	iso_rotation(float ab) // ab == map->scale
{
	float		bc;
	float		ac_h;
	float		radian_30;

	bc = 1;
	ac_h = ab;
	radian_30 = 30 / 57.29578;
	printf("cos(radian_30) = %f\n", cos(radian_30));
	while (ab / ac_h > cos(radian_30))
		ac_h += 0.001;
	printf("Valeur de map->scale = %f - ", ab);
	printf("Valeur de ac_h = %f\n", ac_h);
	while ((bc * bc) < (ac_h * ac_h) - (ab * ab))
		bc += 0.1;
	printf("Valeur de bc = %f\n", bc);
	return (bc);
}
