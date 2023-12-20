/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:48:05 by laroges           #+#    #+#             */
/*   Updated: 2023/12/20 08:38:40 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Calculate the x size of the map
int	pm_size_map(char *line_map, t_mlx_data *data)
{
	int		i;

	i = 0;
	while (line_map[i] && line_map[i] == ' ')
		i++;
	while (line_map[i])
	{
		while (ft_isdigit(line_map[i]) || line_map[i] == '-')
			i++;
		data->size_x++;
		if (line_map[i] == ',')
		{
			i++;
			while (line_map[i] && ft_isalnum(line_map[i]))
				i++;
		}
		while (line_map[i] && line_map[i] == ' ')
			i++;
		i++;
	}
	return (data->size_x);
}

// Calculate the map->(x, y) size and 
// create a linked list containing the lines of the *.fdf file
void	pm_read_map(t_mlx_data *data, char **argv, t_parsing *list)
{
	int		i;
	int		fd;
	char	*line_map;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		clean_error_fd("Error open fd", 1);
	line_map = get_next_line(fd);
	data->size_x = pm_size_map(line_map, data);
	while (line_map != NULL)
	{
		if (data->map_contain_colors == false)
			data->map_contain_colors = split_map_contain_colors(line_map);
		list = insert_node(list, line_map, data->size_x);
		while (i < data->size_x)
			i++;
		i = 0;
		data->size_y++;
		free(line_map);
		line_map = get_next_line(fd);
	}
	if (close(fd) == -1)
		clean_error_fd("Error close fd", 1);
	pm_create_tab_map(data, list);
}

// Create the two dimensions int tab size (called in read_map->function)
void	pm_create_tab_map(t_mlx_data *data, t_parsing *list)
{
	int		y;

	y = 0;
	data->tab_map = ft_calloc(sizeof(int *), data->size_y + 1);
	data->alt_reset = ft_calloc(sizeof(int *), data->size_y + 1);
	if (data->tab_map == NULL || data->alt_reset == NULL)
		clean_error_fd("Error ft_calloc", 1);
	while (y <= data->size_y)
	{
		data->tab_map[y] = ft_calloc(sizeof(int), data->size_x + 1);
		data->alt_reset[y] = ft_calloc(sizeof(int), data->size_x + 1);
		if (data->tab_map[y] == NULL || data->alt_reset[y] == NULL)
		{
			free(data->tab_map);
			clean_error_fd("Error ft_calloc", 1);
		}
		y++;
	}
	pm_insert_int_values(list, data);
}

/* At this point, we got the size (x, y) of the map->and the **int tab. 
 * The following function Inserts int values in the **int tab
 */
void	pm_insert_int_values(t_parsing *list, t_mlx_data *data)
{
	int		*p;
	char	*value;

	if (list == NULL)
		clean_error_fd("Error list == NULL fct pm_insert_int_values", 1);
	data->y = data->size_y - 1;
	while (list && (data->y >= 0))
	{
		while (data->x < data->size_x)
		{
			p = &data->tab_map[data->y][data->x];
			value = list->parsing_value[data->x];
			data->tab_map[data->y][data->x] = ft_atoi(value);
			data->alt_reset[data->y][data->x] = *p;
			free(value);
			data->x++;
		}
		data->y--;
		data->x = 0;
		list = clear_node(list);
	}
	data->y = 0;
	data->alt_top = values_get_top(data);
	data->alt_top_reset = data->alt_top;
}
