CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
OBJS_DIR	= bin
INCLUDES	= -I./includes
TESTS_DIR	= tests

SRCS		= $(SRCS_DIR)/*.c
OBJS		= ${$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o}
TESTS		= $(TESTS_DIR)/*.c
NAME		= ft_printf.a
TEST_NAME	= test

$(NAME):	$(OBJS)
			$(MAKE) bonus -C ./libft
			ar -rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

re:			fclean $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			rm -f $(NAME)

test:		$(NAME)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

retest:		fclean $(TEST)
			rm ./test/test
			make re
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)
			./test/test

.PHONY:		all re clean fclean bin test
