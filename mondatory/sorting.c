/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:10:18 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/03 08:38:28 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// why plus one ? the end of stack beacame first
int	position_content(t_list *list, int nbr, int *min_content, int *max_content)
{
	int	min_position;
	int	max_position;

	min_position = min_node(list, min_content);
	max_position = max_node(list, max_content);
	if (nbr < *min_content && nbr < *max_content)
		return (min_position + 1);
	else if (nbr > *max_content && nbr > *max_content)
		return (max_position);
	return (0);
}

int	get_the_psition(t_list *b, int nbr, int size)
{
	int	i;
	int	n1;
	int	n2;
	int	max_content;
	int	min_content;

	i = 1;
	if (position_content(b, nbr, &min_content, &max_content) != 0)
		return (position_content(b, nbr, &min_content, &max_content));
	while (size - 1)
	{
		n1 = *(int *)b -> content;
		n2 = *(int *)b-> next -> content;
		if ((n1 < nbr && n2 > nbr) && (n1 != min_content))
			return (i + 1);
		if (n1 > nbr && n2 < nbr)
			return (i + 1);
		b = b -> next;
		i++;
		size--;
	}
	return (1);
}

int	numbre_of_move(int *index_a, int size, int p, int type)
{
	if (type == 0)
	{
		*index_a = 1;
		return (size - p + 1);
	}
	else
	{
		*index_a = 1;
		return (size - p + 1);
	}
}
// if (index_a == 1 && pa >= 1)
// 				ft_ra_rb(a,'a', inst); // rra 
// 		if (index_a == 0 && pa > 1)
// 				ft_rra_rrb(a,'a', inst); // ra
// 		if (index_b == 1 && pb >= 1)
// 				ft_ra_rb(b,'b', inst); // rr
// 		if (index_b == 0 && pb > 1)
// 				ft_rra_rrb(b, 'b', inst); // rb

void	nbr_in_top_of_two(t_list **a, t_list **b, int *pa_pb, t_list **inst)
{
	int	index_a;
	int	index_b;

	index_a = 0;
	index_b = 0;
	if (pa_pb[0] > (ft_lstsize(*a) + 1) / 2)
		pa_pb[0] = numbre_of_move(&index_a, ft_lstsize(*a), pa_pb[0], 0);
	if (pa_pb[1] > (ft_lstsize(*b) + 1) / 2)
		pa_pb[1] = numbre_of_move(&index_b, ft_lstsize(*b), pa_pb[1], 1);
	while (pa_pb[0] >= 0 || pa_pb[1] >= 0)
	{
		if (index_a == 1 && pa_pb[0] >= 1)
			ft_ra_rb(a, 'a', inst);
		if (index_a == 0 && pa_pb[0] > 1)
			ft_rra_rrb(a, 'a', inst);
		if (index_b == 1 && pa_pb[1] >= 1)
			ft_ra_rb(b, 'b', inst);
		if (index_b == 0 && pa_pb[1] > 1)
			ft_rra_rrb(b, 'b', inst);
		pa_pb[1]--;
		pa_pb[0]--;
	}
}

void	tree_int(t_list **a, char c, t_list **inst)
{
	int	p_max;
	int	nbr1;

	p_max = max_node(*a, &nbr1);
	if (p_max == 1)
		ft_rra_rrb(a, c, inst);
	else if (p_max == 2)
		ft_ra_rb(a, c, inst);
	if (check_list(*a) == -1)
		ft_s(*a, c, inst);
}
