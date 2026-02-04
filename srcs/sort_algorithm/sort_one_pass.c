#include "push_swap.h"

static int  min_int(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

static int	move_run_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int len_desc;
    int len_asc;
	int	i;

	len_desc = get_desc_len(stack_a);
    len_asc = get_asc_len(stack_a);
	if (len_desc >= len_asc)	
    {
        i = 0;
        while (i < len_desc)
        {
            pb(stack_b, stack_a);
            i++;
        }
        return (len_desc);
    }
    else
    {
        i = 0;
        while (i < len_asc)
        {
            pb(stack_b, stack_a);
            rb(stack_b);
            i++;
        }
        return (len_asc);
    }
}

void	sort_one_pass(t_stack *stack_a,t_stack *stack_b)
{
	int	init_count;
	int	len_a;
	int	len_b;

	init_count = stack_a->size;
	while (init_count > 0)
	{
		len_b = move_run_to_b(stack_a, stack_b);
		init_count -= len_b;
		len_a = 0;
		if (init_count > 0)
		{
			len_a = min_int(len_a, init_count);
			init_count -= len_a;
		}
		merge_len_in_a(stack_a, stack_b, len_a, len_b);
	}
}
