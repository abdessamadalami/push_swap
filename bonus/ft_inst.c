/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:09:50 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/02 14:09:51 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

void	ft_s(t_list **a)
{
	int	*sawp;

	if (ft_lstsize(*a) < 2)
		return ;
	sawp = (*a)-> content;
	(*a)-> content = (*a)-> next -> content;
	(*a)-> next -> content = sawp;
}

void	ft_p(t_list **a, t_list **b, char c)
{
	t_list	*node;
	t_list	*node1;

	node1 = 0;
	if (c == 'b')
	{
		node = ft_lstnew((*a)-> content);
		node1 = *a;
		ft_lstadd_front(b, node);
		if ((*a)-> next != NULL)
			*a = (*a)-> next;
	}
	else if (c == 'a')
	{
		if ((*b) == NULL)
			return ;
		node = ft_lstnew((*b)-> content);
		node1 = *b;
		ft_lstadd_front(a, node);
		if ((*b) != NULL)
			*b = (*b)-> next;
	}
	free(node1);
}

void	ft_ra_rb(t_list **a)
{
	t_list	*node;
	t_list	*list;
	t_list	*l;

	if (ft_lstsize(*a) < 2)
		return ;
	node = ft_lstlast(*a);
	ft_lstadd_front(a, ft_lstnew(node -> content));
		list = *a;
	while ((*a)-> next -> next != NULL)
		(*a) = (*a)-> next;
	l = (*a)-> next;
	(*a)-> next = NULL;
	*a = list;
	free(l);
}

void	ft_rra_rrb(t_list **a)
{
	t_list	*node;
	t_list	*list;

	if (ft_lstsize(*a) < 2)
		return ;
	node = (ft_lstnew((*a)-> content));
	ft_lstadd_back(a, node);
	list = *a;
	(*a) = (*a)-> next;
	list -> next = NULL;
	free(list);
}

int	check_list(t_list *a)
{
	int	index;
	int	i;

	index = *(int *)a -> content;
	i = 0;
	while (a)
	{
		if (index > *(int *)a -> content)
			return (-1 * i);
		index = *(int *)a ->content;
		a = a -> next;
		i++;
	}
	return (1);
}
