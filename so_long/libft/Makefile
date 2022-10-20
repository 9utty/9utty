.SUFFIXES : .c .o
SRCS			=	ft_atoi.c ft_itoa.c ft_split.c ft_bzero.c ft_calloc.c \
					ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
					ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
					ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
					ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS			=	$(SRCS:.c=.o)

AR				=	ar
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	libft.a

all:			$(NAME)

bonus:
				@make bonus=1 all

ifdef bonus
$(NAME):		$(OBJS) $(OBJS_B)
				$(AR) rcs $(NAME) $(OBJS) $(OBJS_B)
else
$(NAME):		$(OBJS)
				$(AR) rcs $(NAME) $(OBJS)
endif

clean:
				$(RM) $(OBJS) $(OBJS_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
