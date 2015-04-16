##
## Makefile for alum-1 in /home/somasu_b/TEST/alum-1
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Sun Feb  2 21:35:36 2014 somasu_b
## Last update Sun Feb 16 21:48:41 2014 somasu_b
##

CC	= gcc

RM	= rm -f

MV	= mv

NAME	= allum1

SRCS_BONUS	= ./Initialize/list.c		\
	  	  ./Initialize/init_term.c	\
		  ./Menu/get_next_line.c	\
		  ./Menu/cmd_center.c		\
		  ./Menu/menu.c			\
		  ./Menu/move.c			\
		  ./Menu/show.c			\
		  ./Menu/texture.c		\
		  ./Screen/my_get_ent.c		\
	  	  ./Screen/tools.c		\
	  	  ./Screen/shows.c		\
	  	  ./Screen/my_string.c		\
	  	  ./Moves/move1.c		\
	  	  ./Moves/move2.c		\
	  	  ./Players/player.c		\
	  	  ./Players/ia_intel.c		\
	  	  ./Players/ia_tools.c		\
	  	  ./main.c

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

LNCURSE = -lncurses


all:	$(NAME)

$(NAME):	$(OBJS_BONUS)
	$(CC) -o $(NAME) $(OBJS_BONUS) $(LNCURSE)
	$(MV) $(NAME) ..
clean:
	$(RM) $(OBJS_BONUS)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all fclean re
