#include "push_swap.h"

static int  get_min_index(t_stack *stack)
{
	t_node	*curr;
	int		min;
	int		min_index;
	int		i;

	if (!stack || !stack->top)
		return (-1);
	curr = stack->top;
	min = curr->value;
	min_index = 0;
	i = 0;
	while (curr)
	{
		if (curr->value < min)
		{
			min = curr->value;
			min_index = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_index);
}

void	fix_rotation(t_stack *stack_a)
{
	int	min_idx;
	int	size;

	min_idx = get_min_index(stack_a);
	size = stack_a->size;

	if (min_idx <= size / 2)
	{
		while (min_idx > 0)
		{
			ra(stack_a);
			min_idx--;
		}
	}
	else
	{
		while (min_idx < size)
		{
			rra(stack_a);
			min_idx++;
        }
    }
}