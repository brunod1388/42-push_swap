CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	=	printf/ft_flag_process.c \
			printf/ft_flag_process2.c \
			printf/ft_type_process.c \
			printf/ft_type_process2.c \
			printf/ft_printf_utils.c \
			ft_printf.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strcpy.c \
			ft_strcat.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_ultoa.c \
			ft_uitoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putnbr_base.c \
			lst/ft_lstnew.c \
			lst/ft_lstadd_front.c \
			lst/ft_lstsize.c \
			lst/ft_lstlast.c \
			lst/ft_lstadd_back.c \
			lst/ft_lstdelone.c \
			lst/ft_lstclear.c \
			lst/ft_lstiter.c \
			lst/ft_lstmap.c \
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
			$(RM) *.o

fclean:		clean
			$(RM) $(NAME)

.PHONY:		all re clean fclean bin cleantest test
