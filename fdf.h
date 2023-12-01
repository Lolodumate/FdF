/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 01:38:31 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 19:29:10 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <limits.h>
# include <math.h>

typedef enum e_color
{
	WHITE = 0xffffff,
	SALMON = 0xff8080,
	RED = 0xff00000
}	t_color;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_image
{
	int		bit_per_pixel;
	int		endian;
	int		line_len;
	void	*image_ptr;
	char	*image_pixel_ptr;
}	t_image;

typedef struct s_data_matrix
{
	int		x;
	int		y;
	int		z;
	char	color[8];
}	t_data_matrix;

typedef struct s_parsing
{
	int					index;
	char				*line;
	char				**parsing_value;
	char				**parsing_color;
	struct s_parsing	*next;
}	t_parsing;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		size_x;
	int		size_y;
	int		**altitude_reset;
	int		**tab_map;
	int		map_contain_colors;
	int		color;
	int		up;
	int		upkp;
	int		right;
	int		rightkp;
	int		x;
	int		y;
	int		position_x;
	int		position_y;
	int		altitude;
	int		rotation;
	int		zoom;
	int		xi;
	int		yi;
	int		tmpx;
	int		tmpy;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		shiftx;
	int		shifty;
	char	***tab_colors;
	char	*map_name;
	t_image	image;
}	t_mlx_data;

int			deal_key(int key, t_mlx_data *data);
int			split_map_contain_colors(char *line);
int			pm_size_map(char *line_map, t_mlx_data *data);
int			values_len_value(char *line, int i);
int			line_setx(t_mlx_data *data, int x, int y);
int			line_sety(t_mlx_data *data, int x, int y);
int			drawing_color(t_mlx_data *data, int z);
double		iso_rotation(double ab, int angle);
double		iso_correction_hypothenuse(double scale, double ab, int angle);
char		**split_get_value(char *line, int size);
char		**split_get_color(char *line, int size);
void		ft_putchar(char c);
void		clean_map(t_mlx_data data, int size_y);
void		clean_tab_int_map(t_mlx_data data, int size_y);
void		clean_tab_colors(t_mlx_data data, int size_y);
void		clean_memory(t_mlx_data *data);
//void		color_screen(t_mlx_data *data, int color);
void		colors_create_tab_colors(t_mlx_data *data);
t_parsing	*colors_insert_colors(t_parsing *list, t_mlx_data *data);
void		put_pixel(t_mlx_data *data, int color);
void		drawing_line_x(t_mlx_data *data, int z);
void		drawing_line_y(t_mlx_data *data, int z);
void		drawing_web(t_mlx_data *data);
void		iso_view(t_mlx_data *data, int *x, int *y, int z);
void		menu_move(t_mlx_data *data);
void		menu_change(t_mlx_data *data);
void		pm_reset_map(t_mlx_data *data);
void		line_init(t_mlx_data *data);
//t_map		*ev_update_map(t_mlx_data *data, t_map *map, int v);
//t_map		*map_data_matrix(t_map *map, int x, int y, int *tab);
//t_map		*map_init_matrix(t_map *map);
t_mlx_data	map_init(t_mlx_data data, char **argv);
t_mlx_data	*drawing_init_data(t_mlx_data *data, double x, double y);
t_mlx_data	*drawing_get_color(t_mlx_data *data, int z1, int z2);
//t_map		*map_scale(t_map *map);
void		pm_create_tab_map(t_mlx_data *data);
//t_map		*map_fill_matrix(t_map *map, t_line *line);
void		pm_insert_int_values(t_parsing *list, t_mlx_data *data);
t_parsing	*clear_node(t_parsing *list);
//t_parsing	*pm_parsing(t_parsing *list, t_map *map, char *line);
t_parsing	*insert_node(t_parsing *list, char *line_map, int size);
t_parsing	*pm_read_map(t_mlx_data *data, char **argv, t_parsing *list);

void		display_linked_list(t_mlx_data data, t_parsing *list);
void		display_int_array(t_mlx_data data);
void		display_map(t_mlx_data data);
//void		display_matrix(t_map *map);
//void		display_tab3(int tab[3]);
//void		display_matrix(t_map *map);

#endif
