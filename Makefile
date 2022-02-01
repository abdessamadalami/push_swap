# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2021/11/17 10:58:30 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = mondatory/ft_inst.c mondatory/main.c mondatory/print_f.c mondatory/sorting.c
BS = bonus/ft_inst.c bonus/main_b.c bonus/print_f.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
all: lib
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o push_swap 
lib:
	 cd libft && make all && make bonus
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
bonus: lib
	$(CC) $(CFLAGS) $(BS) libft/libft.a -o checker
clean: 
	cd libft && make clean
fclean:clean
	cd libft && make fclean
re:fclean ; all bonus
