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
/*
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
*/
/*
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
*/
/*
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
			printf("tmp = %s\n", tmp);
			data->colorx[data->y][data->x] = 0x49ff00;
			free(tmp);
			data->x++;
		}
		list = list->next;
		data->y--;
		data->x = 0;
	}
	data->y = 0;
	return (ptr);
}
*/
t_mlx_data	*colors_get_color(t_mlx_data *data, int z1, int z2)
{
	int		m;

	m = 0;
	if ((((z1 + z2) / 2) * 100 <= INT_MAX) ||
		(((z1 + z2) / 2) * 100 >= INT_MIN)) 
		m = ((z1 + z2) / 2) * 100 / values_abs(data->altitude_top);
//	if (m != 0)
//		printf("m == (%d + %d) / 2 * 100 / %d == %d\n", z1, z2, data->altitude_top, m);
	m *= 255 / 100;
//	if (m != 0)
//		printf("values_abs(m) == %d\n", m);
	if (m == 0)
		data->color = WHITE;
	if (m < 0)
		data->color = BLUE;
	if (m > 0)
		data->color = RED;
	return (data);
}
