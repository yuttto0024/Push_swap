#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int			 value;
	int			 rank;
	struct s_node   *pre;
	struct s_node   *next;
}			   t_node;

typedef struct s_stack
{
	t_node  *top;
	t_node  *bottom;
	int	 size;
}			   t_stack;

t_node  *make_node(int content)
{
	t_node  *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = content;
	node->rank = -1;
	node->pre = NULL;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;

	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		new_node->pre = NULL;
		new_node->next = NULL;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->pre = stack->bottom;
		new_node->next = NULL;
		stack->bottom = new_node;
	}
	stack->size++;
}

void	debug_print_forward(t_stack *stack)
{
	t_node  *current;

	current = stack->top;
	printf("Forward (Top -> Bottom)\n");
	while (current)
	{
		printf("[%d]", current->value);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf("\n\n");
}

void	debug_print_backward(t_stack *stack)
{
	t_node  *current;

	current = stack->bottom;
	printf("Backward (Bottom -> Top)\n");
	while (current)
	{
		printf("[%d]", current->value);
		if (current->pre)
			printf(" -> ");
		current = current->pre;
	}
	printf("\n\n");
}

int main(void)
{
	t_stack stack;

	stack.top = NULL;
	stack.bottom = NULL;
	stack.size = 0;

	add_node_back(&stack, make_node_node(10));
	printf("Size: %d (Top: %d, Bottom: %d)\n", stack.size, stack.top->value, stack.bottom->value);

	add_node_back(&stack, make_node(20));
	printf("Size: %d (Top: %d, Bottom: %d)\n", stack.size, stack.top->value, stack.bottom->value);

	add_node_back(&stack, make_node(30));
	printf("Size: %d (Top: %d, Bottom: %d)\n", stack.size, stack.top->value, stack.bottom->value);

	printf("\n");
	debug_print_forward(&stack);
	debug_print_backward(&stack);

	return (0);
}
