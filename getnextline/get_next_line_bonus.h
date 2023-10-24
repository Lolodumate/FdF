/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:15:42 by laroges           #+#    #+#             */
/*   Updated: 2023/10/24 04:57:36 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_gnl
{
	int				len;
	int				ret;
	char			*buffer;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
char	*ft_cut_stash(char *str_stash);
char	*ft_put_line(char *str_stash);
char	*ft_put_stash(char *str_stash, t_gnl *stash);
char	*ft_strchr_gnl(char *s, char c);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlen_gnl(char *str);
t_gnl	*ft_read_line(int fd, t_gnl *stash, char *str_stash);
t_gnl	*insert_stack(t_gnl *element, char *buffer, size_t ret);
t_gnl	*clear_stack(t_gnl *stash);

#endif
