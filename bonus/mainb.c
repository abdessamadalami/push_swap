#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h>
 #include "libft.h"
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
void char_instruction(t_list **a, t_list **b ,t_list **inst, char c, void (f_inst)(t_list** ,char,t_list **))
{
  
    if(c == 'r' || c == 's')
    {
        f_inst(a,'a', inst);
        f_inst(b,'b', inst);
    }
    else if (c == 'a')
        f_inst(a,c,inst);
    else if (c == 'b')
        f_inst(b,c,inst);
}
char give_me_instruction(char *instruction)
{
    char tab[];
    tab[] = "pa\npb\nsa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\n";
}
void pprr(t_list **a ,t_list **b, t_list **inst,char *instruction)
{


        if (instruction[0] == 's' && instruction[2] == '\n')
        {
            printf("____");
            char_instruction(a,b, inst,instruction[1] , ft_s);// not the same
        }
        else if (instruction[0] == 'r' && instruction[1] == 'r' && ( instruction[2] == 'r'|| instruction[2] == 'a' || instruction[2]== 'b'))
            char_instruction(a, b, inst,instruction[2] , ft_ra_rb);
        else if (instruction[0] == 'r' && instruction[2] == '\n')
            char_instruction(a,b, inst,instruction[1] , ft_rra_rrb);
        else if (instruction[0] == 'p' && instruction[2] == '\n')
        {
            printf("rrrrrrrrrrrrr");
            ft_p(a, b ,instruction[1], inst);
        }
        else
        {
            printf("Unknown instruction _%c_\n",instruction[1]);
            exit(0);
        }
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
int main(int argc, char **argv){

  char instruction;
  int k;
  

    t_list  *a;
    t_list  *b;
    t_list  *inst;
    int i;
    char tab[4];
  
    inst = 0;
    i = 0;
    a = check_and_make(argc ,argv);
    k = 2;
    while (k != 0) 
    {
        k = read(0, &instruction, 1);
             tab[i] = (instruction);
        if ((instruction) == '\n' && i != 0)
        {
            tab[i + 1] = '\0';
            pprr(&a , &b, &inst,tab);
            i = -1;
        }
        i++;
    }
    print_f(a);
    print_f(b);
    print_f_str(inst);
    if (check_list(a) == 1 && b == 0)
        write(1, "OK\n",3);
    else
        write(1, "KO\n",3);
       ft_lstclear(&a, del);
    //  ft_lstclear(&b, del);
    //  ft_lstclear(&inst, del);0
    // system("leaks mix");
}