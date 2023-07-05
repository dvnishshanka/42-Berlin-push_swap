#include "push_swap.h"

void print_list(t_stack_node *list)
{
    t_stack_node *current_node;

    current_node = list;
    while (current_node)
    {
        printf("Node: %d\n", current_node->value);
        current_node = current_node->next;
    }
}


int main(int argc, char **argv)
{
    int i;
    t_stack_node *a;
    // t_stack_node *b;
    int free_argv;

    i = 1;
    free_argv = 0;
    a = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0' ))
        return (0);
    else if (argc == 2)
    {  
        argv = ft_split(argv[1], ' ');
        free_argv = 1;
    }
        
 while (argv[i])
    {
        printf("main %s %d\n", argv[i], i);
        i++;
    }
    a= init_stack(a, argv, free_argv);
    print_list(a);
    if (free_argv)
        ft_free_array(argv, 0);
    ft_free_stack(a);
    // printf("%d %s", argc, argv[1]);
    // printf("%ld %ld %ld", ft_atol("346576"), ft_atol("00"), ft_atol("53628961"));
    // printf("%ld", ft_atol("536289618dfbvj"));   
    return (0);
}