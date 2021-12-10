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

   }
  // printf("\n chec_list return :  %d  \n",check_list(a));
   if (check_list(a))
        return 0;

     print_f(a);
     min_position = min_node(a, &size);
     printf("\n positon of the mini  %d  size of linked %d \n",min_position, size);
     printf("\n chec_list return :  %d  \n",check_list(a));
     ft_ra_rb(&a);
     print_f(a);
     ft_sa(a);
     print_f(a);
     ft_ra_rb(&a);
     print_f(a);
    printf("\n chec_list return :  %d  \n",check_list(a));
//    if ((min_position > size/2))
//    {
//        while ((min_position >= size/2))
//        {
//            ft_ra_rb(&a);
//            min_position++;
//            printf("ra\n");
//            if (min_position == size)
//            {
//                printf("ra\n");
//                ft_ra_rb(&a);
//                break;
//            }
//        }
//    }
//    else
//    {
//         while ((min_position <= size/2))
//        {
//            printf("\n rrb %d",min_position);
//            ft_rra_rrb(&a);
//            min_position--;
//            if (min_position == 1)
//                break; 
//        }
//    }  
//    if (*(int *)a -> content > *(int *)a->next->content)
//             ft_sa(a);
//    print_f(a);
//    printf("a");
//    i = 0;
//    while (i < argc /2 )
//    {
//        ft_pb(&b,&a);
//        i++;
//    }
//      print_f(a);
//      print_f(b);
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