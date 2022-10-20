.SUFFIXES : .c .o
SRCS			=	get_next_line_utils.c \
					get_next_line.c

OBJS			=	$(SRCS:.c=.o)

SRCS_B			=

OBJS_B			=	$(SRCS_B:.c=.o)

AR				=	ar
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	gnl.a

all:			$(NAME)

bonus:
				make bonus=1 all

ifdef bonus
$(NAME):		$(OBJS) $(OBJS_B)
				$(AR) rcs $(NAME) $(OBJS) $(OBJS_B)
else
$(NAME):		$(OBJS)
				$(AR) rcs $(NAME) $(OBJS) -I ../includes/get_next_line.h
endif

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
