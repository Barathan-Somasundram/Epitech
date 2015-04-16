CC			= gcc

RM			= rm -f

NAME		= Lem-in_aff

SRCS		= bonus.c \
		obj.c \
		limit.c \
		detect_end.c \
		my_start.c \
		init_map.c \
		init_base.c \
		init_tube.c \
		init_move.c \
		recup_arg.c \
		event.c \
		init_move_ant.c \
		cam.c \
		my_read.c

OBJS		= $(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -lGL -lGLU -lSDL -lm

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
