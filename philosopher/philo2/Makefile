NAME		=	philo

FLAGS		=	-Wall -Werror -Wextra# -g3 -fsanitize=thread
# LEAKS CHECK -fsanitize=address
CC			=	cc
RM			=	rm -rf

PHILO_SRCS	=  philo.c \
				action_eat.c \
				action_fork.c \
				action_sleep.c \
				check_arg.c \
				check_philo.c \
				error_philo.c \
				philo_to_job.c \
				set_mutex.c \
				set_philo.c \
				set_table.c \
				start_philo.c \
				state_print.c \
				util_all_free.c \
				util_destroy_mutex.c \
				util_detach.c \
				util_ft_atoi.c \
				util_thread_pause.c \
				util_times.c \
				utils.c

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
