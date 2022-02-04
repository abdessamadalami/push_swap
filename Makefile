# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/02/03 09:45:26 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mondatory/ft_inst.c mondatory/main.c mondatory/print_check_make.c mondatory/sorting.c mondatory/tools_functions.c
BS = bonus/ft_inst.c bonus/main_b.c bonus/print_f.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
all: lib
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME) 
lib:
	 cd libft && make all && make bonus
bonus: lib
	$(CC) $(CFLAGS) $(BS) libft/libft.a -o checker
clean: 
	cd libft && make clean
fclean:clean
	rm checker ; rm push_swap ; cd libft && make fclean
re:
	make fclean && make all && make bonus
