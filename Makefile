LIBFT	= ./libft/libft.a
LIBS	= -L./libft -lft

NAME	=	push_swap
SRCS	=	ft_push_swap.c \
			src/ft_ps_operations.c \
			src/ft_ps_process.c \
			src/ft_ps_utils.c \
			src/ft_ps_solve.c \
			src/ft_ps_solve_big.c \
			src/ft_printstacks.c

TEST_DL		=	test_dl
TEST_DLSRCS	=	.tests/ft_dl_test.c
TEST_DLOBJS	=	$(TEST_DLSRCS:.c=.o)

TEST_PSSRCS	=	.tests/ft_push_swap_test.c \
				src/ft_ps_operations.c \
				src/ft_ps_process.c \
				src/ft_printstacks.c
TEST_DLOBJS	=	$(TEST_PSSRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME):	
			$(MAKE) -C ./libft
			$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME) 

all : 		$(NAME)

bonus :		$(NAME)

re:			clean 
			$(MAKE) $(NAME)

clean :
			rm -rf $(OBJS) $(NAME)

fclean :	clean
			$(MAKE) fclean -C ./libft
			rm -rf $(NAME)

pstest:		$(TEST_PSOBJS)
			$(MAKE) -C ./libft
			rm -f $(TEST_DL)
			$(CC) $(FLAGS) $(TEST_PSSRCS) $(LIBS) -o push_swap_test 

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