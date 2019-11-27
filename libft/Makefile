# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soyster <soyster@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 15:11:10 by soyster           #+#    #+#              #
#    Updated: 2019/11/27 17:57:36 by soyster          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putstr_fd.c ft_sqr.c ft_sqrt.c ft_atoi.c ft_strcat.c ft_bzero.c \
	  ft_strchr.c ft_free.c	ft_strclr.c ft_is_negative.c ft_strcmp.c \
	  ft_isalnum.c ft_strcpy.c ft_isalpha.c ft_strdel.c ft_isascii.c \
	  ft_strdup.c ft_isdigit.c ft_strequ.c ft_isprint.c	ft_striter.c \
	  ft_iterative_factorial.c ft_striteri.c ft_itoa.c ft_strjoin.c ft_lstadd.c \
	  ft_strlcat.c ft_lstdel.c ft_strlen.c ft_lstdelone.c ft_strmap.c \
	  ft_lstiter.c ft_strmapi.c ft_lstmap.c	ft_strncat.c ft_lstnew.c ft_strncmp.c \
	  ft_memalloc.c ft_strncpy.c ft_memccpy.c ft_strnequ.c ft_memchr.c ft_strnew.c \
	  ft_memcmp.c ft_strnstr.c ft_memcpy.c ft_strrchr.c ft_memdel.c ft_strsplit.c \
	  ft_memmove.c ft_strstr.c ft_memset.c ft_strsub.c ft_putchar.c ft_strtrim.c \
	  ft_putchar_fd.c ft_swap.c ft_putendl.c ft_tolower.c ft_putendl_fd.c ft_toupper.c \
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c get_next_line.c ft_destroy_int_arr.c \
	  ft_destroy_string_arr.c ft_getnbr.c ft_len_arr.c

HEADER = ../../includes/

OBJECTS = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	@gcc -Wall -Werror -Wextra -I $(HEADER) -c $<

.PHONY: clean fclean re

clean:
	@/bin/rm -f $(OBJECTS)

fclean:	clean
	@/bin/rm -f $(NAME)

re: fclean all
