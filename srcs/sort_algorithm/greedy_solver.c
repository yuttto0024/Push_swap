#include "push_swap.h"

void greedy_move_cheapest_node(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_move	best;
	int		ib;
	int		target_ia;
	int		cost;

	best.cost = -1;
	current = stack_b->top;
	ib = 0;
	while (current)
	{
		target_ia = get_target_index(stack_a, current->value);
		cost = calculate_process_cost(stack_a->size, stack_b->size, target_ia, ib);
		if (best.cost == -1 || cost < best.cost)
		{
			best.cost = cost;
			best.target_ia = target_ia;
			best.ib = ib;
		}
		current = current->next;
		ib++;
	}
	execute_optimal_rotation_and_push(stack_a, stack_b, best.target_ia, best.ib);
}