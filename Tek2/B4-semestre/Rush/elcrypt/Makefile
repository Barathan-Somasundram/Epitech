
CC		=		gcc

RM		=		rm -f

NAME		=		elcrypt

SRCS		=		sources/elcrypt.c	\
				sources/convert.c	\
				sources/flag.c		\
				sources/key.c		\
				sources/get_key.c	\
				sources/rotate.c	\
				sources/algo.c

OBJS		=		$(SRCS:.c=.o)

CFLAGS		=		-W -Wall -Wextra -Werror -pedantic -I./includes -g3

LDFLAGS		=		-g3

all:				$(NAME)

$(NAME):			$(OBJS)
				$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
