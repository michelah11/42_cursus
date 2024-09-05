CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf

SRCS_DIR = srcs/
OBJS_DIR = objs/
LIBFT_DIR = libft/
GNL_DIR = get_next_line/
MLX_DIR = minilibx/

LIBFT_A = $(LIBFT_DIR)libft.a
GNL_A = $(GNL_DIR)gnl.a
MLX_A = $(MLX_DIR)mlx.a

SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))

NAME = fdf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd -o $(NAME)
	@echo "Linked into executable $(NAME)."

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "Compiled $(LIBFT_A)."

$(GNL_A):
	@$(MAKE) -s -C $(GNL_DIR)
	@echo "Compiled $(GNL_A)."

$(MLX_A):
	@@$(MAKE) -s -C $(MLX_DIR)
	@echo "Compiled $(MLX_A)."

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

localclean:
	@$(RM) $(OBJS)
	@echo "Removed object files."

clean: localclean
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@$(MAKE) clean -s -C $(GNL_DIR)
	@$(MAKE) clean -s -C $(MLX_DIR)
	@echo "Cleaned all libraries."

fclean:
	@$(RM) $(NAME)
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@$(MAKE) fclean -s -C $(GNL_DIR)
	@$(MAKE) clean -s -C $(MLX_DIR)
	@echo "Removed executable $(NAME)."

re: fclean all

.PHONY: all clean fclean re localclean
