#include "push_swap.h"

static int search_closest_larger_index(t_stack *stack_a, int b_value)
{
	t_node	*current;
	int		target_index;
	int		closest_value;
	int		i;

	target_index = -1;
	current = stack_a->top;
	i = 0;
	while (current)
	{
		if (current->value > b_value)
		{
			if (target_index == -1 || current->value < closest_value)
			{
				closest_value = current->value;
				target_index = i;
			}
		}
		current = current->next;
		i++;
	}
	return (target_index);
}

int get_target_index(t_stack *stack_a, int b_value)
{
	t_node	*current;
	int		min_value;
	int		max_value;
	int		boundary_index;
	int		i;

	if (!stack_a->top) 
		return (0);

	min_value = stack_a->top->value;
	max_value = stack_a->top->value;
	boundary_index = 0;
	current = stack_a->top;
	i = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			boundary_index = i;
		}
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
		i++;
	}
	if (b_value < min_value || b_value > max_value)
		return (boundary_index);
	return (search_closest_larger_index(stack_a, b_value));
}