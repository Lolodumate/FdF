/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:13:24 by laroges           #+#    #+#             */
/*   Updated: 2023/11/02 17:07:19 by laroges          ###   ########.fr       */
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

int	values_abs(int n)
{
	if (n >= 0)
		return (n);
	return (n * -1);
}
