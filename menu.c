#include "fdf.h"

/*	Nom de la map
 *	Fonctions interactives :
 *	- Monter/Descendre : touches directionnelles ou F1/F2
 *	- Translation Gauche/Droite : touches directionnelles ou F3/F4
 *	- Altitude +/- : U/D
 *	- Zoom +/- : F5/F6
 *	
 *
 *
 * 
 */
void	menu(t_mlx_data *data)
{
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 80, 0xffffff, data->map_name);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 120, 0xffffff, "Fonctions interactives :");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 140, 0xffffff, " - Monter/Descendre : F1/F2");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 160, 0xffffff, " - Translation Gauche/Droite : F3/F4");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 180, 0xffffff, " - Altitude +/- : u/d");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 200, 0xffffff, " - Zoom +/- : F5/F6");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 50, 220, 0xffffff, " - Reset altitude : F12");

}
