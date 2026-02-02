#include "push_swap.h"
#include <stdlib.h>

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	error_exit(t_stack *stack, char **strs, int argc)
{	
	if (stack)
		free_stack(stack);
	if (argc == 2 && strs)
		free_strs(strs);
	ft_printf("Error\n");
	exit(1);
}
