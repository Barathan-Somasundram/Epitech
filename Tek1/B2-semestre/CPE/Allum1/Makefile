##
## Makefile for alum-1 in /home/somasu_b/TEST/alum-1
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Sun Feb  2 21:35:36 2014 somasu_b
## Last update Sun Feb 16 21:48:27 2014 somasu_b
##

CC	= gcc

RM	= rm -f

NAME	= allum1

SRCS	= ./sources/Initialize/list.c		\
	  ./sources/Initialize/init_term.c	\
	  ./sources/Screen/tools.c		\
	  ./sources/Screen/shows.c		\
	  ./sources/Screen/my_string.c		\
	  ./sources/Moves/move1.c		\
	  ./sources/Moves/move2.c		\
	  ./sources/Players/player.c		\
	  ./sources/Players/ia_intel.c		\
	  ./sources/Players/ia_tools.c		\
	  ./sources/main.c

OBJS	= $(SRCS:.c=.o)

LNCURSE = -lncurses -Werror -Wall -Wextra


all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LNCURSE)

bonus:
	make -C ./Bonus/
clean:
	make -C ./Bonus/ clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
	make -C ./Bonus/ fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all fclean re
