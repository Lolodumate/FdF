/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:19:29 by laroges           #+#    #+#             */
/*   Updated: 2023/10/24 05:39:36 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 */

#include "get_next_line_bonus.h"

t_gnl	*insert_stack(t_gnl *stash, char *buf, size_t ret)
{
	t_gnl		*element;
	size_t		tmp;
	size_t		i;

	tmp = 0;
	i = 0;
	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->buffer = malloc(sizeof(char) * ret + 1);
	if (element->buffer == NULL)
	{
		free(element);
		return (NULL);
	}
	while (i < (ret + 1))
		element->buffer[i++] = 0;
	ft_strcpy(element->buffer, buf);
	if (stash != NULL)
		tmp = stash->len;
	element->ret = ret;
	element->len = tmp + ret;
	element->next = stash;
	return (element);
}

t_gnl	*clear_stack(t_gnl *stash)
{
	t_gnl	*element;

	if (stash == NULL)
		return (NULL);
	element = stash->next;
	stash->len = 0;
	stash->ret = 0;
	free(stash->buffer);
	free(stash);
	return (element);
}

char	*ft_put_stash(char *str_stash, t_gnl *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = stash->len - stash->ret;
	str_stash[stash->len] = '\0';
	if (stash == NULL)
		return (0);
	while (stash != NULL)
	{
		while (j < stash->ret)
		{
			str_stash[i + j] = stash->buffer[j];
			j++;
		}
		stash = clear_stack(stash);
		if (stash != NULL)
			i -= stash->ret;
		j = 0;
	}
	return (str_stash);
}

t_gnl	*ft_read_line(int fd, t_gnl *stash, char *str_stash)
{
	int		ret;
	char	*buf;

	ret = 0;
	if (str_stash != NULL && str_stash[0] != '\0')
	stash = insert_stack(stash, str_stash, ft_strlen_gnl(str_stash));
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	while (ret < BUFFER_SIZE)
		buf[ret++] = 0;
	while (!ft_strchr_gnl(buf, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (0);
		}
		buf[ret] = '\0';
		stash = insert_stack(stash, buf, ret);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	t_gnl		*stash;
	static char	*str_stash[4096];
	char		*line;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash, str_stash[fd]);
	if (!(stash == NULL) && !(ft_strchr_gnl(stash->buffer, '\n')))
		stash = clear_stack(stash);
	free(str_stash[fd]);
	if (stash == NULL)
		return (NULL);
	str_stash[fd] = malloc(sizeof(char) * stash->len + 1);
	if (str_stash[fd] == NULL)
		return (NULL);
	str_stash[fd] = ft_put_stash(str_stash[fd], stash);
	if (str_stash[fd] == NULL)
		return (NULL);
	line = ft_put_line(str_stash[fd]);
	str_stash[fd] = ft_cut_stash(str_stash[fd]);
	return (line);
}
