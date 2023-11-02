/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:57 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 17:22:27 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_memory(t_mlx_data *data, t_line *line, t_map *map)
{
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->window_ptr);
	free(line);
	free_tab_int_map(map);
	free(map);
}
