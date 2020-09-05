# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldediu <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 12:40:44 by ldediu            #+#    #+#              #
#    Updated: 2019/11/11 17:12:08 by ldediu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractal

CC			= gcc

FLAG		= -Wall -Wextra -Werror

FRAMEWORK	= -framework OpenGL -framework AppKit

INCL		= -I fractal.h -L ./libft -lft

MLX			= -I ./minilibx_macos -L ./minilibx_macos -lmlx

SRC			= 	main.c draw.c keys.c mouse.c paint.c
				
OBJ			= ${SRC:.c=.o}

GREEN		= \033[0;32m
RESET		= \033[0m

all: $(NAME)

$(NAME): lib $(OBJ)
		@$(MAKE) -sC ./minilibx_macos
		@$(CC) $(FLAG) $(INCL) $(MLX) $(FRAMEWORK) $(OBJ) -o $(NAME)
		@echo "\n$(NAME): $(GREEN) compile success$(RESET)"

lib:
	make -C libft

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@$(MAKE) -sC ./minilibx_macos clean
	@echo "\n$(NAME): $(GREEN) clean$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@$(MAKE) -sC ./minilibx_macos clean
	@echo "\n$(NAME): $(GREEN) fclean$(RESET)"


re: fclean all

.PHONY: all, clean, fclean, re
