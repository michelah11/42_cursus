# Makefile

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)
DEPS = pipex.h

LIBFT = ./libft/libft.a

# Targets
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft

clean:
	@$(RM) $(OBJS)
	@make -C ./libft clean

fclean: clean
	@$(RM) $(NAME)
	@make -C ./libft fclean

re: fclean all

