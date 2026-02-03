#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*last_second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	last_second = last->pre;
	stack->top = last;
	last->pre = NULL;
	last->next = first;
	first->pre = last;
	stack->bottom = last_second;
	last_second->next = NULL;
}