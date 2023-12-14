/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:20:09 by laroges           #+#    #+#             */
/*   Updated: 2023/12/13 19:27:55 by laroges          ###   ########.fr       */
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

int		colors_size_line(int z1, int z2)
{
	int		size;

	size = values_abs(z1) - values_abs(z2);
	return (values_abs(size));
}

int		colors_int_limit(int color)
{
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	return (color);
}

void	colors_side(t_mlx_data *data, int z1, int z2, int p)
{
	int		trgb[4];
	int		c;
//	int		size;

	trgb[0] = 127;
	trgb[1] = 127;
	trgb[2] = 127;
	trgb[3] = 127;
	c = z1;
	if (values_abs(z2) > values_abs(z1))
		c = z2;
//	size = colors_size_line(z1, z2);
	if ((z1 != 0 || z2 != 0) && p > 0)
	{
		trgb[2] = 0;
		trgb[3] = colors_int_limit(255 - values_abs(c));
	}
	if ((z1 != 0 || z2 != 0) && p < 0)
	{
		trgb[1] = 0;
		trgb[2] = colors_int_limit(255 - values_abs(c));
	}
	data->color = create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]);
}

t_mlx_data	*colors_get(t_mlx_data *data, int z1, int z2)
{
	int		p;

	p = 0;
//	data->color = create_trgb(0, 255, 255, 255);
	if (values_abs(data->alt_top) != 0)
		if ((((z1 + z2) / 2) * 100 <= INT_MAX)
			|| (((z1 + z2) / 2) * 100 >= INT_MIN))
			p = ((z1 + z2) / 2) * 100 / values_abs(data->alt_top);
	if (p > 100)
		p = 100;
	if (p < -100)
		p = -100;
	colors_side(data, z1, z2, p);
/*	if (m == 0)
		data->color = WHITE;
	if (m < 0)
		data->color = BLUE;
	if (m > 0)
		data->color = RED;
*/	return (data);
}
