# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laroges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 01:52:45 by laroges           #+#    #+#              #
#    Updated: 2023/11/02 17:56:59 by laroges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
	display.c \
	linked_list.c \
	parsing_map.c \
	values.c \
	events.c \
	drawing.c \
	map.c \
	line.c \
	clean_memory.c \
	isometry.c \
	split.c \
	menu.c \
	colors.c \
	colors_convert.c \
	colors_utils.c \

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lX11 -lXext

OBJ =	$(SRC:.c=.o)

NAME =	./fdf

NAMELIBFT =	libft.a

NAMEMLX =	libmlx_Linux.a

NAMEGNL =	get_next_line.a

INCLUDELIBFT =	./libft/

INCLUDEMLX =	./minilibx-linux/

INCLUDEGNL =	./getnextline/

all: $(NAME)

%.o : %.c fdf.h
	$(CC) $(CFLAGS) -I $(INCLUDELIBFT) -I $(INCLUDEMLX) -I $(INCLUDEGNL) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx-linux
	make -C getnextline
	cp $(INCLUDELIBFT)$(NAMELIBFT) .
	cp $(INCLUDEMLX)$(NAMEMLX) .
	cp $(INCLUDEGNL)$(NAMEGNL) .
	$(CC) $(CFLAGS) $(OBJ) -I $(INCLUDELIBFT) $(NAMELIBFT) -I $(INCLUDEGNL) $(NAMEGNL) $(NAMEMLX) $(MLXFLAGS) -o $(NAME) -lm

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
