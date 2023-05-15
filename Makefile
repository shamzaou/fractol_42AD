# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 19:22:58 by shamzaou          #+#    #+#              #
#    Updated: 2023/05/15 12:12:37 by shamzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = main.c mandelbrot.c julia.c events.c utils.c

OBJ = $(FILES:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

MLX = libmlx.a

$(NAME): $(OBJ)
	cd mlx && make
	$(CC) $(OBJ) -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

.PHONY: all clean fclean re


clean:
	rm -f $(OBJ)
	rm -f $(MLX)
	make clean -sC ./mlx


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re