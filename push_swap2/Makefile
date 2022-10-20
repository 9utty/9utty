NAME		=	push_swap
NAME_B		=	checker

FLAGS		=	-Wall -Werror -Wextra
CC			=	cc
RM			=	rm -rf

PU_SRCS		= push_swap.c \
				arg_validation.c error.c \
				ft_atoi.c ft_split.c \
				init_index.c init_stack.c \
				is_utils.c libft_utils.c \
				libft_utils_2.c num_validation.c \
				order_sort.c push_sort.c \
				small_sorting.c sort_utils.c \
				stack_utils.c push.c \
				rotation.c swap.c \
				revers_rotation.c \
				sort_check.c

PU_SRCS_B	= checker_bonus.c\
				read_bonus.c \
				arg_validation_bonus.c \
				error_bonus.c \
				ft_atoi_bonus.c \
				ft_split_bonus.c \
				init_index_bonus.c \
				init_stack_bonus.c \
				is_utils_bonus.c \
				libft_utils_bonus.c \
				libft_utils_2_bonus.c \
				num_validation_bonus.c \
				order_sort_bonus.c \
				sort_utils_bonus.c \
				push_bonus.c \
				rotation_bonus.c \
				swap_bonus.c \
				revers_rotation_bonus.c \

DIR_OBJS	=	obj
DIR_OBJS_B	=	obj_b
DIR_SRCS	=	src
DIR_SRCS_B	=	bonus

PU_OBJS		=	$(PU_SRCS:.c=.o)
PU_OBJS_B	=	$(PU_SRCS_B:.c=.o)

SRCS		=	$(addprefix $(DIR_SRCS)/,$(PU_SRCS))
OBJS		=	$(addprefix $(DIR_OBJS)/,$(PU_OBJS))
SRCS_B		=	$(addprefix $(DIR_SRCS_B)/,$(PU_SRCS_B))
OBJS_B		=	$(addprefix $(DIR_OBJS_B)/,$(PU_OBJS_B))


all					:	$(NAME)

bonus				:	$(NAME_B)

$(NAME_B)			:	$(OBJS_B)
			$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS_B)/%.o	:	$(DIR_SRCS_B)/%.c Makefile | $(DIR_OBJS_B)
			$(CC) $(FLAGS) -c $< -o $@

$(DIR_OBJS_B)		:
			mkdir -p $@

$(NAME)				:	$(OBJS)
			$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o		:	$(DIR_SRCS)/%.c Makefile | $(DIR_OBJS)
			$(CC) $(FLAGS) -c $< -o $@

$(DIR_OBJS)			:
			mkdir -p $@

clean				:
			$(RM) $(DIR_OBJS)
			$(RM) $(DIR_OBJS_B)

fclean				:
			$(RM) $(DIR_OBJS)
			$(RM) $(DIR_OBJS_B)
			$(RM) $(NAME)
			$(RM) $(NAME_B)

re					:	fclean all

.PHONY				:	all clean fclean re
