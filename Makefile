CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
OBJS_DIR	= bin
INCLUDES	= -I./includes -I./libft
LIBS		= -L./libft -lft
TESTS_DIR	= tests

SRCS		=	$(SRCS_DIR)/ft_printf.c 
				
TESTS_SRCS	= $(TESTS_DIR)/*.c

OBJS		:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
TESTS_OBJS	:= $(patsubst $(TESTS_DIR)/%.c, $(TESTS_DIR)/%.o, $(TESTS_SRCS))
NAME		= ft_printf.a
TEST_NAME	= $(TESTS_DIR)/test

$(NAME):	$(OBJS)
			make -C ./libft
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

$(TESTS_DIR)/%.o:	$(TESTS_DIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -c

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
					$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -c

re:			fclean $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			rm -f $(NAME)

test:		all $(TESTS_OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(TEST_NAME) $(TESTS_OBJS) $(OBJS)
			./$(TEST_NAME)

retest:		fclean
			rm -f $(TEST_NAME)
			make test
			

.PHONY:		all re clean fclean bin test
