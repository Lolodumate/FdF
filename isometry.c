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
