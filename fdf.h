/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 01:38:31 by laroges           #+#    #+#             */
/*   Updated: 2023/10/26 21:48:52 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_image
{
	void	*image_ptr;
	char	*image_pixel_ptr;
	int	bit_per_pixel;
	int	endian;
	int	line_len;
}	t_image;

typedef struct	s_map
{
	int		size_x;
	int		size_y;
	int		x;
	int		y;
	int		*tab_map[100]; // Le nombre dans les accolades signifie la taille max du tableau. Voir quelle taille indiquer.
	char	**char_value;
}	t_map;

typedef struct	s_parsing
{
	int		index;
	char	*line;
	char	**parsing_line;
	t_map		*map;
	struct	s_parsing	*next;
}	t_parsing;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_image	image;
}	t_mlx_data;

int			deal_key(int key, t_mlx_data *data);
void			ev_up_and_down(t_map *map);
t_map			*ev_update_map(t_map *map, int v);
int			pm_size_mapx(char *line, t_map *map);
int			values_len_value(char *line, int i);
char		*values_create_str(int len);
char		**values_create_value(t_parsing *list, t_map *map);
void		ft_putchar(char c);
void		color_screen(t_mlx_data *data, int color);
t_parsing	*pm_parsing(t_parsing *list, t_map *map, char *line);
t_map		*pm_create_tab_map(t_map *map);
t_map		*pm_insert_int_values(t_parsing *list, t_map *map);
t_parsing	*insert_node(t_parsing *list, t_map *map, char *line_map);
t_parsing	*clear_node(t_parsing *list);
t_parsing	*pm_read_map(char **argv, t_map *map, t_parsing *list);


void		display_fdf_file(t_map *map);
void		display_linked_list(t_parsing *list);
void		display_int_array(t_map *map);

#endif
