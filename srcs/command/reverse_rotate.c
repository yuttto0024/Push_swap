/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:06:32 by yuonishi          #+#    #+#             */
/*   Updated: 2026/02/07 14:13:17 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*last_second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	last_second = last->pre;
	stack->top = last;
	last->pre = NULL;
	last->next = first;
	first->pre = last;
	stack->bottom = last_second;
	last_second->next = NULL;
}
