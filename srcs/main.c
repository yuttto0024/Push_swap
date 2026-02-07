/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:16:19 by yuonishi          #+#    #+#             */
/*   Updated: 2026/02/07 14:09:40 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_stack_structs(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->size = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_b->size = 0;
}

static char	**process_input_arguments(int argc, char **argv,\
								int *should_free_memory)
{
	char	**arguments;

	*should_free_memory = 0;
	if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		if (!arguments)
			return (NULL);
		*should_free_memory = 1;
		return (arguments);
	}
	return (argv + 1);
}

static void	execute_sorting_strategy(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else
		sort_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**arguments;
	int		should_free_memory;

	if (argc < 2)
		return (0);
	initialize_stack_structs(&stack_a, &stack_b);
	arguments = process_input_arguments(argc, argv, &should_free_memory);
	if (!arguments)
		return (1);
	init_stack_a(&stack_a, arguments, argc);
	if (should_free_memory)
		free_strs(arguments);
	execute_sorting_strategy(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
