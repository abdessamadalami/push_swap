/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:08:56 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/03 08:12:42 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	error_fun(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	char_instruction(t_list **a, t_list **b,
char c, void (f_inst)(t_list**))
{
	if (c == 'r' || c == 's')
	{
		f_inst(a);
		f_inst(b);
	}
	else if (c == 'a')
		f_inst(a);
	else if (c == 'b')
		f_inst(b);
	else
		error_fun();
}

void	instructions_fun(t_list **a, t_list **b, char *instruction)
{
	if (instruction[0] == 's' && instruction[2] == '\n')
		char_instruction(a, b, instruction[1], ft_s);
	else if (instruction[0] == 'r' && instruction[2] == '\n')
		char_instruction(a, b, instruction[1], ft_rra_rrb);
	else if (instruction[0] == 'r' && instruction[1] == 'r')
		char_instruction(a, b, instruction[2], ft_ra_rb);
	else if (instruction[0] == 'p' && instruction[2] == '\n'
		&& (instruction[1] == 'a' || instruction[1] == 'b'))
		ft_p(a, b, instruction[1]);
	else
		error_fun();
}

void	result_function(int n, t_list *b)
{
	if (n == 1 && b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		k;
	int		i;
	char	tab[4];

	i = 0;
	k = 1;
	a = check_and_make(argc, argv);
	while (k != 0)
	{
		k = read(0, &tab[i], 1);
		if (tab[i] == '\n' && i < 4)
		{
			tab[i + 1] = '\0';
			instructions_fun(&a, &b, tab);
			i = -1;
		}
		if (i >= 4)
			error_fun();
		i++;
	}
	result_function(check_list(a), b);
	ft_lstclear(&a, del);
}
