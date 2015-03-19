##
## Makefile for menger in /home/somasu_b/rendu/piscine_cpp_d01/ex01
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Wed Jan  7 12:19:28 2015 SOMASUNDRAM Barathan
## Last update Wed Jan  7 13:29:10 2015 SOMASUNDRAM Barathan
##

NAME	=	menger

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra -std=gnu99

SRCS	=	main.c	\
		menger.c

OBJS	=	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:	
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all

.PHONY:	all clean fclean re
