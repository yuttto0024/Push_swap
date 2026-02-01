#include "push_swap.h"

void	add_node_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		new_node->pre = NULL;
		new_node->next = NULL;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->pre = stack->bottom;
		new_node->next = NULL;
		stack->bottom = new_node;
	}
	stack->size++;
}