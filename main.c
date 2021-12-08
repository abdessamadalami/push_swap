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
void ft_pb(t_list **b,t_list **a);
int *f(int a)
{
    int *ptr;
	ptr = (int *)malloc(4);
	*ptr = a;
	return ptr;
}
int main(int argc, char **argv)
{
	t_list *a;
    t_list *b;
	t_list *node;

    int i = 1;
    while (i < argc)
     {
        node = ft_lstnew(f(ft_atoi(argv[i])));
        ft_lstadd_back(&a,node);
        i++;
    }
   if (argc==1)
   {
       printf("                     (<>|<>)\n");
       printf("                      ( O ) ");

   }
     print_f(a);
   
   if (*(int *)a -> content > *(int *)a->next->content)
            ft_sa(a);
   print_f(a);
   printf("a");
   i = 0;
   while (i < argc /2 )
   {
       ft_pb(&b,&a);
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
    // ft_rra_rrb(&a);
    // print_f(a);
    // ft_rra_rrb(&a);
    // print_f(a);
    // ft_rra_rrb(&a);
    // print_f(a);

}