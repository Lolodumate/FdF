/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:48:05 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 16:21:48 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Calculate the x size of the map
int	pm_size_map(char *line_map, t_map *map)
{
	int		i;

	i = 0;
	while (line_map[i] && line_map[i] == ' ')
		i++;
	while (line_map[++i])
	{
		if (line_map[i] && line_map[i] == ' ')
		{
			map->size_x++;
			while (line_map[i] && line_map[i] == ' ')
				i++;
		}
	}
	if (line_map[i - 1] != ' ')
		map->size_x++;
	return (map->size_x); 
}

// Calculate the map->(x, y) size and create a linked list containing the lines of the *.fdf file
t_parsing	*pm_read_map(char **argv, t_map *map, t_parsing *list)
{
	int		fd;
	int		index_;
	char	*line_map;

	int	i = 0;
	index_ = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_map = get_next_line(fd);
	map->size_x = pm_size_map(line_map, map);
	while (line_map != NULL)
	{
		list = insert_node(list,line_map);
		index_++;
		list->index = index_;
//		printf("pm_read_map - i = %2d - line = %s", list->index, line_map);
		while (i < map->size_x)
			i++;
		i = 0;
		map->size_y++;
		free(line_map);
		line_map = get_next_line(fd);
	}
	map = pm_create_tab_map(map);
	return (list);
}

// Create the two dimensions int tab size (called in read_map->function)
t_map *pm_create_tab_map(t_map *map)
{
	int		y;
	
	y = 0;
	map->tab_map = ft_calloc(sizeof(int *), map->size_y + 1);
	if (map->tab_map == NULL)
		return (NULL);
	while (y <= map->size_y)
	{
		map->tab_map[y] = ft_calloc(sizeof(int), map->size_x + 1);
		if (map->tab_map[y] == NULL)
		{
			free(map->tab_map);
			return (NULL);
		}
		y++;
	}
	return (map);
}

/* At this point, we got the size (x, y) of the map->and the **int tab. 
 * The following function Inserts int values in the **int tab
 */
t_map *pm_insert_int_values(t_parsing *list, t_map *map)
{
	char	*value;

	if (list == NULL || map == NULL)
		return (NULL);
	map->y = map->size_y - 1;
	while (list && (map->y >= 0))
	{
		while (map && (map->x < map->size_x))
		{
			value = list->parsing_line[map->x];
			map->tab_map[map->y][map->x] = ft_atoi(list->parsing_line[map->x]);
			if (map->tab_map[map->y][map->x] > map->greatest_z)
				map->greatest_z = map->tab_map[map->y][map->x];
			if (map->tab_map[map->y][map->x] < map->smallest_z)
				map->smallest_z = map->tab_map[map->y][map->x];
			free(value);
			map->x++;
		}
		map->y--;
		map->x = 0;
		list = clear_node(list);
	}
	map->y++;
	return (map);
}
