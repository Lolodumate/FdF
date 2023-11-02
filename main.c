/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:00:31 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 22:38:44 by laroges          ###   ########.fr       */
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
	for (int y = 0; y < 1080; ++y)
	{
		for (int x = 0; x < 1920; ++x)
		{
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, x, y, color);
		}
	}
}

void	put_pixel(t_mlx_data *data, int color)
{
	int		i;
	int		j;
//	int		tab[20][20];
	i = 0;
	j = 0;
	while (j < 20)
	{
		while (i < 20)
		{
//			tab[j][i] = {0};	
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, i + 100, j + 100, color);
			i++;
		}
		i = 0;
		j++;
	}
}

int	deal_key(int key, t_mlx_data *data)
{
	if (key == XK_r)
	{
		color_screen(data, 0xff0000);
		ft_putchar('r');
	}
	else if (key == XK_g)
	{
		color_screen(data, 0xff00);
		ft_putchar('g');
	}
	else if (key == XK_b)
	{
		color_screen(data, 0xff);
		ft_putchar('b');
	}
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
	t_parsing	*list;
	t_map		*map;
	t_line		*line;
	t_mlx_data	data;

	list = NULL;
	map = NULL;
	line = NULL;
	if (argc != 2)
	{
		printf("Le nombre d'arguments doit etre de deux.\n");
		return (0);
	}
	line = line_init(line);
	map = map_init(map);
	list = pm_read_map(argv, map, list);
	if (list == NULL)
		return (-1);
	map = pm_insert_int_values(list, map);
	display_map(map);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (-1);
	data.window_ptr = mlx_new_window(data.mlx_ptr, 860, 480, "mlx_42");
	if (data.window_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (-1);
	}
	data.image.image_ptr = mlx_new_image(data.mlx_ptr, 860, 480);
	data.image.image_pixel_ptr = mlx_get_data_addr(data.image.image_ptr, &data.image.bit_per_pixel, &data.image.line_len, &data.image.endian);
	printf("Line_len %d <-> SIDE_LEN %d\nbpp %d\nendian %d\n", data.image.line_len, 500, data.image.bit_per_pixel, data.image.endian);
	mlx_key_hook(data.window_ptr, deal_key, &data);

//	drawing_web(data, map, line);
	//printf("Valeur de map->position_x = %d\nValeur de map->position_y = %d\n", map->position_x,     map->position_y);

	line_draw_map_tab_int_y(data, line, map);
	line_draw_map_tab_int_x(data, line, map);

	mlx_loop(data.mlx_ptr);
	clean_memory(&data, line, map);
	return (0);
}
