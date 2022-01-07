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
