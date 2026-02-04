#include "push_swap.h"

static void	stack_remove_top(t_stack *stack_y)
{
	t_node	*first_y;
	t_node	*second_y;

	first_y = stack_y->top;
	second_y = first_y->next;
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

static void stack_add_top(t_stack *stack_x, t_node *new_node)
{
	t_node	*first_x;

    first_x = stack_x->top;
	if (stack_x->size > 0)
	{
		new_node->next = first_x;
		first_x->pre = new_node;
	}
	else
	{
		stack_x->bottom = new_node;
		new_node->next = NULL;
	}
	stack_x->top = new_node;
	stack_x->size++;
	new_node->pre = NULL;
}

void	push(t_stack *stack_x, t_stack *stack_y)
{
	t_node	*tmp_move_node;

	if (stack_y->size == 0)
		return ;
	tmp_move_node = stack_y->top;
	stack_remove_top(stack_y);
	stack_add_top(stack_x, tmp_move_node);
}
