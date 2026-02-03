#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;
	
	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	last = stack->bottom;
	stack->top = second;
	second->pre = NULL;
	stack->bottom = first;
	last->next = first;
	first->pre = last;
	first->next = NULL;
}
