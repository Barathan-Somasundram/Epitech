##
## Makefile for malloc in /home/song_k/rendu/PSU_2014_malloc
##
## Made by song kevin
## Login   <song_k@epitech.net>
##
## Started on  Tue Jan 27 09:36:01 2015 song kevin
## Last update Sun Feb 15 23:17:45 2015 song kevin
##

CC	=	gcc

RM	=	rm -f

SRCS	=	malloc.c		\
		realloc.c 		\
		calloc.c		\
		free.c			\
		utils.c			\
		show_alloc_mem.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy_malloc_$(HOSTTYPE).so

LSI	=	ln -sf

PRIMARY	=	libmy_malloc.so

CFLAGS	+=	-fPIC -Wall -Wextra -Werror -W -lpthread -g3

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -shared -o $(NAME) $(OBJS)
		$(LSI) $(NAME) $(PRIMARY)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)
		$(RM) $(PRIMARY)

re	: 	fclean all

.PHONY	:	re fclean clean all
