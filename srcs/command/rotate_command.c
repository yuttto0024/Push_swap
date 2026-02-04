#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_B)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
