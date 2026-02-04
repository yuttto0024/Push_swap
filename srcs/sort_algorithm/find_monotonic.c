int	get_asc_length(t_stack *stack)
{
	t_node	*current;
	int		count;

	if (!sta)
		return ;
	current = stack->top;
	count = 1;
	while (current)
	{
		if (current->value < current->next->value)
		{
			count++;
			current = current->next;
		}
		else
			break ;
	}
	return (count);
}

int	get_desc_length(t_stack *stack)
{
	t_node  *current;
	int		count;

	if (!stack || !stack->top)
		return (0);
    
	current = stack->top;
	count = 1; 
	while (current->next)
	{
		if (current->value > current->next->value)
        {
            count++;
            current = current->next;
		}
		else
			break ;
	}
	return (count);
}