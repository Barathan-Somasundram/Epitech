##
## Makefile for  in /home/somasu_b/rendu/206neutrinos
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Mer May 6 01:05:05 2015 SOMASUNDRAM Barathan
## Last update Mer May 6 01:05:05 2015 SOMASUNDRAM Barathan
##

RM		=		rm -f

GPP		=		g++

NAME		=		206neutrinos

SRCS		=		206.cpp

INC_PATH	=		./includes/

OBJS		=		$(SRCS:.cpp=.o)

CPPFLAGS	=		-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
		$(GPP)  -I includes -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
