NAME = libft.a
INCLUDES = -I../include
SRCS_DIR = src/
OBJS_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
AR = ar rcs

FT_BONUS = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
	ft_lstlast ft_lstnew ft_lstsize ft_lstiter ft_lstmap

FT = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
	ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
	ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr \
	ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi \
	ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
	ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd \
	ft_putendl_fd ft_putnbr_fd

SRCS = $(addprefix $(SRCS_DIR),$(addsuffix .c, $(FT)))
OBJS = $(addprefix $(OBJS_DIR),$(addsuffix .o, $(FT)))

BONUS_SRCS = $(addprefix $(SRCS_DIR),$(addsuffix .c, $(FT_BONUS)))
BONUS_OBJS = $(addprefix $(OBJS_DIR),$(addsuffix .o, $(FT_BONUS)))

OBJSF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):	
	@mkdir -p $(OBJS_DIR)
	@touch $(OBJSF)

clean:
	$(RM) -rf $(OBJS_DIR) $(BONUS_OBJS) $(OBJSF)

fclean: clean
	$(RM) -f $(NAME)

re:			fclean all
       
.PHONY:		all bonus clean fclean re 
