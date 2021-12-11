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
int check_list(t_list *a);
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
    int posi;

    i = *(int *)lst -> content;
	while (lst)
	{
        a = *(int *)lst -> content;
        if (a < i)
        {
            i = a;
            posi = (*size);
        }
        lst = lst -> next;
        (*size)++;
	}
    printf(" \n {%d} ",a);
    (*size)--;
	return (posi);
}


int main(int argc, char **argv)
{
	t_list *a;
    t_list *b;
	t_list *node;
    int size = 1;
    int i = 1;
    int min_position;
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
       return 0;
   }
  // printf("\n chec_list return :  %d  \n",check_list(a));
   if (check_list(a))
        return 0;
    if (check_list(a))
          return 0;
     min_position = min_node(a, &size);
     printf("\n positon of the mini  %d  size of linked %d \n",min_position, size);
    // printf("\n chec_list return :  %d  \n",check_list(a));
    //THE MINIMAL OF NUMBERS 
   instruction(a,min_position,size,b) ;

}