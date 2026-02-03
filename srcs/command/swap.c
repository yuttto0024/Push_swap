#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	third = second->next;

	first->next = third;
	first->pre = second;

	second->next = first;
	second->pre = NULL;

	if (stack->size >= 3)
		third->pre = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}