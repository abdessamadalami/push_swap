/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check_make.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:10:14 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/03 08:43:04 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<unistd.h>

void	error_fun(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	duplicat(t_list *a)
{
	int		nbr;
	t_list	*list;

	nbr = 0;
	while (a)
	{
		nbr = *(int *)a -> content;
		list = a -> next;
		while (list)
		{
			if (*(int *)list ->content == nbr)
				return (1);
			list = list -> next;
		}
		a = a -> next;
	}
	return (0);
}

int	check_argv(char *argv)
{
	int	index;

	index = 0;
	while (argv[index] != '\0')
	{
		if (ft_isdigit(argv[index]) == 0 && (argv[index] != '-'))
			return (0);
		if ((argv[index] == '-' && ft_isdigit(argv[index + 1]) == 0))
			return (0);
		index++;
	}
	return (1);
}

t_list	*check_and_make(int argc, char **argv)
{
	t_list	*a;
	t_list	*node;
	int		i;

	i = 1;
	a = 0;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		if (check_argv(argv[i]) == 0)
			error_fun();
		node = ft_lstnew(f(ft_atoi(argv[i])));
		ft_lstadd_back(&a, node);
		i++;
	}
	if (duplicat(a) || argc == 0)
		error_fun();
	return (a);
}

void	print_f_str(t_list *list)
{
	char	*str1;
	char	*str2;

	while (list != NULL)
	{
		str1 = (char *)list -> content;
		if (list -> next != NULL)
			str2 = list -> next -> content;
		if (str2 != 0 && str1[2] == '\0' && str2[2] == '\0'
			&& (str1[0] == str2[0]) && (str2[0] != 'p') && (str2[1] != str1[1]))
		{
			if (str1[0] == 's' && (str2[1] == 'a' || str2[1] == 'b'))
				write(1, "ss\n", 3);
			else if (str1[0] == 'r' && (str2[1] == 'a' || str2[1] == 'b'))
				write(1, "rr\n", 3);
			list = list -> next;
		}
		else
		{
			ft_putstr_fd(str1, 1);
			write(1, "\n", 1);
		}
	list = list -> next;
	}
}
