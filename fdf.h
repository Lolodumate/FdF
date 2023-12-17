/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 01:38:31 by laroges           #+#    #+#             */
/*   Updated: 2023/12/13 18:56:06 by laroges          ###   ########.fr       */
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

//# include <stdio.h>
# include <limits.h>
# include <math.h>

typedef enum e_color
{
	WHITE = 0xffffff,
	BLUE = 0x0000ff,
	GREEN = 0x00ff00,
	RED = 0xff00000
}	t_color;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_img
{
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		line_len;
	void	*img_ptr;
	char	*addr;
}	t_img;

typedef struct s_matrix
{
	int		*pixel_data;
	int		x;
	int		y;
	int		z;
}	t_matrix;

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
	void	*win_ptr;
	int		boost;
	int		menu;
	int		iso;
	int		size_x;
	int		size_y;
	int		**alt_reset;
	int		**tab_map;
	int		map_contain_colors;
	int		color;
	int		up;
	int		upkp;
	int		right;
	int		rightkp;
	int		x;
	int		y;
	int		alt;
	int		alt_top;
	int		alt_top_reset;
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
	t_img	img;
}	t_mlx_data;

int				clean_close(t_mlx_data *data);
int				colors_int_limit(int color);
int				colors_size_line(int z1, int z2);
int				values_abs(int n);
int				deal_key(int key, t_mlx_data *data);
int				split_map_contain_colors(char *line);
int				pm_size_map(char *line_map, t_mlx_data *data);
int				values_len_value(char *line, int i);
int				values_get_top(t_mlx_data *data);
int				line_bool(int x, int y, int width, int height);
int				line_in_the_screen(t_mlx_data *data);
int				line_setx(t_mlx_data *data, int x, int y);
int				line_sety(t_mlx_data *data, int x, int y);
int				draw_color(t_mlx_data *data, int z);
int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				c_trgb(char t, char r, char g, char b);
unsigned char	c_t(int trgb);
unsigned char	c_r(int trgb);
unsigned char	c_g(int trgb);
unsigned char	c_b(int trgb);
char			**split_get_value(char *line, int size);
//char			**split_get_color(char *line, int size);
void			clean_map(t_mlx_data data, int size_y);
void			clean_tab_int_map(t_mlx_data data, int size_y);
void			clean_tab_colors(t_mlx_data data, int size_y);
void			clean_memory(t_mlx_data *data);
//void			colors_create_tab_colors(t_mlx_data *data);
void			*display_img_ptr(t_mlx_data *data,void * img, int width, int height);
void			draw_line_x(t_mlx_data *data, int z);
void			draw_line_y(t_mlx_data *data, int z);
void			draw_web(t_mlx_data *data);
void			iso_view(t_mlx_data *data, int *x, int *y, int z);
void			map_resize_init(t_mlx_data *data);
void			menu(t_mlx_data *data);
void			menu_move(t_mlx_data *data);
void			menu_change(t_mlx_data *data);
void			pm_create_tab_map(t_mlx_data *data);
void			pm_insert_int_values(t_parsing *list, t_mlx_data *data);
t_img			map_fdf_init(char **argv, t_mlx_data *data, t_img img, t_parsing *list);
void			map_reset_map(t_mlx_data *data);
void			put_pixel(t_mlx_data *data, int x, int y, unsigned int color);
void			line_init(t_mlx_data *data, t_img *img);
void			line_update_alt(t_mlx_data *data, int up);
t_img			map_init(t_mlx_data *data, char **argv, t_img img);
void			colors_side(t_mlx_data *data, int z1, int z2, int p);
t_mlx_data		map_init_data(t_mlx_data data);
t_mlx_data		*draw_init_data(t_mlx_data *data, int x, int y);
t_mlx_data		*colors_get(t_mlx_data *data, int z1, int z2);
t_parsing		*clear_node(t_parsing *list);
//t_parsing		*colors_insert_colors(t_parsing *list, t_mlx_data *data);
t_parsing		*insert_node(t_parsing *list, char *line_map, int size);
t_parsing		*pm_read_map(t_mlx_data *data, char **argv, t_parsing *list);

void			display_linked_list(t_mlx_data data, t_parsing *list);
void			display_int_array(t_mlx_data data);
void			display_map(t_mlx_data data);

#endif
