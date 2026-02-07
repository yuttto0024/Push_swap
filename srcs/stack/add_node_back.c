/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:13:49 by yuonishi          #+#    #+#             */
/*   Updated: 2026/02/07 14:13:52 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		new_node->pre = NULL;
		new_node->next = NULL;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->pre = stack->bottom;
		new_node->next = NULL;
		stack->bottom = new_node;
	}
	stack->size++;
}
