LIBFT	= ./libft/libft.a
LIBS	= -L./libft -lft

NAME	=	push_swap
SRCS	=	ft_push_swap.c \
			src/ft_ps_operations.c \
			src/ft_ps_utils.c

TEST_DL		=	test_dl
TEST_DLSRCS	=	tests/ft_dl_test.c
TEST_DLOBJS	=	$(TEST_SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME):	
			$(MAKE) -C ./libft
			$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME) 

all : 		$(NAME)

bonus :		$(NAME)

re:			fclean $(NAME)

clean :
			$(MAKE) clean -C ./libft
			rm -rf $(OBJS)

fclean :	clean
			$(MAKE) fclean -C ./libft
			rm -rf $(NAME)

dltest:		$(TEST_DLOBJS)
			$(MAKE) -C ./libft
			rm -f $(TEST_DL)
			$(CC) $(FLAGS) $(TEST_DLSRCS) $(LIBS) -o $(TEST_DL) 

# test:		$(OBJS)
# 			make -C ./libft
# 			$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(TEST_NAME) $(OBJS) $(TESTS_SRCS)
# 			./$(TEST_NAME)

# retest:		fclean
# 			rm -f $(TEST_NAME)
# 			make test

PHONY : fclean all test re