#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
    t_node  *current;

    if (!stack || !stack->top)
        return (1);
    current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}
