NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR      = srcs
INCDIR      = includes
OBJDIR      = objs

SRCS_NAME = \
	ft_printf.c \
	ft_print_text.c \
	ft_putnbr.c \
	ft_putnbr_unsigned.c \
	ft_puthex.c \
	ft_putptr.c \

OBJS_NAME   = $(SRCS_NAME:.c=.o)

SRCS        = $(addprefix $(SRCDIR)/, $(SRCS_NAME))
OBJS        = $(addprefix $(OBJDIR)/, $(OBJS_NAME))

IFLAGS      = -I $(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re