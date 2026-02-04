#include "push_swap.c"

static int	move_run_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	len;
	int	i;

	len = get_desc_len(stack_a);
	i = 0;
	while (i < len)
	{
		pb(stack_b, stack_a);
		i++;
	}
	return (len);
}

void	sort_one_pass(t_stack *stack_a,t_stack *stack_b)
{
	int	i;
	int	init_count;
	int	len_a;
	int	len_b;

	init_count = stack_a->size;
	while (init_count > 0)
	{
		len_b = move_run_to_b(stack_a, stack_b);
		init_count -= len_b;
		len_a = 0;
		if (init_count > 0)
		{
			len_a = get_asc_len(stack_a);
			init_count -= len_a;
		}
		merge_len_in_a(stack_a, stack_b, len_a, len_b);
	}
}
