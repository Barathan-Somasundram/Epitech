##
## Makefile for 108monstre in /home/somasu_b/rendu/work/108monstre/gnuplot
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Sat Mar 22 14:35:27 2014 somasu_b
## Last update Sat Mar 22 15:10:25 2014 song_k
##

CC		= gcc

RM		= rm -f

NAME		= 108monstre

SRCS		= my_calc.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -W -Wall -Wextra -Werror -O3

CMATHS		= -lm

all: 	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CMATHS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
