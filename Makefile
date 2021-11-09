LIBFT	= ./libft/libft.a
LIBS	= -L./libft -lft

NAME = libftprintf.a
#NAME = ft_printf.a
SRCS =	ft_flag_process.c \
		ft_flag_process2.c \
		ft_type_process.c \
		ft_type_process2.c \
		ft_printf_utils.c \
		ft_printf.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

TESTS_DIR	= tests
TEST_NAME	= $(TESTS_DIR)/test
TESTS_SRCS	= $(TESTS_DIR)/printf_test.c

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
			ar -rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all : 		$(NAME)

bonus :		$(NAME)

re:			fclean $(NAME)

clean :
			$(MAKE) clean -C ./libft
			rm -rf $(OBJS)

fclean :	clean
			$(MAKE) fclean -C ./libft
			rm -rf $(NAME)

test:		$(OBJS)
			make -C ./libft
			$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(TEST_NAME) $(OBJS) $(TESTS_SRCS)
			./$(TEST_NAME)

retest:		fclean
			rm -f $(TEST_NAME)
			make test

re : fclean all