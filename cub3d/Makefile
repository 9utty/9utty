NAME			=	cub3D

FLAGS			=	-Wall -Wextra -Werror
S_FLAGS			=	-framework OpenGL -framework AppKit
CC				=	cc

CUB_SRCS		= cub3d.c \


DIR_SRCS		=	src
DIR_OBJS		=	obj
DIR_MLX			=	mlx

CUB_OBJS		=	$(CUB_SRCS:.c=.o)

SRCS			=	$(addprefix $(DIR_SRCS)/,$(CUB_SRCS))
OBJS			=	$(addprefix $(DIR_OBJS)/,$(CUB_OBJS))

AR_MLX			=	$(DIR_MLX)/libmlx.a

all				:	$(NAME)

$(NAME)			:	$(AR_MLX) $(OBJS)
					arch -x86_64 $(CC) $(FLAGS) $(S_FLAGS)

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c Makefile | $(DIR_OBJS)
					$(CC) $(FLAGS) -Imlx -c $< -o $@

$(DIR_OBJS)		:
					mkdir -p $@

$(AR_MLX)		:
					make -C $(DIR_MLX)

clean			:
					rm -rf $(DIR_OBJS)
					make clean -C $(DIR_MLX)

fclean			:
					rm -rf $(DIR_OBJS)
					make fclean -C $(DIR_MLX)
					rm -rf $(NAME)

re				:	fclean all

.PHONY			:	re fclean clean all
