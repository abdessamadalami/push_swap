/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:05:37 by ael-oual          #+#    #+#             */
/*   Updated: 2021/12/06 11:05:43 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include<unistd.h>
// void ft_sa(t_list *a);
// void ft_pa(t_list **b,t_list **a);
// void ft_ra_rb(t_list **a);
// void ft_rra_rrb(t_list **a);
// void ft_pb(t_list **b,t_list **a);
// int check_list(t_list *a);


int *f(int a)
{
    int *ptr;
	ptr = (int *)malloc(4);
	*ptr = a;
	return ptr;
}
int	min_node(t_list *lst,int *size)
{
	t_list	*list;
    int i;
    int a;
    int position;
    *size = 1;
     
    position = 1;
    i = *(int *)lst -> content;
	while (lst)
	{
        a = *(int *)lst -> content;
        if (a < i)
        {
            i = a;
            position = (*size);
        }
        lst = lst -> next;
        (*size)++;
	}
    (*size)--;
	return (position);
}

int duplicat(t_list *a)
{
    int index;
    int nbr;
    t_list *list;

    
    index = 0;
    nbr = 0;
    while (a)
    {
       nbr = *(int *)a -> content;
       list = a -> next;
        while (list)
        {
            if (*(int *)list ->content == nbr)
            {
                return 1;
            }
            list = list -> next;
        }
        a = a->next;
    }
    return 0;
    
}
int main(int argc, char **argv)
{
	t_list *a;
    t_list *b;
	t_list *node;
    t_list *inst;
    int i = 1;
    int min_position;
    int size = 1;
    int sum;
    sum = 0;
    while (i < argc)
     {
        sum +=ft_atoi(argv[i]);
        node = ft_lstnew(f(ft_atoi(argv[i])));
        ft_lstadd_back(&a,node);
        i++;
    }
   if (duplicat(a) || argc == 1)
    {
        write(1, "Error", 5);//letters
        return (0);
    }
   if (check_list(a))
        return 0;
     min_position = min_node(a, &size);
  instruction(&a, size, &b, sum,&inst);
 while (b)
 {
 if (max_node(b,&size) > 1)
    {
       nbr_in_top(&b, max_node(b, &size), ft_lstsize(b), 'b', &inst);
    }
     ft_p(&a,&b,'a',&inst);
 }
 printf("\n  (%d)",check_list(a));
  print_f(a);
  printf("\n  (%d)",ft_lstsize(a));

}