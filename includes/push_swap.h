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
	int				rank;
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

#endif