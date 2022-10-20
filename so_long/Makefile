NAME			=	so_long


FLAGS			=	-Wall -Wextra -Werror
S_FLAGS			=	-framework OpenGL -framework AppKit
CC				=	cc

SO_SRCS			=	so_long.c \
					map_parsing.c \
					map_check.c \
					map_validi_utils.c \
					error_del.c \
					so_long_exit.c \
					window_map.c \
					move_key.c \
					put_img.c \
					get_next_line.c \
					get_next_line_utils.c

DIR_SRCS		=	src
DIR_OBJS		=	obj
DIR_LIBFT		=	libft
DIR_GNL			=	gnl
DIR_MLX			=	mlx

SO_OBJS			=	$(SO_SRCS:.c=.o)

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SO_SRCS))
OBJS			=	$(addprefix $(DIR_OBJS)/,$(SO_OBJS))

AR_LIBFT		=	$(DIR_LIBFT)/libft.a
AR_MLX			=	$(DIR_MLX)/libmlx.a


all : $(AR_LIBFT) $(NAME)

$(NAME) : $(AR_LIBFT) $(AR_GNL) $(AR_MLX) $(OBJS)
			arch -x86_64 $(CC) $(FLAGS) $(S_FLAGS) $^ -o $@

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c $(DIR_OBJS)
			$(CC) $(FLAGS) -Imlx -c $< -o $@

$(DIR_OBJS) :
			mkdir -p $@

$(AR_MLX) :
	make -C $(DIR_MLX)

$(AR_LIBFT) :
	make -C $(DIR_LIBFT)

clean :
	rm -rf $(DIR_OBJS)
	make clean -C $(DIR_LIBFT)

fclean : clean
	make fclean -C $(DIR_LIBFT)
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all
