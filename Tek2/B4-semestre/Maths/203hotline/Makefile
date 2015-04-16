##
## Makefile for  in /home/somasu_b/rendu/203hotline
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Sat Mar 28 18:56:39 2015 SOMASUNDRAM Barathan
## Last update Sat Mar 28 19:19:04 2015 SOMASUNDRAM Barathan
##

GPP		=	g++

RM		=	rm -f

NAME		=	203hotline

SRCS		=	sources/hotline.cpp

OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS	=	-Wall -Wextra -Werror -lgmpxx -lgmp -I includes

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(GPP) $(SRCS) -o $(NAME) $(CPPFLAGS)
			@mkdir -p data

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)
			@rm -rf data

re		:	fclean all

.PHONY		:	all clean fclean re
