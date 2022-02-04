/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:10:06 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/03 06:36:33 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

void	ft_s(t_list *a, char c, t_list **inst)
{
	int	*sawp;

	sawp = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = sawp;
	if (c == 'a')
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("sa")));
	else
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("sb")));
}

void	ft_p(t_list **a, t_list **b, char c, t_list **inst)
{
	t_list	*node;
	t_list	*node1;

	if (c == 'b')
	{
		node = ft_lstnew((*a)-> content);
		node1 = *a;
		ft_lstadd_front(b, node);
		*a = (*a)-> next;
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("pb")));
	}
	else
	{
		node = ft_lstnew((*b)-> content);
		node1 = *b;
		ft_lstadd_front(a, node);
		*b = (*b)-> next;
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("pa")));
	}
	free(node1);
}

void	ft_ra_rb(t_list **a, char c, t_list **inst)
{
	t_list	*node;
	t_list	*list;
	t_list	*l;

	node = ft_lstlast(*a);
	ft_lstadd_front(a, ft_lstnew(node -> content));
	list = *a;
	while ((*a)->next-> next != NULL)
		(*a) = (*a)-> next;
	l = (*a)-> next;
	(*a)-> next = NULL;
	*a = list;
	if (c == 'a')
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rra")));
	else
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rrb")));
	free(l);
}

void	ft_rra_rrb(t_list **a, char c, t_list **inst)
{
	t_list	*node;
	t_list	*list;

	node = ft_lstnew((*a)-> content);
	ft_lstadd_back(a, node);
	list = *a;
	(*a) = (*a)-> next;
	list -> next = NULL;
	if (c == 'a')
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("ra")));
	else
		ft_lstadd_back(inst, ft_lstnew(ft_strdup("rb")));
	free(list);
}

int	check_nbr_list(t_list *a, int med, int *cont)
{
	int	index;
	int	n;

	index = 1;
	while (a)
	{
		n = *(int *) a -> content;
		if (n < med)
		{
			*cont = n;
			return (index);
		}
		index++;
		a = a -> next;
	}
	return (0);
}
