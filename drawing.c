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

t_mlx_data	*drawing_get_color(t_mlx_data *data, int z1, int z2)
{
	if (z1 == 0 && z2 == 0)
		data->color = 0xffffff;
	else if (z1 < 0 || z2 < 0)
		data->color = 0x00aaaa;
	else
		data->color = 0xff0000;
	return (data);
}

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
void	drawing_line(t_mlx_data data, t_line *line, int z)
{
	int		xi;
	int		yi;
	int		i;
	int		tmpx;
	int		tmpy;
	float		x;
	float		y;

	xi = 1;
	yi = 1;
	i = 0;
	tmpx = 0;
	tmpy = 0;
	x = line->x1;
	y = line->y1;
	line->ex = line->x2 - line->x1;
	if (line->ex < 0)
		line->ex *= -1;
	line->ey = line->y2 - line->y1;
	if (line->ey < 0)
		line->ey *= -1;
	tmpx = line->ex;
	tmpy = line->ey;
	line->dx = 2 * line->ex;
	line->dy = 2 * line->ey;
	if (x > line->x2)
		xi = -1;
	if (y > line->y2)
		yi = -1;
	if (tmpx >= tmpy)
	{
		while (i <= tmpx)
		{
			mlx_pixel_put(data.mlx_ptr, data.window_ptr, x, y, z);
			x += xi;
			line->ex -= line->dy;
			if (line->ex < 0)
			{
				y += yi;
				line->ex += line->dx;
			}
			i++;
		}
	}
	if (tmpx < tmpy)
        {
                while (i <= tmpy)
                {
                        mlx_pixel_put(data.mlx_ptr, data.window_ptr, x, y, z);
                        y += yi;
                        line->ey -= line->dx;
                        if (line->ey < 0)
                        {
                                x += xi;
                                line->ey += line->dy;
                        }
                        i++;
                }
        }

}

void	drawing_web(t_mlx_data data, t_map *map, t_line *line, int shift)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	line->shift = shift;
	while (y < map->size_y)
	{
		while (x < map->size_x)
		{
			drawing_get_color(&data, map->tab_map[y][x], map->tab_map[y][x + 1]);
			x = line_setx(line, map, x, y);
			drawing_line(data, line, data.color);
		}
		x = 0;
		y++;
	}
	x = 0;
	y = 0;
	while (x < map->size_x)
	{
		while (y < map->size_y)
		{
			drawing_get_color(&data, map->tab_map[y][x], map->tab_map[y + 1][x]);
			y = line_sety(line, map, x, y);
			drawing_line(data, line, data.color);
		}
		y = 0;
		x++;
	}
}

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
