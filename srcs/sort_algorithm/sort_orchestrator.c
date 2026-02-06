#include "push_swap.h"

static void	push_by_quartiles_to_b(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int	limit_size;
	int	sent_count;
	int	i;

	limit_size = stack_a->size;
	sent_count = 0;
	i = 0;
	while (limit_size > i && stack_a->size > 3)
	{
		if (stack_a->top->value >= start && stack_a->top->value <= end)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
		i++;
	}
}

static void align_min_to_top(t_stack *stack_a)
{
	t_node  *current;
	int	 min_val;
	int	 min_index;
	int	 i;

	if (!stack_a->top)
		return ;
	min_val = stack_a->top->value;
	min_index = 0;
	current = stack_a->top;
	i = 0;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	if (min_index <= stack_a->size / 2)
	{
		while (stack_a->top->value != min_val) 
			ra(stack_a);
	}
	else
	{
		while (stack_a->top->value != min_val) 
			rra(stack_a);
	}
}

void sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted_refs;
	int	total_size;
	int	qua_1;
	int	qua_2;
	int	qua_3;

	if (stack_a->size <= 3)
	{
		if (stack_a->size == 2)
			sa(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		return ;
	}
	total_size = stack_a->size;
	sorted_refs = build_sorted_reference(stack_a, total_size);
	bubble_sort_array_ascending(sorted_refs, total_size);
	qua_1 = sorted_refs[total_size / 4];
	qua_2 = sorted_refs[total_size / 2];
	qua_3 = sorted_refs[(total_size * 3) / 4];
	free(sorted_refs);
	push_by_quartiles_to_b(stack_a, stack_b, qua_3, 2147483647);
	push_by_quartiles_to_b(stack_a, stack_b, qua_2, qua_3);
	push_by_quartiles_to_b(stack_a, stack_b, qua_1, qua_2);
	while (stack_a->size > 3)
		pb(stack_b, stack_a);
	sort_three(stack_a);
	while (stack_b->size > 0)
		greedy_move_cheapest_node(stack_a, stack_b);
	align_min_to_top(stack_a);
}