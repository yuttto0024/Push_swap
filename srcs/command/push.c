#include "push_swap.h"

static void	push_add(t_stack *stack_x, t_stack *stack_y)
{
	if (stack_x->size > 0)
	{



	}


}


void	push(t_stack *stack_x, t_stack *stack_y)
{
	t_node	*first_x;
	t_node	*first_y;
	t_node	*second_y;

	if (stack_y->size == 0)
		return ;
	first_x = stack_x->top;
	first_y = stack_y->top;
	second_y = first_y->next;

	if (stack_x->size > 0)
	{
		first_y->next = first_x;
		first_x->pre = first_y;
	}
	else 
	{
		stack_x->bottom = first_y;
		first_y->next = NULL;
	}
	stack_x->top = first_y;
	stack_x->size++;

	first_y->pre = NULL;
	if (stack_y->size > 1)
	{
		stack_y->top = second_y;
		second_y->pre = NULL;
	}
	else
	{
		stack_y->top = NULL;
		stack_y->bottom = NULL;
	}
	stack_y->size--;
}