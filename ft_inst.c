#include"libft.h"
#include <stdio.h>

void ft_sa(t_list *a)
{
    int *sawp;
    sawp = a -> content;
       printf("sa\n");
    a -> content = a -> next -> content;
    a -> next -> content = sawp;
}

void ft_sb(t_list *a)
{
    if (a == NULL)
        return;
    int *sawp;
    sawp = a -> content;
    printf("sa\n");
    a -> content = a -> next -> content;
    a -> next -> content = sawp;
}


void ft_pb(t_list **a,t_list **b)
{
 
     t_list *node;
     t_list *node1;
         /* code */ 
        node = ft_lstnew((*a) -> content);
        node1 = *a;
        ft_lstadd_front(b, node);
        *a = (*a) -> next; //leks
         printf("pa\n");
        free(node1);
     
}

void ft_pa(t_list **a,t_list **b)
{
     
     t_list *node;
     t_list *node1;
     node = ft_lstnew((*b) -> content);
        node1 = *b;
        ft_lstadd_front(a, node);
        *b = (*b) -> next; //leks
        printf("pa\n");
      //  print_f(*b);
        free(node1);
}

void ft_ra_rb(t_list **a)
{
    t_list *node;
    t_list *l;
    t_list *list;

    node = ft_lstlast(*a);
    printf("ra\n");
    ft_lstadd_front(a, ft_lstnew(node -> content));
     list = *a;
     while ((*a) -> next -> next != NULL)
         (*a) = (*a) -> next;
     (*a) -> next = NULL;
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
     printf("rra\n");
}

int check_list(t_list *a)
{
    int index;

    index = *(int *)a -> content;
    while (a)
    {
        if (index > *(int *)a -> content)
        {
            return (0);
        }
        index = *(int *)a ->content;
        a = a -> next;
    }
    return (1);
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
    if ((n1 > n2 && n3 < n1 && n2 > n3 ) || (n1 < n2 && n2 > n3 && n1 < n3))
    {
        ft_sa(*a);
        ft_ra_rb(a);
    }
    else if (n1 > n2 && n1 < n3)
        ft_sa(*a);
    else if (n1 > n2 && n1 > n3)
        ft_rra_rrb(a);
    else if (n1 < n2 && n2 > n3 && n2 > n3)
            ft_ra_rb(a);
    else if (n1 < n2 && n2 > n3)
        {
            ft_ra_rb(a);
            ft_sa(*a);
        }
}

void nbr_in_top(t_list **a, int min_position, int size)
{
    int index = 0;
  //  printf("{%d}\n",min_position);
    if (size == min_position && min_position != 1)
        ft_ra_rb(a);
    
    else if ((min_position <= size/2) || size - min_position == size / 2)
   {
       while (min_position >= 1  )
       {
          // print_f(*a);
           if (min_position == 2)
           {
               ft_rra_rrb(a);
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
           if (min_position > size)
           {
             // print_f(*a); 
              return;
           }
            ft_ra_rb(a);
        //    printf("{{{{{{{{ *b  nbr = %d  %d }}}}}}}} \n", min_position,size);
        //    print_f(*a);
            min_position++;
       }
   }
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

int	miin_node(t_list *lst,int *content)
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
        if (a < i)
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