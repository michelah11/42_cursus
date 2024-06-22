NAME = libftprintf.a
INCLUDE = include
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

SRC_FILES = ft_printf ft_printf_utils ft_puthex_pf ft_putptr_pf ft_putuint_pf 

SRC = $(addprefix $(SRC_DIR),$(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR),$(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT)
		cp libft/libft.a .
		mv libft.a $(NAME)
		$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -rf $(OBJ_DIR) $(OBJF)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f $(LIBFT)/libft.a

re:			fclean all
       
.PHONY:		all clean fclean re 