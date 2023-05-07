# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 19:22:58 by shamzaou          #+#    #+#              #
#    Updated: 2023/05/06 23:22:50 by shamzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =   main.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = 

MLX = libmlx.dylib


%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@


all: $(NAME)


$(NAME): $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


$(MLX):
	@make -sC ./mlx


clean:
	@rm -f $(OBJ)
	@rm -f $(MLX)
	@make clean -sC ./mlx


fclean: clean
	@rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re