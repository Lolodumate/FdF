/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:00:31 by laroges           #+#    #+#             */
/*   Updated: 2023/10/26 21:43:45 by laroges          ###   ########.fr       */
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

void	color_screen(t_mlx_data *data, int color)
{
	for (int y = 0; y < 500; ++y)
	{
		for (int x = 0; x < 500; ++x)
		{
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, x, y, color);
		}
	}
}

int	deal_key(int key, t_mlx_data *data)
{
	if (key == XK_r)
		color_screen(data, 0xff0000);
	else if (key == XK_g)
		color_screen(data, 0xff00);
	else if (key == XK_b)
		color_screen(data, 0xff);
	else if (key == XK_Escape)
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
	(void)argc;
	(void)argv;
//	t_parsing	*list;
	t_map		*map;
	t_mlx_data	data;

//	list = NULL;
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (-1);
	map->size_x = 0;
	map->size_y = 0;
	map->x = 0;
	map->y = 0;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (-1);
	data.window_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "mlx_42");
	if (data.window_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (-1);
	}
	data.image.image_ptr = mlx_new_image(data.mlx_ptr, 500, 500);
	data.image.image_pixel_ptr = mlx_get_data_addr(data.image.image_ptr, &data.image.bit_per_pixel, &data.image.line_len, &data.image.endian);
	printf("Line_len %d <-> SIDE_LEN %d\nbpp %d\nendian %d\n", data.image.line_len, 500, data.image.bit_per_pixel, data.image.endian);
	mlx_key_hook(data.window_ptr, deal_key, &data);
//	mlx_pixel_put(mlx_ptr, window_ptr, int x, int y, int color); // (x, y) = Coordonnees du pixel
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.window_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free(data.window_ptr);
	return (0);
}
