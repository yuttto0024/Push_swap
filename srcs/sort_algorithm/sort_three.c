#include "push_swap.h"

static int	find_max_value(t_stack *stack)
{
	int		max;
	t_node	*current;

	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	sort_three(t_stack *a)
{
	int		max_value;	
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	max_value = find_max_value(a);
	if (a->top->value == max_value)
		ra(a);
	else if (a->top->next->value == max_value)
		rra(a);
	first = a->top;
	second = first->next;
	if (first->value > second->value)
		sa(a);
}