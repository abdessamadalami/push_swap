/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:10:21 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/02 15:23:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<unistd.h>

void	del(void *ptr)
{
	free(ptr);
}

int	*f(int a)
{	
	int	*ptr;

	ptr = malloc(4);
	if (ptr == NULL)
		return (0);
	*ptr = a;
	return (ptr);
}

int	max_node(t_list *lst, int *content)
{
	int	i;
	int	index;
	int	a;
	int	position;

	position = 1;
	index = 1;
	i = *(int *)lst -> content;
	while (lst)
	{
		a = *(int *)lst -> content;
		if (a > i)
		{
			i = a;
			position = index;
		}
		lst = lst -> next;
		index++;
	}
	*content = i;
	return (position);
}

int	min_node(t_list *lst, int *size)
{
	int	i;
	int	a;
	int	position;
	int	index;

	index = 1;
	*size = 1;
	position = 1;
	i = *(int *)lst -> content;
	while (lst)
	{
		a = *(int *)lst -> content;
		if (a < i)
		{
			i = a;
			position = index;
		}
	lst = lst -> next;
	index++;
	}
	*size = i;
	return (position);
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
