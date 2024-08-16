NAME = fdf
LIBFT = libft/
GNL = get_next_line/
MLX = minilibx/
LIBFT_A = $(addprefix $(LIBFT), libft.a)
GNL_A = $(addprefix $(GNL), gnl.a)
MLX_A = $(addprefix $(MLX), mlx.a)

CC = gcc
INCLUDE = includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
RM = rm -f
SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
		@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lX11 -lXext -lm -o $(NAME)
		@echo "Linked into executable."

$(LIBFT_A):
		@$(MAKE) -s -C $(LIBFT)
		@echo "Compiled $(LIBFT_A)"

$(GNL_A):
		@$(MAKE) -s -C $(GNL)
		@echo "Compiled $(GNL_A)"

$(MLX_A):
		@$(MAKE) -s -C $(MLX)
		@echo "Compiled $(MLX_A)"

bonus:	all

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		@echo "Compiling $<."

localclean:
		@$(RM) $(OBJS)
		@echo "Removed object files."

clean: localclean
		@$(MAKE) clean -s -C $(LIBFT)
		@echo "Clean libft."
		@$(MAKE) clean -s -C $(GNL)
		@echo "Clean gnl."
		@$(MAKE) clean -s -C $(MLX)
		@echo "Clean mlx."
		

fclean: localclean
		@$(MAKE) fclean -s -C $(LIBFT)
		@echo "Full clean libft."
		@$(MAKE) fclean -s -C $(GNL)
		@echo "Full clean gnl."
		@$(MAKE) clean -s -C $(MLX)
		@echo "Clean mlx."
		@$(RM) $(NAME)
		@echo "Removed executable"

re:		fclean all

.PHONY:	all clean fclean re localclean bonus