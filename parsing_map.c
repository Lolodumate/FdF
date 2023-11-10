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

// Cut the line in order to create as strings as values
t_parsing	*pm_parsing(t_parsing *list, t_map *map, char *line)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	k = 0;
	len = 0;
	list->parsing_line = malloc(sizeof(char *) * map->size_x + 1);
	if (list->parsing_line == NULL)
		return (NULL);
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		len = values_len_value(line, i);
		if (line[i])
		{
			list->parsing_line[j] = ft_calloc(sizeof(char), len + 1);
			if (list->parsing_line[j] == NULL)
				return (NULL);
			while (line[i] && line[i] != ' ')
			{
				list->parsing_line[j][k] = line[i];
				i++;
			       	k++;
			}
		}
		j++;
		k = 0;
	}
	return (list);
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
		list = insert_node(list, map, line_map);
		index_++;
		list->index = index_;
		list = pm_parsing(list, map, line_map);
		while (i < map->size_x)
			i++;
		i = 0;
		map->size_y++;
		free(line_map);
		line_map = get_next_line(fd);
	}
	map = pm_create_tab_map(map);
	list->map = map;
	return (list);
}

// Create the two dimensions int tab size (called in read_map->function)
t_map *pm_create_tab_map(t_map *map)
{
	int		j;
	
	j = 0;
	map->tab_map[1000] = malloc(sizeof(int *) * map->size_y);
	if (map->tab_map[1000] == NULL)
		return (NULL);
	while (j < map->size_y)
	{
		map->tab_map[j] = malloc(sizeof(int) * map->size_x);
		if (map->tab_map[j] == NULL)
		{
			free(map->tab_map[1000]);
			return (NULL);
		}
		j++;
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
	display_linked_list(list);
	map_init_matrix(map);
	map->y = map->size_y - 1;
	while (list && (map->y >= 0))
	{
		while (map->x < map->size_x)
		{
			value = list->parsing_line[map->x];
			map->tab_map[map->y][map->x] = ft_atoi(list->parsing_line[map->x]);
//			printf("%3d ", map->tab_map[map->y][map->x]);
			free(value);
			map->x++;
		}
//		printf("\n");
		map->y--;
		map->x = 0;
		list = clear_node(list);
	}
	map->y++;
	return (map);
}
