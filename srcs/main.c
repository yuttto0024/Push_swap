#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    char    **args;
    int     is_split;

    if (argc < 2)
        return (0);

    stack_a.top = NULL;
    stack_a.bottom = NULL;
    stack_a.size = 0;
    stack_b.top = NULL;
    stack_b.bottom = NULL;
    stack_b.size = 0;

    is_split = 0;
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args) return (1);
        is_split = 1;
    }
    else
        args = argv + 1;
    
    init_stack_a(&stack_a, args, argc);
    
    if (is_split)
        free_strs(args);

    if (!is_sorted(&stack_a))
    {
        if (stack_a.size == 2)
            sa(&stack_a);
        else if (stack_a.size == 3)
            sort_three(&stack_a);
        else
            sort_stacks(&stack_a, &stack_b);
    }

    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}