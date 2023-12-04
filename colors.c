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
		//	data->tab_colors[y][x][0] = '\0';
		}
		x = -1;
	}
}

void	colors_create_colorx(t_mlx_data *data)
{
	int		y;

	y = 0;
	data->colorx = ft_calloc(sizeof(int *), data->size_y + 1);
	if (data->colorx == NULL)
		return ;
	while (y <= data->size_y)
	{
		data->colorx[y] = ft_calloc(sizeof(int), data->size_x + 1);
		if (data->colorx[y] == NULL)
		{
			free(data->colorx);
			return ;
		}
		y++;
	}
}

t_parsing	*colors_insert_colors(t_parsing *list, t_mlx_data *data)
{
	t_parsing	*ptr;
	char	*tmp;

	ptr = list;
	if (list == NULL)
		return (NULL);
	data->y = data->size_y - 1;
	colors_create_colorx(data);
	while (list && (data->y >= 0))
	{
		while (data->x < data->size_x)
		{
			tmp = list->parsing_color[data->x];
			data->colorx[data->y][data->x] = mlx_get_color_value(data, data->colorx[data->y][data->x]);
			printf("tmp = %s\n", tmp);
			printf("colorx = %d\n", data->colorx[data->y][data->x]);
			free(tmp);
			data->x++;
		}
		list = list->next;
		data->y--;
		data->x = 0;
		printf("\n");
	}
	data->y = 0;
	return (ptr);
}
