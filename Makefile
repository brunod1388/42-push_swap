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
			src/ft_utils2.c

SRCS_PS = 	ft_push_swap.c \
				$(SRCS)

SRCS_TESTER	=	ft_tester.c \
				$(SRCS)

SRCS_CHECKER =	ft_checker.c \
				$(SRCS)

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
OBJS_TESTER = $(SRCS_TESTER:.c=.o)
_BLUE=\e[34m
_PURPLE=\e[35m
_CYAN=\e[36m
_END=\e[0m

$(NAME):	
			$(MAKE) -C ./libft
			@$(CC) $(FLAGS) $(SRCS_PS) $(LIBS) -o $(NAME)
			@printf "push_swap	[$(_BLUE)✓$(_END)]\n"

all : 		$(NAME)

bonus :		$(NAME)

re:			clean
			$(MAKE) $(NAME)

clean :
			@printf "$(_PURPLE)Object cleaning...$(_END)\n"
			@rm -rf $(OBJS) $(NAME)

fclean :	clean
			$(MAKE) fclean -C ./libft
			@rm -rf $(NAME)
			@printf "$(_PURPLE)push_swap	deleted$(_END)\n"

checker :
			@$(MAKE) -C ./libft
			@$(CC) $(FLAGS) $(SRCS_CHECKER) $(LIBS) -o checker
			@printf "checker		[$(_BLUE)✓$(_END)]\n"

recheck :
			@rm -f checker
			@printf "$(_PURPLE)checker deleted!$(_END)\n"
			@make checker

tester :
			@$(MAKE) -C ./libft
			@$(CC) $(FLAGS) $(SRCS_TESTER) $(LIBS) -o tester
			@printf "tester		[$(_BLUE)✓$(_END)]\n"


retest :
			@rm -f tester
			@printf "$(_PURPLE)tester deleted$(_END)\n"
			make tester

full :		all
			@$(CC) $(FLAGS) $(SRCS_PS) $(LIBS) -o $(NAME)
			@printf "push_swap	[$(_BLUE)✓$(_END)]\n"
			@$(CC) $(FLAGS) $(SRCS_TESTER) $(LIBS) -o tester
			@printf "tester		[$(_BLUE)✓$(_END)]\n"
			@$(CC) $(FLAGS) $(SRCS_CHECKER) $(LIBS) -o checker
			@printf "checker		[$(_BLUE)✓$(_END)]\n"

ffclean :	fclean
			@rm -f checker
			@printf "$(_PURPLE)checker		deleted$(_END)\n"
			@rm -f tester
			@printf "$(_PURPLE)tester		deleted$(_END)\n"


PHONY : fclean all re clean tester retest