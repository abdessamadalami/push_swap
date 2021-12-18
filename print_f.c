#include"libft.h"
#include<stdio.h>
void print_f(t_list *a) {

   t_list *ptr = a;
   printf("\n[ ");

   //start from the beginning
   while(ptr)
   {
      printf("( %d ) ",*(int *)ptr -> content);
      ptr = ptr->next;
   }
   printf(" ]\n");
}
int ft_sum(t_list *a, int nbr)
{
    int sum;
    t_list *ptr;

    sum = 0;
    ptr = a;
   while(nbr)
   {
     sum += *(int *)ptr -> content;
      ptr = ptr->next;
      nbr--;
   }
   return (sum);

}