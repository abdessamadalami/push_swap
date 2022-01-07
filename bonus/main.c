/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:05:37 by ael-oual          #+#    #+#             */
/*   Updated: 2021/12/06 11:05:43 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include<unistd.h>

int *f(int a)
{
    int *ptr;

	ptr = malloc(4);
	*ptr = a;
	return ptr;
}

void del(void *ptr)
{
	 free(ptr);
}

int duplicat(t_list *a)
{
    int nbr;
    t_list *list;

    nbr = 0;
    while (a)
    {
       nbr = *(int *)a -> content;
       list = a -> next;
        while (list)
        {
            if (*(int *)list ->content == nbr)
            {
                return 1;
            }
            list = list -> next;
        }
        a = a->next;
    }
    return 0;
}

int check_nbr_list(t_list *a , int nbr,int *cont)
{
    int index;
    int n;
    
    index = 1;
    while (a)
    {
        n = *(int *) a -> content;
       if (n < nbr)
       {
            *cont = n;
            return index;
       }
       index++;
       a = a -> next;
    }
        return 0;
}

void pro_link(t_list **a, t_list **b, t_list **inst, int t)
{
    int m;
    int cont;
    int position;
    int position_b;
    
    position_b = 0;
    m =  buble_list(*a);
    while(1)
    {
        position = check_nbr_list (*a, m, &cont);
        if((*a) -> next == NULL)
            return;
        if (position == 0)
            return;
        if (*b != NULL && t == 1)
            position_b = get_the_psition(*b,cont,ft_lstsize(*b));
         nbr_in_top_of_two(a, b, position, position_b, inst);
         ft_p(a, b,'b',inst);
    }
}


void countSwaps(int a_count, int* a) 
{
    int i;
    int j;
    int nbr;

    i = 0; 
    while (i < a_count) 
    {
        j = 0;
        while ( j < a_count - 1)    
        {
            if (a[j] > a[j + 1])
            {
                nbr = a[j];
                a[j] = a[j + 1];
                a[j + 1] = nbr;
            }
            j++;
        }
        i++;
    }
}

int buble_list(t_list *a) 
{
    int n1;
    int i;
    int k;
    int arr[ft_lstsize(a)];

    i = 0;
    k = 3;
   while(a) 
   {
        n1 = *(int *) (a) -> content;
        arr[i++] = n1;
        a = a -> next;    
   }
    countSwaps(i, arr);
    if (i > 100)
        k = 8;
    return (arr[i / (k)]);  
}

int check_argv(char *argv)
{
     int index;

     index = 0;
     while (argv[index] != '\0')
     {
         if(ft_isdigit(argv[index]) == 0 && argv[index] != '-')
                return 0;
         index ++;
     }
     return 1;
}

t_list *check_and_make(int argc ,char **argv)
{
    t_list  *a;
	t_list  *node;
    int     i;

    i = 1;
    a = 0;
    while (i < argc)
    {
         if (check_argv(argv[i]) == 0)
         {
             write(1, "Error", 5);//letters
             exit(0);
         }
        node = ft_lstnew(f(ft_atoi(argv[i])));
        ft_lstadd_back(&a, node);
        i++;
    }
    if (duplicat(a) || argc == 1)
    {
        write(1, "Error", 5);//letters
        ft_lstclear(&a, del);
        exit(0);
    }
    return (a);
}

int main(int argc, char **argv)
{
	t_list  *a;
    t_list  *b;
    t_list  *inst;
    int t = 1;
  
    inst = 0;
    a = check_and_make(argc ,argv);
   while (ft_lstsize(a) > 3)
        pro_link(&a, &b, &inst, 1);
    if (ft_lstsize(a) == 2 && check_list(a) != 1)
         ft_s(a,'a',&inst);
   else if (check_list(a) != 1)
          tree_int(&a,'a',&inst);
   while(b)
   {
     nbr_in_top_of_two(&a, &b, 0, max_node(b, &t) ,&inst);
     ft_p(&a, &b, 'a',&inst);
   }
  //  printf("%d \n",check_list(a) );
    //print_f(a);
    print_f_str(inst);
    ft_lstclear(&a, del);
    ft_lstclear(&b, del);
    ft_lstclear(&inst, del);
   // system("leaks a.out");
}