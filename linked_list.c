/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:02:14 by laroges           #+#    #+#             */
/*   Updated: 2023/12/20 08:34:34 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_parsing	*insert_node(t_parsing *list, char *line_map, int size)
{
	t_parsing	*node;

	node = malloc(sizeof(t_parsing));
	if (node == NULL)
		clean_error_fd("Error malloc fct insert_node", 1);
	node->index = 0;
	node->line = line_map;
	node->parsing_value = split_get_value(line_map, size);
	node->next = list;
	return (node);
}

t_parsing	*clear_node(t_parsing *list)
{
	t_parsing	*node;

	if (list == NULL)
		clean_error_fd("Error list == NULL fct clear_node", 1);
	node = list->next;
	free(list->parsing_value);
	free(list);
	return (node);
}

void	display_linked_list(t_mlx_data data, t_parsing *list)
{
	int	i;

	i = 0;
	while (list)
	{
		while (list && (i < data.size_x))
			i++;
		list = list->next;
		i = 0;
	}
}
