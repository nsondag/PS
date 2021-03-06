# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsondag <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 12:33:09 by nsondag           #+#    #+#              #
#    Updated: 2019/01/23 02:36:00 by nsondag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push.c swap.c reverse_rotate.c rotate.c shift.c\
	  parser.c\
	  ft_issorted.c get_key_values.c quick_sort.c small_sort.c\

SRC1 = push_swap.c

SRC2 = visualization.c checker.c

NAME1 = push_swap

NAME2 = checker

FLAGS = -Wall -Wextra -Werror

FRAME = -framework OpenGL -framework AppKit

.PHONY:  all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1):
	@make -C libft
	@gcc -o $(NAME1) $(FLAGS) $(SRC) $(SRC1) libft/libft.a

$(NAME2):
	@make -C libft
	@make -C mlx
	@gcc -o $(NAME2) $(FLAGS) -I mlx -g -L mlx -lmlx $(FRAME) $(SRC) $(SRC2)\
				libft/libft.a
clean:
	@make clean -C libft
	@make clean -C mlx

fclean: clean 
	@make fclean -C libft
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all
