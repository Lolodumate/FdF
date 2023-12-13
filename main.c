/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:00:31 by laroges           #+#    #+#             */
/*   Updated: 2023/12/13 19:12:54 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		clean_map(*data, data->size_y);
		exit(0);
	}
	else if (key == XK_F12)
	{
		map_reset_map(data);
		data->alt_top = data->alt_top_reset;
	}
	else if (key == XK_u)
	{
		data->alt = 2;
		data->alt_top += data->alt;
		if (data->alt_top == 0)
			data->alt_top += data->alt;
	}
	else if (key == XK_d)
	{
		data->alt = -2;
		data->alt_top += data->alt;
		if (data->alt_top == 0)
			data->alt_top += data->alt;
	}
	else if (key == XK_Down)
		data->up += -10;
	else if (key == XK_Up)
		data->up += 10;
	else if (key == XK_Down)
		data->up += -10;
	else if (key == XK_Right)
		data->right += 10;
	else if (key == XK_Left)
		data->right += -10;
	else if (key == XK_F1)
		data->upkp += 50;
	else if (key == XK_F2)
		data->upkp += -50;
	else if (key == XK_F3)
		data->rightkp += 50;
	else if (key == XK_F4)
		data->rightkp += -50;
	else if (key == XK_F5)
		data->zoom += 2;
	else if (key == XK_F6)
		data->zoom += -2;
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->img.width, data->img.height);
	if (data->img.img_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		clean_map(*data, data->size_y);
		exit(1);
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.line_len, &data->img.endian);
	draw_web(data);
	menu(data);
	data->alt = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_parsing	*list;
	t_mlx_data	data;
	t_img		img;

	list = NULL;
	if (argc != 2)
		return (0);
	img = map_fdf_init(argv, &data, img, list);
	data = map_init_data(data);
	printf("data->size_x = %d\n", data.size_x);
	draw_web(&data);
	menu(&data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_hook(data.win_ptr, 17, 0L, clean_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
