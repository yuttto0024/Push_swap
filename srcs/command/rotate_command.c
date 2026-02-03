#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate(stack);
	printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(stack);
	printf("ra\n");
}

void	rr(t_stack *stack_a, t_stack *stack_B)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("ra\n");
}
