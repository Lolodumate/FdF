# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laroges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 03:47:58 by laroges           #+#    #+#              #
#    Updated: 2023/10/24 05:51:40 by laroges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

OBJ =	$(SRC:.c=.o)

NAMEGNL = get_next_line

INCLUDEGNL = ./getnextline/

%.o: %.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -I $(INCLUDEGNL) -c $< -o $(<:.c=.o)

$(NAMEGNL): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAMEGNL)

clean:
	rm -f $(OBJ) $(NAMEGNL)

fclean: clean
	fm -f $(NAMEGNL)

re: fclean all

.PHONY : all clean fclean re
