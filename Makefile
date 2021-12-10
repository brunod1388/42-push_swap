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

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

$(NAME):	
			$(MAKE) -C ./libft
			@$(CC) $(FLAGS) $(SRCS_PS) $(LIBS) -o $(NAME)
			@printf "push_swap	[$(_GREEN)✓$(_END)]\n"

all : 		$(NAME)

bonus :		$(NAME)

re:			clean
			$(MAKE) $(NAME)

clean :
			@printf "$(_YELLOW)Object cleaning...$(_END)\n"
			@rm -rf $(OBJS) $(NAME)

fclean :	clean
			$(MAKE) fclean -C ./libft
			@rm -rf $(NAME)
			@printf "$(_YELLOW)push_swap deleted!$(_END)\n"

checker :
			@$(MAKE) -C ./libft
			@$(CC) $(FLAGS) $(SRCS_CHECKER) $(LIBS) -o checker
			@printf "checker		[$(_GREEN)✓$(_END)]\n"

recheck :
			@rm -f checker
			@printf "$(_YELLOW)checker deleted!$(_END)\n"
			@make checker

tester :
			@$(MAKE) -C ./libft
			@$(CC) $(FLAGS) $(SRCS_TESTER) $(LIBS) -o tester
			@printf "tester		[$(_GREEN)✓$(_END)]\n"


retest :
			@rm -f tester
			@printf "$(_YELLOW)tester deleted$(_END)\n"
			make tester

full :		all tester checker

ffclean :	clean
			$(MAKE) fclean -C ./libft
			@rm -f push_swap
			@printf "$(_YELLOW)push_swap	deleted$(_END)\n"
			@rm -f checker
			@printf "$(_YELLOW)checker		deleted$(_END)\n"
			@rm -f tester
			@printf "$(_YELLOW)tester		deleted$(_END)\n"


PHONY : fclean all re clean tester retest