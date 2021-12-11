#include "libft.h"
#include <stdio.h>

void miniment_in_top(t_list *a,int min_position,int size)
{
     if ((min_position > size/2) || min_position == size)
   {
       while ((min_position > size/2))
       {
           if (min_position == size)
           {
               printf("ra\n");
               ft_ra_rb(&a);
               break;
           }
            ft_ra_rb(&a);
           min_position++;
           printf("ra\n");
       }
   }
   else
   {
        while ((min_position <= size/2) && min_position != 1)
       {
           printf("\n rrb %d",min_position);
           ft_rra_rrb(&a);
           min_position--;
           if (min_position == 1)
               break; 
       }
   }
}
int check_for_sa(t_list *a)
{
    int n1;
    int n2;
    n1 = *(int *) a -> content;
    n2 = *(int *)(a -> next) -> content;
    if (n1 > n2)
    {
        ft_sa(a);
        printf("sa\n");
        return 1;
    }
    return 0;
}

void instruction(t_list *a,int min_position,int size,t_list *b)
{
   while (!check_list(a))
   {
      miniment_in_top(a,min_position,size);
      print_f(a);
    //   if(check_list(a))
    //         return;
    //   if(check_for_sa(a))
    //         {   
    //              if (check_list(a))
    //                     return;
    //         }
    //   ft_pa(&a,&b);
    //   print_f(b);
      break;
   }
}