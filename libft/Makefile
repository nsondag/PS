# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsondag <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 21:09:08 by nsondag           #+#    #+#              #
#    Updated: 2018/12/12 15:01:38 by nsondag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_memset.c\
	  ft_bzero.c\
	  ft_strnew.c\
	  ft_atoi.c\
	  ft_isdigit.c\
	  ft_strsplit.c\
	  word_count.c\
	  ft_strcmp.c\
	  get_next_line.c\
	  ft_strlen.c\
	  ft_strjoin.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strsub.c\
	  ft_itoa.c\

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

INCL = libft.h

OBJ := $(SRC:%.c=%.o)
 
.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib libft.a

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
