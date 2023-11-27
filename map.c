/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:23:26 by laroges           #+#    #+#             */
/*   Updated: 2023/11/21 20:47:16 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_data	map_init(t_mlx_data data)
{
//	data.= malloc(sizeof(t_data.);
//	if (data.== NULL)
//		return (NULL);
	data.scale = 5;
	data.size_x = 0;
	data.size_y = 0;
	data.x = 0;
	data.y = 0;
	data.position_x = 500;
	data.position_y = 200;
//	data.greatest_z = 0;
//	data.smallest_z = 0;
	data.rotation = 0;
	data.tab_map = NULL;
	data.zoom = 40;
	data.up = 0;
	data.right = 0;
	return (data);
}
/*
t_data.*data.scale(t_data.*data.
{
	data.scale = (1000 / data.size_y) / 2;
	data.position_x = 1800 / data.scale * (data.size_x * 2 / 3);
	data.position_y = 1000 / data.scale * data.size_y;
	return (data.;
}*/
