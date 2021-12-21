#include"libft.h"
#include<stdio.h>
#include<unistd.h>
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

int ft_sum(t_list *a, int nbr)
{
    int sum ,size;
     int sum_half = 0;
     int argc = 0;

    sum = 0;
    size = nbr;
    argc = ft_lstsize(a);
   while(nbr)
   {
      if (nbr < 100)
      {
         sum_half += *(int *)a -> content;
      }
      sum += *(int *)a -> content;
      a = a->next;
      nbr--;

   }
   if (size > 100)
   {
      return sum_half;
   }
   return (sum);
}

void print_f_str(t_list *a) {

   t_list *ptr = a;
   char *str1;
   char *str2;
   int len;
   //start from the beginning
   while(ptr -> next != NULL)
   {
       str1 = ptr -> content;
       str2 = ptr -> next ->content;
      if ((str1[2] == '\0' && str2[2] == '\0') && (str1[0] == str2[0]) && (str2[0] != 'p') && (str2[1] != str1[1]))
      {
         if (str1[0] == 's' && (str2[1] == 'a' || str2[1]== 'b'))
         {
               printf("( ss )\n");
               ptr = ptr -> next;
         }
         else if (str1[0] == 'r' && (str2[1] == 'a' || str2[1]== 'b') )
         {
               printf("( rr )\n");
               ptr = ptr -> next;
         }
      }
      else
         printf("( %s ) \n",ptr -> content); 
      ptr = ptr -> next;
   }
}