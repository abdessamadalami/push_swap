#include "libft.h"
#include <stdio.h>

int position_content(t_list *list, int nbr ,int *min_content,int *max_content)
{
    int min_position;
    int max_position;

      min_position = min_node(list, min_content);
      max_position = max_node(list, max_content);
        //printf(" min content %d \n", *min_content);
     if (nbr < *min_content && nbr < *max_content)
         return min_position + 1 ;
     else if (nbr > *max_content && nbr > *max_content)
         return max_position;
    return (0);
}

int get_the_psition(t_list *b,int nbr,int size)
{
    int i;
    int n1;
    int n2;
    int max_content;
    int min_content;

    i = 1;
    if (position_content(b, nbr ,&min_content,&max_content) != 0)
        return position_content(b, nbr ,&min_content,&max_content);
    while (size - 1)
    {
        n1 = *(int *)b -> content;
        n2 = *(int *)(b -> next) -> content;
        if ((n1 < nbr && n2 > nbr) && (n1 != min_content))
            return i + 1;
        if (n1 > nbr && n2 < nbr )
            return i+1;
        b = b -> next;
        i++;
        size--;
    }
	return (1);
}

void nbr_in_top_of_two(t_list **a, t_list **b, int pa , int pb , t_list **inst)
{
    int index_a = 0;
    int index_b = 0;

      if (pa > (ft_lstsize(*a) + 1)/2)
          {
              index_a = 1; // rra
              pa = ft_lstsize(*a) - pa + 1;
          }
       if (pb > (ft_lstsize(*b) + 1) / 2)
       {
          index_b = 1; // rra
          pb = ft_lstsize(*b) - pb + 1; //
       }
       while (pa >= 0 || pb >= 0)
       {
            if(index_a == 1 && pa >= 1)
                 ft_ra_rb(a,'a', inst); // rra
            if(index_a == 0 && pa > 1)
                 ft_rra_rrb(a,'a', inst); // ra
            if(index_b == 1 && pb >= 1)
                 ft_ra_rb(b,'b', inst); // rr
            if(index_b == 0 && pb > 1)
                 ft_rra_rrb(b,'b', inst); // rb
           pb--;
           pa--;
       }   
}