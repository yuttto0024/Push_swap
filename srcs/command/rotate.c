#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*end;
	
	if (stack->size <= 1)
		return ;
	first = stack->top;
	second = first->next;
	end = stack->bottom;
	stack->top = second;
	second->pre = NULL;
	stack->bottom = first;
	end->next = first;
	first->pre = end;
	first->next = NULL;
}
