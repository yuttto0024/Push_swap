#include "push_swap.h"
//#include <stdio.h>
//#include <stdlib.h>

/*
typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;
*/

t_node	*make_node(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->pre = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*
int	main(void)
{
	t_node	*node;

	node = make_node(42);
	if (!node)
		return (1);
	printf("Value: %d\n", node->value);
	printf("Rank: %d\n", node->rank);
	if (!node->pre)
		printf("pre: NULL\n");
	if (!node->next)
		printf("next: NULL\n");
	free(node);
}
*/
