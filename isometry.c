/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:16 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 19:02:01 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_view(t_mlx_data *data, int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.816540);
	*x += data->shiftx;
	*x += data->right;
	*x += data->right_KP;
	*x += data->zoom;
	*y = (*x + *y) * sin(0.816540) - z;
	*y += data->shifty;
	*y -= data->up;
	*y += data->up_KP;
	*x += data->zoom;
}
