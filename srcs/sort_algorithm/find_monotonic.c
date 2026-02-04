#include "push_swap.h"

int	get_asc_length(t_stack *stack)
{
	t_node	*current;
	int		len;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	len = 1;
	while (current->next)
	{
		if (current->value < current->next->value)
		{
			len++;
			current = current->next;
		}
		else
			break ;
	}
	return (len);
}

int	get_desc_length(t_stack *stack)
{
	t_node  *current;
	int		len;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	len = 1; 
	while (current->next)
	{
		if (current->value > current->next->value)
        {
            len++;
            current = current->next;
		}
		else
			break ;
	}
	return (len);
}
