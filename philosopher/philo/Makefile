NAME		=	philo

FLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=thread
# LEAKS CHECK -fsanitize=address -fsanitize=thread
CC			=	cc
RM			=	rm -rf

PHILO_SRCS	= main.c \
				action.c \
				check_arg.c \
				init.c \
				parser.c \
				start_philo.c \
				state_print.c \
				utils_lib_1.c \
				utils_lib_2.c \
				utils_lib_3.c

DIR_OBJS	=	obj
DIR_SRCS	=	src

PHILO_OBJS		=	$(PHILO_SRCS:.c=.o)

SRCS		=	$(addprefix $(DIR_SRCS)/,$(PHILO_SRCS))
OBJS		=	$(addprefix $(DIR_OBJS)/,$(PHILO_OBJS))

all					:	$(NAME)


$(NAME)				:	$(OBJS)
			$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o		:	$(DIR_SRCS)/%.c Makefile | $(DIR_OBJS)
			$(CC) $(FLAGS) -c $< -o $@

$(DIR_OBJS)			:
			mkdir -p $@

clean				:
			$(RM) $(DIR_OBJS)

fclean				:
			$(RM) $(DIR_OBJS)
			$(RM) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
