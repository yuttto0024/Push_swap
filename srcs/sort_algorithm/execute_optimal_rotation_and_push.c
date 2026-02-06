#include "push_swap.h"

static void apply_rr_strategy(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	while (ia > 0 && ib > 0)
	{
		rr(stack_a, stack_b);
		ia--;
		ib--;
	}
	while (ia > 0)
	{
		ra(stack_a);
		ia--;
	}
	while (ib > 0)
	{
		rb(stack_b);
		ib--;
	}
}

static void apply_rrr_strategy(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int rev_ia;
	int rev_ib;

	rev_ia = stack_a->size - ia;
	if (ia == 0)
		rev_ia = 0;
	rev_ib = stack_b->size - ib;
	if (ib == 0)
		rev_ib = 0;
	while (rev_ia > 0 && rev_ib > 0)
	{
		rrr(stack_a, stack_b);
		rev_ia--;
		rev_ib--;
	}
	while (rev_ia-- > 0)
		rra(stack_a);
	while (rev_ib-- > 0)
		rrb(stack_b);
}

static void apply_mixed_strategy(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int rev_ia;
	int rev_ib;

	rev_ia = stack_a->size - ia;
	if (ia == 0)
		rev_ia = 0;
	rev_ib = stack_b->size - ib;
	if (ib == 0)
		rev_ib = 0;
	if (ia <= (stack_a->size / 2))
	{
		while (ia-- > 0)
			ra(stack_a);
	}
	else
	{
		while (rev_ia-- > 0)
			rra(stack_a);
	}
	if (ib <= (stack_b->size / 2))
	{
		while (ib-- > 0)
			rb(stack_b);
	}
	else
	{
		while (rev_ib-- > 0)
			rrb(stack_b);
	}
}

void execute_optimal_rotation_and_push(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int cost;
	int cost_rr;
	int cost_rrr;
	int rev_ia;
	int rev_ib;

	cost = calculate_process_cost(stack_a->size, stack_b->size, ia, ib);
	if (ia > ib)
		cost_rr = ia;
	else
		cost_rr = ib;
	rev_ia = stack_a->size - ia;
	if (ia == 0)
		rev_ia = 0;
	rev_ib = stack_b->size - ib;
	if (ib == 0)
		rev_ib = 0;
	if (rev_ia > rev_ib)
		cost_rrr = rev_ia;
	else
		cost_rrr = rev_ib;
	if (cost == cost_rr)
		apply_rr_strategy(stack_a, stack_b, ia, ib);
	else if (cost == cost_rrr)
		apply_rrr_strategy(stack_a, stack_b, ia, ib);
	else
		apply_mixed_strategy(stack_a, stack_b, ia, ib);
	pa(stack_a, stack_b);
}