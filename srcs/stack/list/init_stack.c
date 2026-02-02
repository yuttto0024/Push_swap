#include "push_swap.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++ ;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_limit(char *str, int sign)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	if (sign == 1)
		return (ft_strncmp(str, "2147483647", 10) <= 0);
	else
		return (ft_strncmp(str, "2147483648", 10) <= 0);
}

static int	is_int_range(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0' && str[i + 1])
		i++;
	return (check_limit(&str[i], sign));
}

void	free_error_stack(t_stack *stack)
{
	(void)stack;
	ft_printf("Error\n");
	exit(1);
}

int	has_duplicate(t_stack *stack, int n)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == n)
			return (1);
		current = current->next;
	}
	return (0);
}

void	init_stack_a(t_stack *stack, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!is_numeric(argv[i]))
			free_error_stack(stack);
		if (!is_int_range(argv[i]))
			free_error_stack(stack);
		n = ft_atoi(argv[i]);
		if (has_duplicate(stack, (int)n))
			free_error_stack(stack);
		add_node_back(stack, make_node((int)n));
		i++;
	}
}
