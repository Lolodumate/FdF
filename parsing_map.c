/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:48:05 by laroges           #+#    #+#             */
/*   Updated: 2023/10/26 21:31:58 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Calculate the x size
int	pm_size_mapx(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line_map[i] == ' ')
		i++;
	while (line_map[++i])
	{
		if (line_map[i] == ' ')
		{
			map.x++;
			while (line_map[i] == ' ')
				i++;
		}
	}
	if (line_map[i - 1] != ' ')
		map.x++;
	return (map.x); 
}

// Cut the line in order to create as strings as values
void	pm_parsing(t_parsing *list, t_map *map, char *line)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	k = 0;
	len = 0;
	list->parsing_line = ft_calloc(sizeof(char *), map.x + 1);
	if (list->parsing_line == NULL)
		return ;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		while (line[i] != ' ')
		{
			len = values_len_value(line, i);
			list->parsing_line[j] = ft_calloc(sizeof(char), len + 1);
			if (list->parsing_line[j] == NULL)
				return ;
			list->parsing_line[j][k] = line[i];
			(i++, k++);
		}
		(j++, k = 0);
	}
}

// Calculate the map (x, y) size and create a linked list containing the lines of the *.fdf file
t_parsing	*pm_read_map(char **argv, t_map *map, t_parsing *list)
{
	int		fd;
	char	*line_map;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (line_map = get_next_line(fd))
	{
		list = insert_node(list, map, line_map);
		parsing(list, map, line_map);
		map.size_y++;
		free(line_map);
	}
	map.x = size_mapx(list->line, map);
	map = create_tab_map(map);
	list->map = map;
	return (list);
}

// Create the two dimensions int tab size (called in read_map function)
t_map	*pm_create_tab_map(t_map *map)
{
	map.tab_map[map.size_y][map.size_x];

	return (map);
}

// Insert int values in the **int
t_parsing	*pm_insert_int_values(t_parsing *list)
{
	char	*value;

	while (list->map.y++ <= list->map.size_y)
	{
		while (list->map.x++ <= list->map.size_x)
		{
			value = list.parsing_line[list->map.size_x];
			tab_map[list->map.size_y - list->map.y][list->map.x] = ft_atoi(value);
			free(value);
		}
		list->map.x = 0;
		list = clear_node(list);
	}
	return (list);
}
