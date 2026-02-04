#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_printf("pb\n");
}
