#include "push_swap.c"

static int	is_sorted(t_stack *stack_a)
{
	if (get_asc_len(stack) == stack->size)
		return (1);
	return (0);
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	while (!is_sorted(stack_a))
		sort_one_pass(stack_a, stack_b);
}