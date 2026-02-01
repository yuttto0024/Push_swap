#include "push_swap.h"

int main(void)
{
    // 1. Libft_test
    if (ft_strlen("Hello") == 5)
        ft_printf("Libft is linked\n");

    // 2. ft_printf_test
    ft_printf("ft_printf is working!\n");

    // 3. stack_test
    t_stack	stack;
    stack.size = 0;
    ft_printf("Stack initialized. Size: %d\n", stack.size);

    return (0);
}