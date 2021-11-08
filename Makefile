CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
INCLUDES	= -I./includes -I./libft
LIBS		= -L./libft -lft
TESTS_DIR	= tests

SRCS		=	$(SRCS_DIR)/ft_flag_process.c \
				$(SRCS_DIR)/ft_flag_process2.c \
				$(SRCS_DIR)/ft_type_process.c \
				$(SRCS_DIR)/ft_type_process2.c \
				$(SRCS_DIR)/ft_printf_utils.c \
				$(SRCS_DIR)/ft_printf.c

OBJS		= ${SRCS:.c=.o}
# NAME		= ft_printf.a
NAME		= libftprintf.a


TEST_NAME	= $(TESTS_DIR)/test
TESTS_SRCS	= $(TESTS_DIR)/printf_test.c

$(NAME):	$(OBJS)
			make -C ./libft
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

.c.o:
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o ${<:.c=.o}

all:		$(NAME)

re:			fclean $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			rm -f $(NAME)

test:		$(OBJS)
			make -C ./libft
			$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(TEST_NAME) $(OBJS) $(TESTS_SRCS)
			./$(TEST_NAME)

retest:		fclean
			rm -f $(TEST_NAME)
			make test

.PHONY:		all re clean fclean test
