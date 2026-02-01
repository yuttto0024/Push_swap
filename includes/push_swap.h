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

t_node	*new_node(int content);

#endif