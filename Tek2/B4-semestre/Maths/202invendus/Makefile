##
## Makefile for  in /home/somasu_b/rendu/cpp_abstractvm
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Tue Feb 17 17:22:16 2015 SOMASUNDRAM Barathan
## Last update Sun Mar  1 13:23:56 2015 SOMASUNDRAM Barathan
##

RM		=		rm -f

GPP		=		g++

NAME		=		202invendus

SRCS		=		202.cpp	\
				invendus.cpp

INC_PATH	=		./includes/

OBJS		=		$(SRCS:.cpp=.o)

CPPFLAGS	=		-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(GPP)  -I includes -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
