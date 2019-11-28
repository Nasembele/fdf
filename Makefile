# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soyster <soyster@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 17:13:33 by soyster           #+#    #+#              #
#    Updated: 2019/11/28 17:36:26 by soyster          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = sources

SRC = bresenham.c keyboard.c main.c map.c projections.c validation.c window.c 

HEADER = ./includes

FLAG =  -Wall -Wextra -Werror -I ./resourses/minilibx -framework OpenGl -framework AppKit -lmlx

OBJECTS = $(addprefix $(SRC_DIR)/, bresenham.o keyboard.o main.o map.o \
		projections.o validation.o window.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make re -C ./resourses/libft
	@gcc -o  $(NAME) $(FLAG) -L./resourses/libft -lft -I $(HEADER) $(OBJECTS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc -c -I ../resourses/minilibx $^ -I $(HEADER) -o $@

.PHONY: clean fclean re

clean: 
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./resourses/libft
	
fclean:	clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./resourses/libft
	
re: fclean all
