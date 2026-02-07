/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_orchestrator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:04:26 by yuonishi          #+#    #+#             */
/*   Updated: 2026/02/07 14:14:55 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_range(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int	limit;

	limit = stack_a->size;
	while (limit-- > 0 && stack_a->size > 3)
	{
		if (stack_a->top->value >= start && stack_a->top->value <= end)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
}

static void	process_quartiles(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted;
	int	size;
	int	q1;
	int	q2;
	int	q3;

	size = stack_a->size;
	sorted = build_sorted_reference(stack_a, size);
	bubble_sort_array_ascending(sorted, size);
	q1 = size / 4;
	q2 = size / 2;
	q3 = size * 3 / 4;
	free(sorted);
	push_range(stack_a, stack_b, q3, 0x7fffffff);
	push_range(stack_a, stack_b, q2, q3);
	push_range(stack_a, stack_b, q1, q2);
	while (stack_a->size > 3)
		pb(stack_b, stack_a);
}

static int	get_min_index(t_stack *stack_a, int *min_value)
{
	t_node	*current;
	int		min_ia;
	int		i;

	*min_value = stack_a->top->value;
	min_ia = 0;
	current = stack_a->top;
	i = 0;
	while (current)
	{
		if (current->value < *min_value)
		{
			*min_value = current->value;
			min_ia = i;
		}
		current = current->next;
		i++;
	}
	return (min_ia);
}

static void	align_min_to_top(t_stack *stack_a)
{
	int	min_value;
	int	min_ia;

	if (!stack_a->top)
		return ;
	min_ia = get_min_index(stack_a, &min_value);
	if (min_ia <= stack_a->size / 2)
	{
		while (stack_a->top->value != min_value)
			ra(stack_a);
	}
	else
	{
		while (stack_a->top->value != min_value)
			rra(stack_a);
	}
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
	{
		if (stack_a->size == 2)
			sa(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		return ;
	}
	process_quartiles(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
		greedy_move_cheapest_node(stack_a, stack_b);
	align_min_to_top(stack_a);
}
