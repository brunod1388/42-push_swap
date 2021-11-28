CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	=	printf/ft_flag_process.c \
			printf/ft_flag_process2.c \
			printf/ft_type_process.c \
			printf/ft_type_process2.c \
			printf/ft_printf_utils.c \
			printf/ft_printf.c \
			sort/ft_bubsort.c \
			sort/ft_quicksort.c \
			utils/ft_printarray.c \
			math/ft_sqrt.c \
			math/ft_abs.c \
			ftc/ft_isalpha.c \
			ftc/ft_swap.c \
			ftc/ft_isdigit.c \
			ftc/ft_isalnum.c \
			ftc/ft_isascii.c \
			ftc/ft_isprint.c \
			ftc/ft_strlen.c \
			ftc/ft_memset.c \
			ftc/ft_bzero.c \
			ftc/ft_memcpy.c \
			ftc/ft_memmove.c \
			ftc/ft_strcpy.c \
			ftc/ft_strcat.c \
			ftc/ft_tolower.c \
			ftc/ft_toupper.c \
			ftc/ft_strchr.c \
			ftc/ft_strrchr.c \
			ftc/ft_strncmp.c \
			ftc/ft_memchr.c \
			ftc/ft_memcmp.c \
			ftc/ft_strnstr.c \
			ftc/ft_atoi.c \
			ftc/ft_calloc.c \
			ftc/ft_strdup.c \
			ftc/ft_substr.c \
			ftc/ft_strjoin.c \
			ftc/ft_strtrim.c \
			ftc/ft_split.c \
			ftc/ft_itoa.c \
			ftc/ft_ultoa.c \
			ftc/ft_uitoa.c \
			ftc/ft_strmapi.c \
			ftc/ft_striteri.c \
			ftc/ft_putchar.c \
			ftc/ft_putstr.c \
			ftc/ft_putendl.c \
			ftc/ft_putnbr.c \
			ftc/ft_putnbr_base.c \
			lst/ft_lstnew.c \
			lst/ft_lstadd_front.c \
			lst/ft_lstsize.c \
			lst/ft_lstlast.c \
			lst/ft_lstadd_back.c \
			lst/ft_lstdelone.c \
			lst/ft_lstclear.c \
			lst/ft_lstiter.c \
			lst/ft_lstmap.c \
			dlst/ft_dlst.c \
			dlst/ft_dlstnode.c \
			dlst/ft_dlst_utils.c \
			get_next_line.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

RM		= rm -f

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

re:			fclean $(NAME)

clean:		
			$(RM) *.o ftc/*.o printf/*.o lst/*.o dlst/*.o

fclean:		clean
			$(RM) $(NAME)

.PHONY:		all re clean fclean bin cleantest test
