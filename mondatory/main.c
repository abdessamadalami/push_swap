/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:05:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/03 09:34:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<unistd.h>
#include"libft.h"

// this fun return 0 or index of it (numbre) 
void	pro_link(t_list **a, t_list **b, t_list **inst, int t)
{
	int	med;
	int	cont;
	int	pa_pb[2];

	pa_pb[0] = 0;
	pa_pb[1] = 0;
	med = buble_list(*a);
	while (1)
	{
		pa_pb[0] = check_nbr_list (*a, med, &cont);
		if ((*a)-> next == NULL || pa_pb[0] == 0)
			return ;
		if (*b != NULL && t == 1)
			pa_pb[1] = get_the_psition(*b, cont, ft_lstsize(*b));
		nbr_in_top_of_two(a, b, pa_pb, inst);
		ft_p(a, b, 'b', inst);
	}
}

void	countswaps(int a_count, int *a)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	while (i < a_count)
	{
		j = 0;
		while (j < a_count - 1)
		{
			if (a[j] > a[j + 1])
			{
				nbr = a[j];
				a[j] = a[j + 1];
				a[j + 1] = nbr;
			}
			j++;
		}
		i++;
	}
}

int	buble_list(t_list *a)
{
	int	n1;
	int	i;
	int	k;
	int	*arr;

	i = 0;
	k = 3;
	arr = malloc(ft_lstsize(a) * sizeof(int));
	while (a)
	{
		n1 = *(int *)a -> content;
		arr[i++] = n1;
		a = a -> next;
	}
	countswaps(i, arr);
	if (i > 100)
		k = 8;
	free(arr);
	return (arr[i / (k)]);
}

void	empty_b(t_list *a, t_list *b, t_list *inst)
{
	if (ft_lstsize(inst) == 1)
	{
		ft_putstr_fd(inst -> content, 1);
		write(1, "\n", 1);
	}	
	else
		print_f_str(inst);
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	ft_lstclear(&inst, del);
}

int	main(int argc, char **argv)
{	
	t_list	*a;
	t_list	*b;
	t_list	*inst;
	int		t;
	int		pa_pb[2];

	inst = 0;
	t = 0;
	a = check_and_make(argc, argv);
	while (ft_lstsize(a) > 3 && check_list (a) != 1)
		pro_link(&a, &b, &inst, 1);
	if (ft_lstsize(a) == 2 && check_list(a) != 1)
		ft_s(a, 'a', &inst);
	else if (check_list(a) != 1)
		tree_int(&a, 'a', &inst);
	while (b)
	{
		pa_pb[0] = 0;
		pa_pb[1] = max_node(b, &t);
		nbr_in_top_of_two(&a, &b, pa_pb, &inst);
		ft_p(&a, &b, 'a', &inst);
	}
	empty_b(a, b, inst);
}
//system("leaks push_swap");