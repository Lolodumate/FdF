# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laroges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 01:52:45 by laroges           #+#    #+#              #
#    Updated: 2023/10/24 06:00:50 by laroges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \

CC =	gcc

CFLAGS = -Wall -Werror -Wextra -lmlx 

OBJ =	$(SRC:.c=.o)

NAME =	./fdf

NAMELIBFT =	libft.a

NAMEMLX =	libmlx_Linux.a

NAMEGNL =	get_next_line

INCLUDELIBFT =	./libft/

INCLUDEMLX =	./minilibx-linux/

INCLUDEGNL =	./getnextline/

all: $(NAME)

%.o : %.c fdf.h
	$(CC) $(CFLAGS) -I $(INCLUDELIBFT) -I $(INCLUDEMLX) -I $(INCLUDEGNL) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx-linux
	cp $(INCLUDELIBFT)$(NAMELIBFT) .
	cp $(INCLUDEMLX)$(NAMEMLX) .
	$(CC) $(CFLAGS) $(OBJ) -I $(INCLUDELIBFT) $(NAMELIBFT) -I $(INCLUDEMLX) $(NAMEMLX) -o $(NAME)

clean:
	make clean -C libft
	make clean -C minilibx-linux
	make clean -C getnextline
	rm -f $(OBJ) $(NAMELIBFT) $(INCLUDELIBFT)$(NAMELIBFT)
	rm -f $(OBJ) $(NAMEMLX) $(INCLUDEMLX)$(NAMEMLX)
	rm -f $(OBJ) $(NAMEGNL) $(INCLUDEGNL)$(NAMEGNL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
