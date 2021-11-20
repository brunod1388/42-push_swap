LIBFT	= ./libft/libft.a
LIBS	= -L./libft -lft

NAME = push_swap
SRCS =	ft_push_swap.c

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

test:		
			rm $(NAME)
			make

# test:		$(OBJS)
# 			make -C ./libft
# 			$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(TEST_NAME) $(OBJS) $(TESTS_SRCS)
# 			./$(TEST_NAME)

# retest:		fclean
# 			rm -f $(TEST_NAME)
# 			make test

re : fclean all