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
void ft_sa(t_list *a);
void ft_pa(t_list **b,t_list **a);
void ft_ra_rb(t_list **a);
void ft_rra_rrb(t_list **a);
int *f(int a)
{
    int *ptr;
	ptr = (int *)malloc(4);
	*ptr = a;
	return ptr;
}

// void print_f(t_list *a) {

//    t_list *ptr = a;
//    printf("\n[ ");

//    //start from the beginning
//    while(ptr)
//    {
//       printf("( %d ) ",*(int *)ptr -> content);
//       ptr = ptr->next;
//    }
//    printf(" ]");
// }

int main()
{
	t_list *a;
    t_list *b;
	t_list *node;
    t_list *n;
	int *ptr;
    int tab1[4] = {1, 12, 32, 4};
          int tab = 1337;
        a = ft_lstnew(f(tab));
    int i = 0;
    while (i<4) {
        node = ft_lstnew(f(tab1[i]));
        ft_lstadd_front(&a,node);
        i++;
    }
   print_f(a);
   print_f(b);
//    printf("\n sa ");
//    ft_sa(b);
//    ft_sb(a);
//    print_f(b);
//    print_f(a);
   //ft_ra_rb(&a);
   //print_f(a);
    ft_rra_rrb(&a);
    print_f(a);
    ft_rra_rrb(&a);
    print_f(a);
    ft_rra_rrb(&a);
    print_f(a);

}