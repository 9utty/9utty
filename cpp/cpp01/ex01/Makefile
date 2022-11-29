NAME		=	MoarBrainz!

FLAGS		=	-Wall -Werror -Wextra -std=c++98
CXX			=	c++
RM			=	rm -rf

P_SRCS		=	main.cpp \
				ZombieHorde.cpp \
				Zombie.cpp

DIR_OBJS	=	obj
DIR_SRCS	=	src

P_OBJS		=	$(P_SRCS:.cpp=.o)

SRCS		=	$(addprefix $(DIR_SRCS)/,$(P_SRCS))
OBJS		=	$(addprefix $(DIR_OBJS)/,$(P_OBJS))

all					:	$(NAME)


$(NAME)				:	$(OBJS)
			$(CXX) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o		:	$(DIR_SRCS)/%.cpp Makefile | $(DIR_OBJS)
			$(CXX) $(FLAGS) -c $< -o $@

$(DIR_OBJS)			:
			mkdir -p $@

clean				:
			$(RM) $(DIR_OBJS)

fclean				:
			$(RM) $(DIR_OBJS)
			$(RM) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
