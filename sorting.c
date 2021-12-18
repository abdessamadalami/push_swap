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

int pushb_in_the_p(t_list **a, t_list **b, int sum)
{
    int position;
    int nbr;
    int size;

    nbr = *(int *)(*a) -> content;
    size = ft_lstsize(*b);
     position = 0;
    if (*b == NULL || size <= 2)
    {
        ft_pb(a, b);
        if (size == 2)
        {
            tree_int(b);
            ft_sa(*b);
        }
        return 1;
    }  
    else if(nbr >= sum)  // some b9b9b9b99b9b9b9b
    {  
      position = get_the_psition(*b, nbr,size);
      if (position != 1)
      {  // printf("__%d------------------------------------------------__",position);
          nbr_in_top(b, position, size);
      }
        ft_pb(a, b); 
      return 1;
    }
    return 0;
}

void instruction(t_list **a,int size,t_list **b,int sum)
{
     int s = size;
     int argc = ft_lstsize(*a);
     int index = 0;
  while (1)
   {
       index++;
        // print_f(*b);
          int m = pushb_in_the_p(a, b, sum / argc);
    //    printf("%d_-______________________________________\n",m);
        if (*a != NULL && m == 0)
        {
            // printf("sum / argc _______%d_____ \n", sum/argc);
            //  print_f(*a);
            //  print_f(*b);

             ft_ra_rb(a);
             
            //  print_f(*a);
            //  print_f(*b);
            //  printf("\n\n\n\n\n\n");
        
        }
       if (index <= size)
       {
           if (ft_lstsize(*a) >= 1)
           {
               instruction(a, ft_lstsize(*a), b, ft_sum(*a,ft_lstsize(*a)));
           }
            //nbr_in_top(b, max_node(*b, &size), ft_lstsize(*b));
            break;  
       }
       size--; 
   }
   
}