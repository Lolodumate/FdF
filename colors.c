/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:20:09 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 17:33:40 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colors_create_tab_colors(t_mlx_data *data)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	data->tab_colors = ft_calloc(sizeof(char **), data->size_y + 1);
	if (data->tab_colors == NULL)
		return ;
	while (++y <= data->size_y)
	{
		data->tab_colors[y] = ft_calloc(sizeof(char *), data->size_x + 1);
		if (data->tab_colors[y] == NULL)
			return ;
		while (++x <= data->size_x)
		{
			data->tab_colors[y][x] = ft_calloc(sizeof(char), 8 + 1);
			if (data->tab_colors[y][x] == NULL)
			{
				free(data->tab_colors[y]);
				free(data->tab_colors);
				return ;
			}
		}
		x = -1;
	}
}

t_parsing	*colors_insert_colors(t_parsing *list, t_mlx_data *data)
{
	t_parsing	*ptr;

	ptr = list;
	if (list == NULL)
		return (NULL);
	data->y = data->size_y - 1;
	while (list && (data->y >= 0))
	{
		while (data->x < data->size_x)
		{
			ft_strlcpy(data->tab_colors[data->y][data->x], list->parsing_color[data->x], 8);
			free(list->parsing_color[data->x]);
			data->x++;
		}
		list = list->next;
		data->y--;
		data->x = 0;
	}
	data->y = 0;
	return (ptr);
}
