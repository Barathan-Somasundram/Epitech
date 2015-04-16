##
## Makefile for my_select in /home/somasu_b/TEST/select
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Sun Jan 19 20:13:14 2014 somasu_b
## Last update Sun Jan 19 21:16:07 2014 somasu_b
##

CC	= gcc

RM	= rm -f

NAME	= my_select

SRCS	= command_center.c	\
	  keys.c		\
	  my_list.c		\
	  my_select_print.c	\
	  my_strings.c		\
	  signal.c		\
	  tools.c		\
	  main.c

OBJS	= $(SRCS:.c=.o)

LIB	= -lncurses

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
