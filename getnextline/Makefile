# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laroges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 03:47:58 by laroges           #+#    #+#              #
#    Updated: 2023/10/30 14:39:19 by laroges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	get_next_line.c \
	get_next_line_utils.c \

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

OBJ =	$(SRC:.c=.o)

NAMEGNL = get_next_line.a

all: $(NAMEGNL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAMEGNL): $(OBJ)
	ar rc $(NAMEGNL) $(OBJ)
	ranlib $(NAMEGNL)

clean:
	rm -f $(OBJ) $(NAMEGNL)

fclean: clean
	fm -f $(NAMEGNL)

re: fclean all

.PHONY : all clean fclean re
