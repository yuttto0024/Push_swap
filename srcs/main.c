#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	debug_print_stack(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	printf("Size: %d\n", stack->size);
	printf("Top: %p, Bottom: %p\n", stack->top, stack->bottom);
	while (current)
	{	
		printf("[%d]\n", current->value);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**args;
	if (argc < 2)
		return (0);
	stack_a.top = NULL;
	stack_a.bottom = NULL;
	stack_a.size = 0;
    stack_b.top = NULL;
	stack_b.bottom = NULL;
	stack_b.size = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)	
			return (1);
		init_stack_a(&stack_a, args, argc);
		free_strs(args);
	}
	else
		init_stack_a(&stack_a, &argv[1], argc);
	if (stack_a.size == 2)
		sort_three(&stack_a);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else
		sort_stacks(&stack_a, &stack_b);
	free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}

