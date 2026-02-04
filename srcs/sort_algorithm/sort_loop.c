#include "push_swap.h"

void	conplete_sort_step(t_stack *stack_a, t_stack *stack_b)
{
	int	len_b;
	int	len_a;

	len_b = move_run_to_b(stack_a, stack_b);
	len_a = get_asc_len(stack_a);
	merge_len_in_a(stack_a, stack_b, len_a, len_b);
}

int	move_run_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	len;
	int	i;

	len = get_asc_len(stack_a);
	i = 0;
	while (i < len)
	{
		pb(stack_b, stack_a);
		i++;
	}
}