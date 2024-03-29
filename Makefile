# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 19:22:58 by shamzaou          #+#    #+#              #
#    Updated: 2023/09/28 09:25:35 by shamzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = main.c mandelbrot.c julia.c events.c utils.c utils2.c ft_atof.c

OBJ = $(FILES:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

MLX = libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	cd mlx && make
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(MLX)
	make clean -sC ./mlx

fclean: clean
	rm -f $(NAME)

re: fclean all
