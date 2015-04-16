##
## Makefile for Makefile in /home/somasu_b/rendu/PSU_2013_my_ls
## 
## Made by a
## Login   <somasu_b@epitech.net>
## 
## Started on  Tue Nov 19 13:09:19 2013 a
## Last update Sun Dec  1 20:37:36 2013 a
##

RM	= rm -f

NAME	= my_ls

SRCS	= my_fct_str.c \
	  my_data.c \
	  my_print.c \
	  my_ls.c \
	  tri.c \
	  main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) -g

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all
