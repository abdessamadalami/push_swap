#include "libft.h"
#include <stdio.h>

void miniment_in_top(t_list **a, int min_position, int size)
{
    if (size == min_position && min_position != 1)
        ft_ra_rb(a);
    else if ((min_position <= size/2) && min_position != 1)
   {
       while (min_position >= 1)
       {
           if (min_position == 2)
           {
               ft_sa(*a);
               break;
           }
            ft_rra_rrb(a);
           min_position--;
       }
   }
   else
   {
        while ((min_position > size/2) && min_position != 1)
       {
           ft_ra_rb(a);
           if (min_position == size )
                break; 
            min_position++;
       }
   }
}

void tree_int(t_list **a)
{
  // printf("i M GERE");
    int n1;
    int n2;
    int n3;
    n1 = *(int *) (*a) -> content;
    n2 = *(int *)((*a) -> next) -> content;
    n3 = *(int *)(((*a) -> next -> next)) -> content;
    //printf("______%d %d %d ",n1 ,n2 ,n3);
    if ((n1 > n2 && n3 < n1 && n2 > n3 ))
    {
        ft_sa(*a);
        ft_ra_rb(a);
    }
    else if (n1 > n2 && n1 < n3)
        ft_sa(*a);
    else if (n1 > n2 && n1 > n3)
        ft_rra_rrb(a);
    else if (n1 < n2 && n2 > n3)
        {
            ft_ra_rb(a);
            ft_sa(*a);
        }
    // print_f(*a);
}

void instruction(t_list **a,int min_position,int size,t_list **b)
{
    int index;
    int content;

    index = 0;
  if (size == 3)
  {
      tree_int(a);
      return;
  }
    int s=size;
  while (1)
   {
            miniment_in_top(a, min_node(*a,&size), size);      
           //printf(" \n %d",min_node(*a,&size));
            if (!check_list(*a)){
                ft_pb(a,b);
            }
            if(*b != NULL)
                content = *(int *)ft_lstlast(*b) ->content;
            if ( *b != NULL && check_list(*a) && content < *(int *)(*a) -> content)
            {
                s = 4;
            }
            s--;
   // printf("________%d________\n\n",ft_lstsize(*a));
    //    print_f(*b);
       if (s == 3)
       {
           //printf("++d++ %d \n\n\n",size);
          
           tree_int(a);
           // print_f(*a);
           while(*b != NULL && *a != NULL)
           {
               ft_pa(a,b);
           }
          // print_f(*a);
           break;
       } 
       index++;
       
   }
   
}