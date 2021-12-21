#include "libft.h"
#include <stdio.h>

int position_content(t_list *list, int nbr ,int *min_content,int *max_content)
{
    int min_position;
    int max_position;

      min_position = miin_node(list, min_content);
      max_position = max_node(list, max_content);
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
    while (size-1)
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
void sort_list(t_list **a, t_list **b, t_list **inst)
{
    int content;

    while(ft_lstsize(*a) > 3)
    {
       printf(" %d ",miin_node(*a, &content));
       if (miin_node(*a, &content) != 1)
                nbr_in_top(a, miin_node(*a, &content), ft_lstsize(*a),'a',inst);
       ft_p(a, b, 'b',inst);
    }
    tree_int(a, 'a', inst);
}

void instruction(t_list **a,int size,t_list **b,int sum,t_list **inst)
{
     int argc ;
     int index;
     int m;
  
    index = 0;
    argc = ft_lstsize(*a);
     if (argc > 100)
        argc = 55;
     m = pushb_in_the_p(a, b, sum/argc, inst); //80
    if(m == -1)
        return;
    if (((*a) -> next) != NULL && m == 0)
        ft_ra_rb(a, 'a', inst);// this is rra not ra the last becamme the first
    if (ft_lstsize(*a) >= 1)
    {
        instruction(a, ft_lstsize(*a), b, ft_sum(*a, ft_lstsize(*a)),inst);
    }
}