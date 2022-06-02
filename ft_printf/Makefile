CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_print_csp.c ft_print_nbr.c
SRCS_BONUS = ft_printf_bonus.c ft_printf_utils_bonus.c \
			 ft_print_csp_bonus.c ft_print_nbr_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar cr $(NAME) $(OBJS_BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
