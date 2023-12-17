/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:51:39 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 19:11:16 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*display_img_ptr(t_mlx_data *data, void *img, int width, int height)
{
	img = mlx_new_image(data->mlx_ptr, width, height);
	if (data->img.img_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		clean_map(*data, data->size_y);
		exit(1);
	}
	return (img);
}

void	display_int_array(t_mlx_data data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < data.size_y)
	{
		while (i < data.size_x)
		{
//			printf("%3d", data.tab_map[j][i]);
//			printf(" ");
			i++;
		}
//		printf("\n");
		i = 0;
		j++;
	}
}
/*
void	display_map(t_mlx_data data)
{
	printf("map.size_x = %d\n", data.size_x);
	printf("map.size_y = %d\n", data.size_y);
	printf("map.x = %d\n", data.x);
	printf("map.x = %d\n", data.x);
	printf("map.position_x = %d\n", data.position_x);
	printf("map.position_y = %d\n", data.position_y);
	display_int_array(data);
}*/
