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
			printf("%3d", data.tab_map[j][i]);
			ft_putchar(' ');
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

void	display_map(t_mlx_data data)
{
	printf("map.size_x = %d\n", data.size_x);
	printf("map.size_y = %d\n", data.size_y);
	printf("map.x = %d\n", data.x);
	printf("map.x = %d\n", data.x);
	printf("map.position_x = %d\n", data.position_x);
	printf("map.position_y = %d\n", data.position_y);
	display_int_array(data);
}
