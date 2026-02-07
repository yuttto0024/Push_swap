/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:43:23 by yuonishi          #+#    #+#             */
/*   Updated: 2026/02/07 14:18:17 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	calculate_process_cost(int size_a, int size_b, int ia, int ib)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_mixed;
	int	rev_ia;
	int	rev_ib;

	cost_rr = get_max_index(ia, ib);
	rev_ia = size_a - ia;
	if (ia == 0)
		rev_ia = 0;
	rev_ib = size_b - ib;
	if (ib == 0)
		rev_ib = 0;
	cost_rrr = get_max_index(rev_ia, rev_ib);
	cost_mixed = ia + rev_ib;
	if ((rev_ia + ib) < cost_mixed)
		cost_mixed = rev_ia + ib;
	if (cost_rr <= cost_rrr && cost_rr <= cost_mixed)
		return (cost_rr);
	if (cost_rrr <= cost_rr && cost_rrr <= cost_mixed)
		return (cost_rrr);
	return (cost_mixed);
}
