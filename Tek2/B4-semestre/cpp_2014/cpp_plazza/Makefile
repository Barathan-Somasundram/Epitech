##
## Makefile for  in /home/somasu_b/rendu/cpp_plazza
##
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
##
## Started on  Tue Apr  7 12:44:49 2015 SOMASUNDRAM Barathan
## Last update Tue Apr  7 12:55:10 2015 SOMASUNDRAM Barathan
##

NAME		=		plazza

RM		=		rm -f

MV		=		mv

all:		$(NAME)

$(NAME):
		@(cd ./qt && $(MAKE) $@)
		$(MV) ./qt/$(NAME) $(NAME)

clean:
		@(cd ./qt && $(MAKE) clean $@)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
