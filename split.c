/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:38:11 by laroges           #+#    #+#             */
/*   Updated: 2023/12/20 06:55:01 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	split_map_contain_colors(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			return (true);
		i++;
	}
	return (false);
}

char	**split_malloc_value_a(char **value, char *line, int size)
{
	value = malloc(sizeof(char *) * size);
	if (line == NULL || value == NULL)
		return (NULL);
	return (value);
}

char	*split_malloc_value_b(char **value_a, char *value, int len)
{
	value = ft_calloc(sizeof(char), len + 1);
	if (value == NULL)
	{
		free(value_a);
		return (NULL);
	}
	return (value);
}

char	**split_get_value(char *line, int size)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**value;

	i = 0;
	j = -1;
	k = 0;
	value = NULL;
	value = split_malloc_value_a(value, line, size);
	while (++j < size)
	{
		while (line[i] && !ft_isdigit(line[i]) && line[i] != '-')
			i++;
		len = values_len_value(line, i);
		value[j] = split_malloc_value_b(value, value[j], len);
		while (line[i] && (ft_isdigit(line[i]) || line[i] == '-'))
			value[j][k++] = line[i++];
		if (line[i++] == ',')
			while (ft_isalnum(line[i]))
				i++;
		k = 0;
	}
	return (value);
}
