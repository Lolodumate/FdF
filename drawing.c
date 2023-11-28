/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:19:00 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 20:19:45 by laroges          ###   ########.fr       */
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

// https://htmlcolorcodes.com/fr/
//	matrix->color = "0xffffff";
	// Plus z est grand, plus il tend vers le rouge
	// blanc vers le rouge = decremention de color[4] et color[6] de f vers 0, puis reinitialisation avec decrementation de color[3] et color[5]
//	Plus z est petit, plus il tend vers le bleu

 /* https://www.youtube.com/watch?v=nQbnYl7xgb8
        * Deux cas :
        * - droite > 45 degres
        * - droite < 45 degres
        * > Creer un booleen pour determiner l'angle de la droite       
        * int dx = abs(x2 - x1)
        * int dy = abs(y2 - y1)
        * Coefficient directeur float m(ou a) = dy / dx
        * 
        * Equation d'une droite y = mx + y1
        * A faire :
        * - Verifier les valeurs de y pour calculer les arrondis.
        * - Quand la decimale de y est superieur a 0.5, alors arrondir a l'entier superieur, et inversement.
        * Pour tenir compte de cette correction faire y = mx + y1 + 0.5
        * Cette methode pose probleme pour les droite verticales ou quasi verticales
        * **************************************************************************************
        * Determiner de quel pixel le coefficient directeur a (ou m) est le plus proche.
        * Calculer le coefficient directeur et afficher le pixel le plus proche.
        * y = -1     _______________
        *           |       |    /  |
        *           |       |   /   |
        *           |       |  /    |
        * y = 0.5   |_______|_/_____|.....
        *           |       |/......|..... e
        *           |       |       |
        *           |      /|       |
        * y = 1     |_____/_|_______|
        * 
        * Cas 1 : le coefficient directeur a est negatif.
        * if (a <= -0.5)
        *       y--;
        * NB : un coefficient directeur negatif correspond a une droite ascendante.
        * Le pixel qui sera dessine est une approximation. Il faut donc 'recaler' le coefficient directeur pour le pixel suivant calculant e (erreur) a l'aide de la formule e = a + 1 (premier passage de boucle). 
        * x++ & :
        * >> Si y-- alors
        * Ensuite faire e = a + e pour repositionner a sur le prochain pixel de la droite theorique en tenant de l'erreur e.
        * Et ainsi de suite. Refaire les calculs de e et a a chaque incrementation de x.
        * >> Sinon alors
        * y ne bouge pas, donc :
        * 1.    e = m + e
        * 2.    if(e < -0.5) y--
        * >> Si la condition precedente est vraie et que y a ete decremente, alors e = e + 1
        * Continuer sur le meme principe jusqu'a x2.
        *
        * Note : essayer d'utiliser des doubles au lieu des float pour voir s'il y a un gain de performance.
        *
        */

void	drawing_line(t_mlx_data *data, int z)
{
	int		i;
	double		x;
	double		y;

	data->xi = 1;
	data->yi = 1;
	i = 0;
	x = data->x1;
	y = data->y1;
	data->ex = abs(data->x2 - data->x1);
	data->ey = abs(data->y2 - data->y1);
	data->tmpx = data->ex;
	data->tmpy = data->ey;
	data->dx = 2 * data->ex;
	data->dy = 2 * data->ey;
	if (x > data->x2)
		data->xi = -1;
	if (y > data->y2)
		data->yi = -1;
	if (data->tmpx >= data->tmpy)
	{
		while (i <= data->tmpx)
		{
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, x, y, z);
			x += data->xi;
			data->ex -= data->dy;
			if (data->ex < 0)
			{
				y += data->yi;
				data->ex += data->dx;
			}
			i++;
		}
	}
	if (data->tmpx < data->tmpy)
        {
                while (i <= data->tmpy)
                {
                        mlx_pixel_put(data->mlx_ptr, data->window_ptr, x, y, z);
                        y += data->yi;
                        data->ey -= data->dx;
                        if (data->ey < 0)
                        {
                                x += data->xi;
                                data->ey += data->dy;
                        }
                        i++;
                }
        }

}

t_mlx_data	*drawing_get_color(t_mlx_data *data, int z1, int z2)
{
	if (z1 == 0 && z2 == 0)
		data->color = 0xffffff;
	else if (z1 < 0 || z2 < 0)
		data->color = 0x00aaaa;
	else if (z1 > 8 || z2 > 8)
		data->color = 0xff0000;
	else if (z1 > 15 || z2 > 15)
		data->color = 0xff1000;
	else if (z1 > 14 || z2 > 14)
		data->color = 0xff2000;
	else if (z1 > 13 || z2 > 13)
		data->color = 0xff3000;
	else if (z1 > 12 || z2 > 12)
		data->color = 0xff4000;
	else if (z1 > 11 || z2 > 11)
		data->color = 0xff5000;
	else if (z1 > 10 || z2 > 10)
		data->color = 0xff6000;
	else if (z1 > 9 || z2 > 9)
		data->color = 0xff7000;
	else if (z1 > 8 || z2 > 8)
		data->color = 0xff8000;
	else if (z1 > 7 || z2 > 7)
		data->color = 0xff9000;
	else if (z1 > 6 || z2 > 6)
		data->color = 0xff0f00;
	else if (z1 > 5 || z2 > 5)
		data->color = 0xff1f00;
	else if (z1 > 4 || z2 > 4)
		data->color = 0xff2f00;
	else if (z1 > 3 || z2 > 3)
		data->color = 0xff3f00;
	else if (z1 > 2 || z2 > 2)
		data->color = 0xff4f00;
	else if (z1 > 1 || z2 > 1)
		data->color = 0xff5f00;
	return (data);
}

void	drawing_web(t_mlx_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			drawing_get_color(data, data->tab_map[y][x], data->tab_map[y][x + 1]);
			x = line_setx(data, x, y);
			drawing_line(data, data->color);
		}
	}
	x = -1;
	while (++x < data->size_x)
	{
		y = 0;
		while (y < data->size_y)
		{
			drawing_get_color(data, data->tab_map[y][x], data->tab_map[y + 1][x]);
			y = line_sety(data, x, y);
			drawing_line(data, data->color);
		}
	}
}

/* La variable rotation (dans t_map) permet d'incliner la carte.
 * Par convention un inclinaison de 30 degres implique une reduction de la taille des segments auxquels il faut appliquer un coefficient de 0.82.
 * Par ailleurs, une inclinaison de 30 degres d'un carre ou rectangle implique que, du fait de la perspective isometrique, l'angle rectangle s'elargisse a 120 degres. Nous avons donc trois angles de 30, 120 et 30 degres.
 * */
