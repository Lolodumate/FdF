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
/*
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
}*/

int	deal_key(int key, t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_image(data->mlx_ptr, data->image.image_ptr);
	if (key == XK_Escape)
	{
		write(1, "Escape\n", 7);
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		clean_tab_int_map((*data), (*data).size_y);
		printf("deal_key - Check Check\n");
		exit(1);
	}
	else if (key == XK_Up)
	{
		data->up += 10;
		write(1, "Up\n", 3);
		printf("Valeur de data->up = %d\n", data->up);
	}
	else if (key == XK_Down)
	{
		data->up += -10;
		write(1, "Down\n", 5);
		printf("Valeur de data->up = %d\n", data->up);
	}
	else if (key == XK_Right)
	{
		data->right += 10;
		write(1, "Right\n", 6);
		printf("Valeur de data->right = %d\n", data->up);
	}
	else if (key == XK_Left)
	{
		data->right += -10;
		write(1, "Left\n", 5);
		printf("Valeur de data->right = %d\n", data->up);
	}
	else if (key == XK_F1)
	{
		data->up_KP += 50;
		write(1, "Up_F1\n", 6);
		printf("Valeur de data->up_KP = %d\n", data->up_KP);
	}
	else if (key == XK_F2)
	{
		data->up_KP += -50;
		write(1, "Down_F2\n", 8);
		printf("Valeur de data->up_KP = %d\n", data->up_KP);
	}
	else if (key == XK_F3)
	{
		data->right_KP += 50;
		write(1, "Right_F3\n", 9);
		printf("Valeur de data->right_KP = %d\n", data->up_KP);
	}
	else if (key == XK_F4)
	{
		data->right_KP += -50;
		write(1, "Left_F4\n", 8);
		printf("Valeur de data->right_KP = %d\n", data->up_KP);
	}
	else if (key == XK_F5)
	{
		data->zoom += 1;
		write(1, "Zoom_F5\n", 8);
		printf("Valeur de data->zoom = %d\n", data->zoom);
	}
	else if (key == XK_F6)
	{
		data->zoom += -1;
		write(1, "Zoom_F5\n", 8);
		printf("Valeur de data->zoom = %d\n", data->zoom);
	}
	else
		ft_putchar('x');
	drawing_web(data);
	data->image.image_ptr = mlx_new_image(data->mlx_ptr, 1800, 1000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_parsing	*list;
//	t_map		map;
	t_mlx_data	data;

	list = NULL;
//	map = NULL;
	if (argc != 2)
		return (0);
	line_init(&data);
	data = map_init(data);
	list = pm_read_map(&data, argv, list);
	if (list == NULL)
		return (-1);
	pm_insert_int_values(list, &data);
	printf("data->size_y = %d\n", data.size_y);
	display_map(data);
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
	data.image.image_ptr = mlx_new_image(data.mlx_ptr, 1800, 1000);
	drawing_web(&data);
//	data.image.image_pixel_ptr = mlx_get_data_addr(data.image.image_ptr, &data.image.bit_per_pixel, &data.image.line_len, &data.image.endian);
	//	printf("Line_len %d <-> SIDE_LEN %d\nbpp %d\nendian %d\n", data.image.line_len, 500, data.image.bit_per_pixel, data.image.endian);
	mlx_key_hook(data.window_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	printf("Check\n");
	mlx_clear_window(data.mlx_ptr, data.window_ptr);
	mlx_destroy_image(data.mlx_ptr, data.image.image_ptr);
	mlx_destroy_window(data.mlx_ptr, data.window_ptr);
	clean_tab_int_map(data, data.size_y);
	free(data.image.image_ptr);
	free(data.window_ptr);
	free(data.mlx_ptr);
	return (0);
}
