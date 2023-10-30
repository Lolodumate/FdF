/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:38:08 by laroges           #+#    #+#             */
/*   Updated: 2023/10/30 14:27:20 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	size;

	size = 0;
	if (str == NULL)
		return (0);
	while (str[size])
		size++;
	return (size);
}

char	*ft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_cut_stash(char *str_stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str_stash[i] && str_stash[i] != '\n')
		i++;
	if (!str_stash[i])
	{
		free(str_stash);
		return (NULL);
	}
	i++;
	tmp = malloc(sizeof(char) * (ft_strlen_gnl(str_stash) - i + 1));
	if (tmp == NULL)
		return (NULL);
	while (str_stash[i])
		tmp[j++] = str_stash[i++];
	tmp[j] = '\0';
	free(str_stash);
	return (tmp);
}

char	*ft_put_line(char *str_stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (str_stash == NULL)
		return (NULL);
	while (str_stash[i] && str_stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (line == NULL)
	{
		free(str_stash);
		return (NULL);
	}
	while (j <= i)
	{
		line[j] = str_stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
