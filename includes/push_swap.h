#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft.h"
# include "ft_printf.h"

// array
typedef struct s_array
{
	int	*data;
	int	top;
	int	size;
	int	length;
}				t_array;

// Linked List
typedef struct s_node
{
	int				value;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}				t_stack;

t_node	*make_node(int content);
void	add_node_back(t_stack *stack, t_node *new_node);
void	init_stack_a(t_stack *stack, char **argv, int argc);
void	free_strs(char **strs);
void	free_stack(t_stack *stack);
void	error_exit(t_stack *stack, char **strs, int argc);
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	push(t_stack *stack_x, t_stack *stack_y);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	sort_three(t_stack *a);

#endif