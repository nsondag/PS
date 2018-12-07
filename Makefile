# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsondag <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 12:33:09 by nsondag           #+#    #+#              #
#    Updated: 2018/12/07 16:11:17 by nsondag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push.c\
	  swap.c\
	  reverse_rotate.c\
	  rotate.c\
	  shift.c\
	  ft_issorted.c\
	  check_validity.c\
	  quick_sort.c\
	  median.c\
	  small_sort.c\
	  get_extrema.c\
	  divide.c\
	  parser.c\

SRC1 = main.c visualization.c\

SRC2 = main_checker.c

NAME1 = push_swap

NAME2 = checker

FLAGS = -Wall -Wextra -Werror

FRAME = -framework OpenGL -framework AppKit

.PHONY:  all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1):
	@make re -C libft
	@gcc -o $(NAME1) $(FLAGS) -I mlx -g -L mlx -lmlx\
		$(FRAME) $(SRC) $(SRC1) libft/libft.a

$(NAME2):
	@make re -C libft
	@gcc -o $(NAME2) $(FLAGS) $(SRC)  $(SRC2) libft/libft.a

clean:
	@make clean -C libft

fclean: clean 
	@make fclean -C libft
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all
