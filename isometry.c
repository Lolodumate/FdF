/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:16 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 18:32:45 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_view(t_mlx_data *data, int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.816540);
	*x += data->shiftx;
	*x += data->right;
	*x += data->rightkp;
	*x += data->zoom;
	*y = (*x + *y) * sin(0.816540) - z;
	*y += data->shifty;
	*y -= data->up;
	*y += data->upkp;
	*x += data->zoom;
}
