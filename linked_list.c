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

t_parsing	*insert_node(t_parsing *list, t_map *map, char *line_map)
{
	t_parsing	*node;

	node = malloc(sizeof(t_parsing));
	if (node == NULL)
		return (NULL);
	node->line = line_map;
	node->map = *map;
	node->next = *list;
	return (node);
}

t_parsing	*clear_node(t_parsing *list)
{
	t_parsing	*node;

	node = list->next;
	free(list->line);
	free(list);
	return (node);
}
