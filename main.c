/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:00:31 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 20:45:31 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * Compilation : cc -I $(INCLUDE) main.c -L $(INCLUDEMLX) -lmlx -framework OpenGL -framework AppKit
 *
 * */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
void	color_screen(t_mlx_data *data, int color)
{
	for (int y = 0; y < 1080; ++y)
	{
		for (int x = 0; x < 1920; ++x)
		{
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, x, y, color);
		}
	}
}
*/
void	put_pixel(t_mlx_data *data, int color)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (j < 20)
	{
		while (i < 20)
		{
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, i + 100, j + 100, color);
			i++;
		}
		i = 0;
		j++;
	}
}

int	deal_key(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
	{
		write(1, "Escape\n", 7);
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	else
		ft_putchar('x');
	return (0);
}

int	main(int argc, char **argv)
{
	t_parsing	*list;
	t_map		*map;
	t_line		*line;
	t_mlx_data	data;

	list = NULL;
	map = NULL;
	line = NULL;
	if (argc != 2)
		return (0);
	line = line_init(line);
	map = map_init(map);
// Leak de 1 byte dans la liste chainee
// *******************************************
	list = pm_read_map(argv, map, list);
	if (list == NULL)
		return (-1);
// *******************************************
	map = pm_insert_int_values(list, map);
	printf("map->map_size_y = %d\n", map->size_y);
	display_map(map);

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (-1);
	data.window_ptr = mlx_new_window(data.mlx_ptr, 1800, 1000, "mlx_42");
	if (data.window_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (-1);
	}
//	data.image.image_ptr = mlx_new_image(data.mlx_ptr, 800, 800);
//	data.image.image_pixel_ptr = mlx_get_data_addr(data.image.image_ptr, &data.image.bit_per_pixel, &data.image.line_len, &data.image.endian);
//	printf("Line_len %d <-> SIDE_LEN %d\nbpp %d\nendian %d\n", data.image.line_len, 500, data.image.bit_per_pixel, data.image.endian);
	mlx_key_hook(data.window_ptr, deal_key, &data);
	map_fill_matrix(map, line);
	drawing_web(data, map, line);
	clean_map_line(line, map, map->size_y);
	mlx_loop(data.mlx_ptr);
	return (0);
}
