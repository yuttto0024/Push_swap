NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRCDIR		= srcs
INCDIR		= includes
OBJDIR		= objs
LIBFT_DIR	= ./libft
PRINTF_DIR	= ./ft_printf

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a

IFLAGS		= -I $(INCDIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)/includes
LFLAGS		= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

SRCS_NAME   = main.c \
              stack/list/make_node.c \
              stack/list/add_node_back.c \
			  stack/list/init_stack.c \
			  stack/list/clean_stack.c \
			  command/swap.c \
			  command/swap_command.c \
			  command/push.c \
			  command/push_command.c \
			  command/rotate.c \
			  command/rotate_command.c \
			  command/reverse_rotate.c \
			  command/reverse_rotate_command.c \
			  sort_algorithm/sort_three.c \
			  sort_algorithm/sort_orchestrator.c \
			  sort_algorithm/is_sorted.c \
			  sort_algorithm/search_index.c \
			  sort_algorithm/cost_utils.c \
			  sort_algorithm/execute_optimal_rotation_and_push.c \
			  sort_algorithm/greedy_solver.c \
			  sort_algorithm/sort_utils.c \

SRCS		= $(addprefix $(SRCDIR)/, $(SRCS_NAME))
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS_NAME:.c=.o))

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re