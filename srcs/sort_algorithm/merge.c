#include "push_swap.h"

void	merge_len_in_a(t_stack *stack_a, t_stack *stack_b, int len_a, int len_b)
{
	while (len_a > 0 && len_b > 0)
	{
		if (stack_a->top->value < stack_b->top->value)
		{
			ra(stack_a);
			len_a--;
		}
		else
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			len_b--;
		}
	}
	while (len_a > 0)
	{
		ra(stack_a);
		len_a--;
	}
	while (len_b > 0)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		len_b--;
	}
}
