CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = main.c errors.c push_command.c node_a_init.c \
       node_b_init.c push_swap_command.c \
       reverse_rotate_command.c rotate_command.c \
       split.c stack_init.c stack_utils.c swap_command.c \
       tiny_sort.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
