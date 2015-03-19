##
## Makefile for  in /home/somasu_b/rendu/PSU_2014_philo
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Mon Feb 23 17:48:16 2015 SOMASUNDRAM Barathan
## Last update Mon Feb 23 18:01:23 2015 SOMASUNDRAM Barathan
##

CC	=		gcc

RM	=		rm -f

NAME	=		philo

SRCS	=		sources/main.c			\
			sources/init_philo.c		\
			sources/action.c

OBJS	=		$(SRCS:.c=.o)

CFLAGS	=		-W -Wall -Werror -Wextra -pthread -I ./includes

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM)	$(OBJS)

fclean:	clean
	$(RM) 	$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
