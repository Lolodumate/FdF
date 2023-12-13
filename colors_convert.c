/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:13:08 by laroges           #+#    #+#             */
/*   Updated: 2023/12/13 18:49:44 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	c_trgb(char t, char r, char g, char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	c_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	c_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	c_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	c_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
