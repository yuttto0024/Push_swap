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
	t_stack	stack;
	char	**args;
	int		asc;
	int		desc;

	if (argc < 2)
        return (0);
	stack.top = NULL;
	stack.bottom = NULL;
	stack.size = 0;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (1);
		init_stack_a(&stack, args, argc);
		debug_print_stack(&stack);
		free_strs(args);
	}
	else
	{
		init_stack_a(&stack, &argv[1], argc);
		debug_print_stack(&stack);
	}
	// if (stack.size == 3)
 	// 	sort_three(&stack);
	// else if (stack.size == 2)
	// 	sort_three(&stack);
	// ft_printf("---after_sort---\n");
	// debug_print_stack(&stack);
	ft_printf("--- Run Check ---\n");
	debug_print_stack(&stack);
	asc = get_asc_length(&stack);
	desc = get_desc_length(&stack);
	ft_printf("Ascending Run: %d\n", asc);
	ft_printf("Descending Run: %d\n", desc);
	free_stack(&stack);
	return (0);
}

