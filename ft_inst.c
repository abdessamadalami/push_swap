#include"libft.h"
#include <stdio.h>

void ft_s(t_list *a, char c, t_list **inst)
{
    int *sawp;
    sawp = a -> content;
    a -> content = a -> next -> content;
    a -> next -> content = sawp;
    if(c == 'a')
    {
       write(1,"sa\n",4);
        ft_lstadd_back(inst,ft_lstnew(ft_strdup("sa")));
    }
    else
    {
       write(1,"sb\n",4);
        ft_lstadd_back(inst,ft_lstnew(ft_strdup("sa")));
    }
}

void ft_p(t_list **a,t_list **b ,char c, t_list **inst)
{
 
     t_list *node;
     t_list *node1;
if(c == 'b')
{
        node = ft_lstnew((*a) -> content);
        node1 = *a;
        ft_lstadd_front(b, node);
        *a = (*a) -> next; //leks
        free(node1);
        write(1,"pb\n",4);
        ft_lstadd_back(inst,ft_lstnew(ft_strdup("pb")));
}
else
{
     node = ft_lstnew((*b) -> content);
        node1 = *b;
        ft_lstadd_front(a, node);
        *b = (*b) -> next; //leks
       write(1,"pa\n",4);
        ft_lstadd_back(inst,ft_lstnew(ft_strdup("pa")));
      // print_f(*b);
        free(node1);
} 
     
}

// void ft_pa(t_list **a,t_list **b)
// {
     
//      t_list *node;
//      t_list *node1;
//      node = ft_lstnew((*b) -> content);
//         node1 = *b;
//         ft_lstadd_front(a, node);
//         *b = (*b) -> next; //leks
//         printf("pa\n");
//       //  print_f(*b);
//         free(node1);
// }


void ft_ra_rb(t_list **a,char c, t_list **inst)
{
    t_list *node;
    t_list *l;
    t_list *list;

    node = ft_lstlast(*a);
    ft_lstadd_front(a, ft_lstnew(node -> content));
     list = *a;
     while ((*a) -> next -> next != NULL)
         (*a) = (*a) -> next;
     (*a) -> next = NULL;
     *a = list;
     if (c == 'a')
     {
        write(1,"rra\n",4);
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("rra")));
     }
     else
     {
         write(1,"rrb\n",4);
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("rrb")));
     }
     
}
//void ft_rra_rrb(t_list **a, char c,t_list **inst)
void ft_rra_rrb(t_list **a, char c,t_list **inst)
{
    t_list *node;
    t_list *list;
    node = (ft_lstnew((*a) -> content));
    ft_lstadd_back(a, node);
    list = *a;
    (*a) = (*a) -> next;
     if(c == 'a')
     {
         write(1,"ra\n",3);
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("ra")));
     }
     else
     {
        write(1,"rb\n",4);
         ft_lstadd_back(inst,ft_lstnew(ft_strdup("rb")));
     }
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
void tree_int(t_list **a,char c, t_list **inst)
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
        ft_s(*a, c, inst);
        ft_ra_rb(a, c, inst);
    }
    else if (n1 > n2 && n1 < n3)
        ft_s(*a, c,inst);
    else if (n1 > n2 && n1 > n3)
        ft_rra_rrb(a,c,inst);
    else if (n1 < n2 && n2 > n3 && n2 > n3)
            ft_ra_rb(a, c,inst);
    else if (n1 < n2 && n2 > n3)
        {
            ft_ra_rb(a, c,inst);
            ft_s(*a, c,inst);
        }
}

void nbr_in_top(t_list **a, int min_position, int size , char c,t_list **inst)
{
    int index = 0;
  //  printf("{%d}\n",min_position);
    if (size == min_position && min_position != 1)
    {
        ft_ra_rb(a,c,inst);
    }
    else if ((min_position <= size/2) || size - min_position == size / 2)
   {
       while (min_position >= 1  )
       {
          // print_f(*a);
           if (min_position == 2)
           {
               ft_rra_rrb(a,c,inst);
                break;
            }
            ft_rra_rrb(a,c,inst);
            min_position--;
       }
   }
   else
   {
        while ((min_position > size/2) && min_position != 1)
       {
           if (min_position > size)
              return;
            ft_ra_rb(a,c,inst);
        //    printf("{{{{{{{{ *b  nbr = %d  %d }}}}}}}} \n", min_position,size);
        //    print_f(*a);
            min_position++;
       }
   }
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

