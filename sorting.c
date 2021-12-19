#include "libft.h"
#include <stdio.h>

int get_the_psition(t_list *b,int nbr,int size)
{
    int i;
    int n1;
    int n2;
    int index;
    int max_content;
    int min_content;

    i = 1;
    index = 1;
    int min_position = miin_node(b, &min_content);
    int max_position = max_node(b, &max_content);
     if (nbr < min_content && nbr < max_content)
         return min_position +1 ;
     else if (nbr > max_content && nbr > max_content)
     {
         return max_position;
     }
     else
     {
            while (size-1)
            {
                n1 = *(int *)b -> content;
                n2 = *(int *)(b -> next) -> content;
                if ((n1 < nbr && n2 > nbr) && (n1 != min_content))
                {
                    return i + 1;
                }
                if (n1 > nbr && n2 < nbr )
                {
                    return i+1;
                }
                b = b -> next;
                i++;
                size--;
            }
     }
	return (1);
}

int pushb_in_the_p(t_list **a, t_list **b, int sum,t_list **inst)
{
    int position;
    int nbr;
    int size;

    nbr = *(int *)(*a) -> content;
    size = ft_lstsize(*b);
     position = 0;
      if (*b == NULL || size <= 2)
    {
        if (nbr >= sum)
        {
              ft_p(a, b,'b',inst);
              return 1;
        }
    } 
    else if(nbr >= sum)
    { 
      position = get_the_psition(*b, nbr,size);
      if (position != 1 )
      {   
          nbr_in_top(b, position, size, 'b', inst);
      }
        ft_p(a, b, 'b',inst);
       if (ft_lstsize(*a) == 0)
                return (-1);
      return 1;
    }
    return 0;
}
int ft_get_the_instraction(t_list **a, int sum )
{
     int nbr1;
      int nbr2;
      t_list *node;
      node = ft_lstlast(*a);
    if(ft_lstsize(*a) >= 3)
    {
            nbr1 = *(int *)((*a) ->next)-> content;
            nbr2 = *(int *)node -> content;
      if (nbr2 < sum)
             return 1;//1:rra             
    }
   return 0; 
}

void instruction(t_list **a,int size,t_list **b,int sum,t_list **inst)
{
     int argc = ft_lstsize(*a);
     int index = 0;
     int m;
     int nbr1;
     int nbr2;
     t_list *node;
  while (1)
   {
        m = pushb_in_the_p(a, b, sum / (argc), inst);
        if(m == -1)
             return;
        if (((*a) -> next) != NULL && m == 0)
              {
                      print_f(*a);
                      ft_ra_rb(a, 'a', inst);
                     print_f(*a);
                     return ;
              }
       if (index <= size && ft_lstsize(*a) != 0)
       {
           if (ft_lstsize(*a) >= 1 )
           {
                instruction(a, ft_lstsize(*a), b, ft_sum(*a, ft_lstsize(*a)),inst);
           }
            break;  
       }
       size--; 
   }
   
}