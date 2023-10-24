/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:00:31 by laroges           #+#    #+#             */
/*   Updated: 2023/10/24 05:15:23 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

/*
 * Compilation : cc -I $(INCLUDE) main.c -L $(INCLUDEMLX) -lmlx -framework OpenGL -framework AppKit
 *
 * */
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}
*/
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	void	*mlx_ptr;
	void	*window_ptr;
	
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_42");
//	mlx_key_hook(window_ptr, deal_key, (void *)0);
//	mlx_pixel_put(mlx_ptr, window_ptr, int x, int y, int color); // (x, y) = Coordonnees du pixel
	mlx_loop(mlx_ptr);
	return (0);
}
