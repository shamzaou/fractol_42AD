# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 19:22:58 by shamzaou          #+#    #+#              #
#    Updated: 2023/09/18 01:20:14 by shamzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = main.c mandelbrot.c julia.c events.c utils.c

OBJ = $(FILES:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

MLX = libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	cd mlx && make
	$(CC) $(OBJ) -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(MLX)
	make clean -sC ./mlx

fclean: clean
	rm -f $(NAME)

re: fclean all
