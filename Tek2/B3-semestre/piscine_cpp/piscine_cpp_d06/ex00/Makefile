##
## Makefile for my_cat in /home/somasu_b/rendu/piscine_cpp_d06/ex00
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Mon Jan 12 09:11:16 2015 SOMASUNDRAM Barathan
## Last update Tue Jan 13 03:25:40 2015 SOMASUNDRAM Barathan
##

G	=	g++

RM	=	rm -f

NAME	=	my_cat

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	=	-W -Wall -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(G) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
