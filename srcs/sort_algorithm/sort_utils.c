#include "push_swap.h"

void	bubble_sort_array_ascending(int *arr, int size)
{
	int i;
	int j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < (size - 1) - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[i] = arr[j];
				arr[j] = tmp;
			};
			j++;
		}
		i++;
	}
}

int	*build_sorted_reference(t_stack *stack_a, int size)
{
	int		*sorted_refs;
	t_node	*current;
	int		i;

	sorted_refs = (int *)malloc(sizeof(int) * size);
	if (!sorted_refs)
		return (NULL);
	current = stack_a->top;
	i = 0;
	while (i < size && current)
	{
		sorted_refs[i] = current->value;
		current = current->next;
		i++;
	}
	return (sorted_refs);
}