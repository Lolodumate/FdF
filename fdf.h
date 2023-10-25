/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 01:38:31 by laroges           #+#    #+#             */
/*   Updated: 2023/10/24 05:12:01 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_image
{
	void	*image_ptr;
	char	*image_pixel_ptr;
	int	bit_per_pixel;
	int	endian;
	int	line_len;
}	t_image;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_image	image;
}	t_mlx_data;

void	ft_putchar(char c);
void    color_screen(t_mlx_data *data, int color);
int	deal_key(int key, t_mlx_data *data);

#endif
