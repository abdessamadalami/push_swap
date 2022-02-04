/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:09:59 by ael-oual          #+#    #+#             */
/*   Updated: 2022/02/02 14:10:00 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<unistd.h>

int	*f(int a)
{
	int	*ptr;

	ptr = malloc(4);
	if (ptr == NULL)
		return (0);
	*ptr = a;
	return (ptr);
}

void	del(void *ptr)
{
	free(ptr);
}

t_list	*check_and_make(int argc, char **argv)
{
	t_list	*a;
	t_list	*node;
	int		i;

	i = 1;
	a = 0;
	while (i < argc)
	{
		if (check_argv(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		node = ft_lstnew(f(ft_atoi(argv[i])));
		ft_lstadd_back(&a, node);
		i++;
	}
	if (duplicat(a) || argc == 1)
	{
		write(1, "Error\n", 6);
		ft_lstclear(&a, del);
		exit(0);
	}
	return (a);
}

int	check_argv(char *argv)
{
	int	index;

	index = 0;
	while (argv[index] != '\0')
	{
		if (ft_isdigit(argv[index]) == 0 && argv[index] != '-')
			return (0);
		index ++;
	}
	return (1);
}

int	duplicat(t_list *a)
{
	int		nbr;
	t_list	*list;

	nbr = 0;
	while (a)
	{
		nbr = *(int *)a -> content;
		list = a -> next;
		while (list)
		{
			if (*(int *)list ->content == nbr)
			{
				return (1);
			}
			list = list -> next;
		}
		a = a->next;
	}
	return (0);
}
/*
void print_f(t_list *a) {

   t_list *ptr = a;
   printf("\n[ ");

   //start from the beginning
   while(ptr)
   {
      printf(" %d ",*(int *)ptr -> content);
      ptr = ptr->next;
   }
   printf(" ]\n");
}


void print_f_str(t_list *list) {
   char *str1;
   char *str2;
   
   str2 = 0;
   while(list != NULL)
   {
       str1 = (char *)list -> content;
      if (list -> next != NULL)
          str2 = list -> next -> content;
      if (str2 != 0 && (str1[2] == '\0' && str2[2] == '\0') &&
         (str1[0] == str2[0]) && (str2[0] != 'p') && (str2[1] != str1[1]))
         {
            if (str1[0] == 's' && (str2[1] == 'a' || str2[1]== 'b'))
               write(1, "ss\n", 3);
            else if (str1[0] == 'r' && (str2[1] == 'a' || str2[1]== 'b'))
               write(1, "rr\n", 3);
            list = list -> next;
         }
      else
     {
         ft_putstr_fd(str1,1);
         write(1, "\n", 1);
     }
     list = list -> next;
   }
}
*/