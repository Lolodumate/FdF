/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:48:05 by laroges           #+#    #+#             */
/*   Updated: 2023/12/01 19:01:14 by laroges          ###   ########.fr       */
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
	while (line_map[i++])
	{
		if (line_map[i] && line_map[i] == ',')
		{
			i++;
			while (line_map[i] && ft_isalnum(line_map[i]))
				i++;
			while (line_map[i] && line_map[i] == ' ')
				i++;
			data->size_x++;
		}
		else
		{
			while (ft_isdigit(line_map[i]))
				i++;
			if (line_map[i] == ' ')
				data->size_x++;
			while (line_map[i] == ' ')
				i++;
		}
	}
	printf("pm_size_map - Valeur de map->size_x = %d\n", data->size_x);
	return (data->size_x);
}

// Calculate the map->(x, y) size and create a linked list containing the lines of the *.fdf file
t_parsing	*pm_read_map(t_mlx_data *data, char **argv, t_parsing *list)
{
	int		i;
	int		fd;
	char	*line_map;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_map = get_next_line(fd);
	data->size_x = pm_size_map(line_map, data);
	while (line_map != NULL)
	{
		if (data->map_contain_colors == false)
			data->map_contain_colors = split_map_contain_colors(line_map);
		list = insert_node(list, line_map, data->size_x);
//		printf("pm_read_map - i = %2d - line = %s", list->index, line_map);
		while (i < data->size_x)
			i++;
		i = 0;
		data->size_y++;
		free(line_map);
		line_map = get_next_line(fd);
	}
	pm_create_tab_map(data);
	colors_create_tab_colors(data);
	list = colors_insert_colors(list, data);
	pm_insert_int_values(list, data);
	return (list);
}

// Create the two dimensions int tab size (called in read_map->function)
void	pm_create_tab_map(t_mlx_data *data)
{
	int		y;
	
	y = 0;
	data->tab_map = ft_calloc(sizeof(int *), data->size_y + 1);
	data->altitude_reset = ft_calloc(sizeof(int *), data->size_y + 1);
	if (data->tab_map == NULL || data->altitude_reset == NULL)
		return ;
	while (y <= data->size_y)
	{
		data->tab_map[y] = ft_calloc(sizeof(int), data->size_x + 1);
		data->altitude_reset[y] = ft_calloc(sizeof(int), data->size_x + 1);
		if (data->tab_map[y] == NULL || data->altitude_reset[y] == NULL)
		{
			free(data->tab_map);
			return ;
		}
		y++;
	}
}

void	pm_reset_map(t_mlx_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y <= data->size_y)
	{
		while (x < data->size_x)
		{
			data->tab_map[y][x] = data->altitude_reset[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

/* At this point, we got the size (x, y) of the map->and the **int tab. 
 * The following function Inserts int values in the **int tab
 */
void	pm_insert_int_values(t_parsing *list, t_mlx_data *data)
{
	char	*value;

	if (list == NULL)
		return ;
	data->y = data->size_y - 1;
	while (list && (data->y >= 0))
	{
		while (data->x < data->size_x)
		{
			value = list->parsing_value[data->x];
//			printf("data->x = %d - value = %s\n", data->x, value);
			data->tab_map[data->y][data->x] = ft_atoi(value);
			data->altitude_reset[data->y][data->x] = data->tab_map[data->y][data->x];
			free(value);
			data->x++;
		}
		data->y--;
		data->x = 0;
		list = clear_node(list);
	}
	data->y = 0;
}
