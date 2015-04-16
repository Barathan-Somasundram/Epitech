##
## Makefile for lem-in in /home/song_k/rendu/lemin-2016-song_k/workgit/Lem-in
##
## Made by song_k
## Login   <song_k@epitech.net>
##
## Started on  Fri Apr 11 14:14:14 2014 song_k
## Last update Sun May  4 23:24:18 2014 somasu_b
##

CC	=	gcc -g3

RM	=	rm -f

INCDIR	=	inc/

CFLAGS	=	-I $(INCDIR) -ansi -pedantic -Wall -Wextra -W

LDFLAGS	=

SRCS	=	src/my_string1.c			\
		src/my_string2.c			\
		src/my_strcmp.c				\
		src/my_getnbr.c 			\
		src/my_str_to_wordtab.c 		\
		src/my_fillinstr.c 			\
		src/my_checkcharfromstr.c 		\
		src/blocdata.c				\
		src/links.c				\
		src/get_next_line.c			\
		src/cleanway.c				\
		src/algo.c				\
		src/affant.c				\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	lem_in

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	re clean fclean all
