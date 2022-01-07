#include"libft.h"
#include <stdio.h>

void ft_s(t_list **a,char c, t_list **inst)
{
     int *sawp;
     if (ft_lstsize(*a) < 2)
          return;
     sawp = (*a) -> content;
     (*a) -> content = (*a) -> next -> content;
     (*a) -> next -> content = sawp;
    if(c == 'a')
        ft_lstadd_back(inst, ft_lstnew(ft_strdup("sa")));
    else if(c == 'b')
        ft_lstadd_back(inst, ft_lstnew(ft_strdup("sb")));
}

void ft_p(t_list **a,t_list **b ,char c, t_list **inst)
{
     t_list *node;
     t_list *node1;
   //  printf("p%c ",c);
if(c == 'b')
{
    // printf("i am  in pb \n");
         node = ft_lstnew((*a) -> content);
         node1 = *a;
         ft_lstadd_front(b, node);
         if ((*a) -> next != NULL)
             *a = (*a) -> next; 
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("pb")));
}
else if (c == 'a')
{
    //printf("i am  in pa \n");
    if ((*b) == NULL)
        return;
    node = ft_lstnew((*b) -> content);
    node1 = *b;  
       ft_lstadd_front(a, node);
         if ((*b) -> next != NULL)
            *b = (*b) -> next; //leks
        ft_lstadd_back(inst,ft_lstnew(ft_strdup("pa")));
} 
   free(node1); 
}

void ft_ra_rb(t_list **a,char c, t_list **inst)
{
    t_list  *node;
    t_list  *list;
    t_list  *l;
  //  printf("rr%c ",c);
    if (ft_lstsize(*a) < 2)
          return;
    node = ft_lstlast(*a);
    ft_lstadd_front(a, ft_lstnew(node -> content));
     list = *a;
     while ((*a) -> next -> next != NULL)
         (*a) = (*a) -> next;
      l = (*a) -> next;
     (*a) -> next = NULL;
     *a = list;
     if (c == 'a')
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("rra")));
     else
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("rrb")));
         free(l);
}

void ft_rra_rrb(t_list **a, char c,t_list **inst) //ra 
{
    t_list *node;
    t_list *list;

    if (ft_lstsize(*a) < 2)
          return;
    node = (ft_lstnew((*a) -> content));
    ft_lstadd_back(a, node);
    list = *a;
    (*a) = (*a) -> next;
    list -> next = NULL;
     if(c == 'a')
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("ra")));
     else
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("rb")));
    free(list);
}

int check_list(t_list *a)
{
    int index , i;

    index = *(int *)a -> content;
    i = 0;
    while (a)
    {
        if (index > *(int *)a -> content)
            return (-1 * i);
        index = *(int *)a ->content;
        a = a -> next;
        i++;
    }
    return (1);
}



int	max_node(t_list *lst,int *content)
{
    int i;
    int index;
    int a;
    int position;
    
    position = 1;
    index = 1;
    i = *(int *)lst -> content;
	while (lst)
	{
        a = *(int *)lst -> content;
        if (a > i)
        {
            i = a;
            position = index;
        }
        lst = lst -> next;
        index++;
	}
    *content = i;
	return (position);
}

int	min_node(t_list *lst, int *size)
{
    int i;
    int a;
    int position;
    int index;

    index = 1;
    *size = 1;
    position = 1;
    i = *(int *)lst -> content;
	while (lst)
	{
        a = *(int *)lst -> content;
        if (a < i)
        {
            i = a;
            position = index;
        }
        lst = lst -> next;
        index++;
	}
    *size = i;
	return (position);
}