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

int	colors_size_line(int z1, int z2)
{
	int		size;

	size = values_abs(z1) - values_abs(z2);
	return (values_abs(size));
}

int	colors_int_limit(int color)
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

	trgb[0] = 127;
	trgb[1] = 127;
	trgb[2] = 127;
	trgb[3] = 127;
	c = z1;
	if (values_abs(z2) > values_abs(z1))
		c = z2;
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
	if (values_abs(data->alt_top) != 0)
		if ((((z1 + z2) / 2) * 100 <= INT_MAX)
			|| (((z1 + z2) / 2) * 100 >= INT_MIN))
			p = ((z1 + z2) / 2) * 100 / values_abs(data->alt_top);
	if (p > 100)
		p = 100;
	if (p < -100)
		p = -100;
	colors_side(data, z1, z2, p);
	return (data);
}
