/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:02:14 by laroges           #+#    #+#             */
/*   Updated: 2023/10/26 20:29:40 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_parsing	*insert_node(t_parsing *list, t_map *map, char *line_map)
{
	t_parsing	*node;

	node = malloc(sizeof(t_parsing));
	if (node == NULL)
		return (NULL);
	node->index = 0;
	node->line = line_map;
	node->map = map;
	node->next = list;
	return (node);
}

t_parsing	*clear_node(t_parsing *list)
{
	t_parsing	*node;

	if (list == NULL)
		return (NULL);
	node = list->next;
	free(list);
	return (node);
}

void	display_linked_list(t_parsing *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list)
	{
		while (list && (i < list->map->size_x))
		{
	//		printf("Index LL[%2d] - i = %d - parsing_line = %s\n", list->index, i, list->parsing_line[i]);
//			printf("%3s ", list->parsing_line[i]);
			i++;
		}
		printf("\n");
		list = list->next;
		i = 0;
		j++;
	}
}
