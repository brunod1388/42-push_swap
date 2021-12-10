LIBFT	= ./libft/libft.a
LIBS	= -L./libft -lft

NAME	=	push_swap


SRCS	=	src/ft_operations.c \
			src/ft_parsing.c \
			src/ft_utils.c \
			src/ft_solve.c \
			src/ft_solve_big.c \
			src/ft_printstacks.c \
			src/ft_opti.c \
			src/ft_opti2.c

SRCS_PS = 	ft_push_swap.c \
				$(SRCS)

SRCS_TESTER	=	tester.c \
				$(SRCS)

SRCS_CHECKER =	checker.c \
				$(SRCS)

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
OBJS_TESTER = $(SRCS_TESTER:.c=.o)

$(NAME):	
			$(MAKE) -C ./libft
			$(CC) $(FLAGS) $(SRCS_PS) $(LIBS) -o $(NAME)

all : 		$(NAME)

bonus :		$(NAME)

re:			clean 
			$(MAKE) $(NAME)

clean :
			rm -rf $(OBJS) $(NAME)

fclean :	clean
			$(MAKE) fclean -C ./libft
			rm -rf $(NAME)

checker :
			$(MAKE) -C ./libft
			$(CC) $(FLAGS) $(SRCS_CHECKER) $(LIBS) -o checker

recheck :
			rm -f checker
			make checker
tester :
			$(MAKE) -C ./libft
			$(CC) $(FLAGS) $(SRCS_TESTER) $(LIBS) -o tester

retest :
			rm -f tester
			make tester

PHONY : fclean all re clean tester retest