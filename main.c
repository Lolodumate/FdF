/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:00:31 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 19:45:24 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
		clean_map(*data, data->size_y);
		exit(0);
	}
	else if (key == XK_F12)
	{
		pm_reset_map(data);
		write(1, "Reset\n", 6);
		printf("Reset de l'altitude");
	}
	else if (key == XK_u)
	{
		data->altitude = 2;
		write(1, "u\n", 2);
		printf("Valeur de data->altitude = %d\n", data->altitude);
	}
	else if (key == XK_d)
	{
		data->altitude = -2;
		write(1, "d\n", 2);
		printf("Valeur de data->altitude = %d\n", data->altitude);
	}
	else if (key == XK_Down)
	{
		data->up += -10;
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
		data->upkp += 50;
		write(1, "Up_F1\n", 6);
		printf("Valeur de data->upkp = %d\n", data->upkp);
	}
	else if (key == XK_F2)
	{
		data->upkp += -50;
		write(1, "Down_F2\n", 8);
		printf("Valeur de data->upkp = %d\n", data->upkp);
	}
	else if (key == XK_F3)
	{
		data->rightkp += 50;
		write(1, "Right_F3\n", 9);
		printf("Valeur de data->rightkp = %d\n", data->upkp);
	}
	else if (key == XK_F4)
	{
		data->rightkp += -50;
		write(1, "Left_F4\n", 8);
		printf("Valeur de data->rightkp = %d\n", data->upkp);
	}
	else if (key == XK_F5)
	{
		data->zoom += 2;
		write(1, "Zoom_F5\n", 8);
		printf("Valeur de data->zoom = %d\n", data->zoom);
	}
	else if (key == XK_F6)
	{
		data->zoom += -2;
		write(1, "Zoom_F5\n", 8);
		printf("Valeur de data->zoom = %d\n", data->zoom);
	}
	else
		ft_putchar('x');
	menu_move(data);
	menu_change(data);
	drawing_web(data);
	data->image.image_ptr = mlx_new_image(data->mlx_ptr, 1800, 1000);
	if (data->image.image_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		clean_map(*data, data->size_y);
		exit(1);
	}
	data->altitude = 0;
	return (0);
}

int	mouse_hook(int k, int x, int y, t_mlx_data *data)
{
	if (k == 1)
	{
		if (x > 1700 && x <= 1800 && y >= 0 && y < 100)
		{
			printf("k == 1\n");
			data->mouse = 1;
		}
		data->image.image_ptr = mlx_new_image(data->mlx_ptr, 1800, 1000);
		if (data->image.image_ptr == NULL)
		{
			mlx_destroy_window(data->mlx_ptr, data->window_ptr);
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
			clean_map(*data, data->size_y);
			exit(1);
		}
	}
	return (0);
}

// mlx_get_color_value : It takes a standard RGB color and return an unsigned int value.
int	main(int argc, char **argv)
{
	t_parsing	*list;
	t_mlx_data	data;

	list = NULL;
	if (argc != 2)
		return (0);
	line_init(&data);
	data = map_init(data, argv);
	list = pm_read_map(&data, argv, list);
	if (list == NULL)
		return (-1);
	printf("data->size_y = %d\n", data.size_y);
//	display_map(data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(1);
	data.window_ptr = mlx_new_window(data.mlx_ptr, 1800, 1000, "mlx_42");
	if (data.window_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		clean_map(data, data.size_y);
		exit(1);
	}
	menu_move(&data);
	menu_change(&data);
	data.image.image_ptr = mlx_new_image(data.mlx_ptr, 1800, 1000);
	if (data.image.image_ptr == NULL)
	{
		mlx_destroy_window(data.mlx_ptr, data.window_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		clean_map(data, data.size_y);
		exit(1);
	}
	drawing_web(&data);
	mlx_key_hook(data.window_ptr, deal_key, &data);
	mlx_mouse_hook(data.window_ptr, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
