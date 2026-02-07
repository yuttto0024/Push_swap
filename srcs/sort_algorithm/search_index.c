/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   search_index.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/07 09:44:35 by yuonishi		  #+#	#+#			 */
/*   Updated: 2026/02/07 09:47:28 by yuonishi		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static int	search_closest_larger_index(t_stack *stack_a, int b_value)
{
	t_node	*current;
	int		target_index;
	int		closest_value;
	int		i;

	target_index = -1;
	current = stack_a->top;
	i = 0;
	while (current)
	{
		if (current->value > b_value)
		{
			if (target_index == -1 || current->value < closest_value)
			{
				closest_value = current->value;
				target_index = i;
			}
		}
		current = current->next;
		i++;
	}
	return (target_index);
}

static int	get_min_index(t_stack *stack_a)
{
	t_node	*current;
	int		min_value;
	int		min_index;
	int		i;

	min_value = stack_a->top->value;
	min_index = 0;
	current = stack_a->top;
	i = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

int	get_target_index(t_stack *stack_a, int b_value)
{
	int	target_index;

	if (!stack_a->top)
		return (0);
	target_index = search_closest_larger_index(stack_a, b_value);
	if (target_index != -1)
		return (target_index);
	return (get_min_index(stack_a));
}
