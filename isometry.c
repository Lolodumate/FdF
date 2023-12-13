/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:16 by laroges           #+#    #+#             */
/*   Updated: 2023/12/13 19:10:00 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Remplacer les int par des float
//
void	iso_view(t_mlx_data *data, int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.816540);
	*x += data->shiftx;
	*x += data->right;
	*x += data->rightkp;
	*y = (*x + *y) * sin(0.816540) - z;
	*y += data->shifty;
	*y -= data->up;
	*y += data->upkp;
}
