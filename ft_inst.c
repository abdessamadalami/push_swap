#include"libft.h"
#include <stdio.h>

void ft_sa(t_list *a)
{
    int *sawp;
    sawp = a -> content;
     printf(" %d ",*sawp);
    a -> content = a -> next -> content;
    a -> next -> content = sawp;
   
    printf("%d",*(int *)(a -> content));
}

void ft_sb(t_list *a)
{
    if (a == NULL)
        return;
    int *sawp;
    sawp = a -> content;
     printf(" %d ",*sawp);
    a -> content = a -> next -> content;
    a -> next -> content = sawp;
   
    printf("%d",*(int *)(a -> content));
}


void ft_pa(t_list **a,t_list **b)
{
 
     t_list *node;
     t_list *node1;
     node = ft_lstnew((*a) -> content);
        node1 = *a;
        ft_lstadd_front(b, node);
        *a = (*a) -> next; //leks
        free(node1);
}

void ft_pb(t_list **a,t_list **b)
{
 
     t_list *node;
     t_list *node1;
     node = ft_lstnew((*b) -> content);
        node1 = *b;
        ft_lstadd_front(a, node);
        *b = (*b) -> next; //leks
        free(node1);
}

void ft_ra_rb(t_list **a)
{
    t_list *node;
    t_list *l;
    t_list *list;

    node = ft_lstlast(*a);
    //printf("\ndd%d",*(int *)node->content);
    ft_lstadd_front(a, ft_lstnew(node -> content));
     printf("\n%d", *(int *)(*a) -> content);
     list = *a;
     while ((*a) -> next -> next != NULL)
         (*a) = (*a) -> next;
     (*a) -> next = NULL;
     printf(" %d ",*(int *)(*a) -> content);
     *a = list;
}

void ft_rra_rrb(t_list **a)
{
    t_list *node;
    t_list *list;
    node = (ft_lstnew((*a) -> content));
    ft_lstadd_back(a, node);
    list = *a;
    (*a) = (*a) -> next;
    free(list);
}
 