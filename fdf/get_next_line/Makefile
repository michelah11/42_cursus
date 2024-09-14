NAME = libgnl.a
INCLUDES = -I../includes
LIBFT = ../libft
SRCS_DIR = src/
OBJS_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
AR = ar rcs

GNL = get_next_line

SRCS = $(addprefix $(SRCS_DIR),$(addsuffix .c, $(GNL)))
OBJS = $(addprefix $(OBJS_DIR),$(addsuffix .o, $(GNL)))


OBJSF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C $(LIBFT)
	@cp ../libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):	
	@mkdir -p $(OBJS_DIR)
	@touch $(OBJSF)

clean:
	@$(RM) -rf $(OBJS_DIR) $(OBJSF)

fclean: clean
	@$(RM) -f $(NAME)

re:			fclean all
       
.PHONY:		all bonus clean fclean re 
