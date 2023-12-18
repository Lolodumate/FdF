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
	draw_web(&data);
	menu(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, events_key, &data);
	mlx_hook(data.win_ptr, 17, 0L, clean_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
