/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:57:43 by laroges           #+#    #+#             */
/*   Updated: 2023/10/30 15:01:39 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	ev_up_and_down(t_mlx_data *data, t_map *map)
{
	int		v;
	int		i;
	int		j;

	v = 0;
	i = 0;
	j = 0;
	map = ev_update_map(data, map, v);
	ft_putnbr_fd(map->tab_map[j][i], 1);
}

t_map	*ev_update_map(t_mlx_data *data, t_map *map, int v)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->size_y)
	{
		while (i < map->size_x)
		{
			if (map->tab_map[j][i] != 0)
				map->tab_map[j][i] += v;
			ft_putnbr_fd(map->tab_map[j][i], 1);
			write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		j++;
	}
	return (map);
}*/
