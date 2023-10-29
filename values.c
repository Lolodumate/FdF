/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:13:24 by laroges           #+#    #+#             */
/*   Updated: 2023/10/26 18:44:46 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	values_len_value(char *line, int i)
{
	int		len;

	len = 0;
	if (line == NULL)
		return (-1);
	if (line[i] == '-')
	{
		len++;
		i++;
	}
	while (line[i] && ft_isdigit(line[i]))
	{
		len++;
		i++;
	}
	return (len);
}

char	*values_create_str(int len)
{
	char	*str;

	if (len == 0)
		return (NULL);
	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	**values_create_value(t_parsing *list, t_map *map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	map->char_value = malloc(sizeof(char *) * map->x + 1);
	if (map->char_value == NULL)
		return (NULL);
	while (list->line[i])
	{
		while (list->line[i] && list->line[i] == ' ')
			i++;
		map->char_value[j] = values_create_str(values_len_value(list->line, i));
		while (map->char_value[j])
		{
			map->char_value[j][k] = list->line[i];
			i++;
			k++;
		}
		j++;
	}
	return (map->char_value);
}
