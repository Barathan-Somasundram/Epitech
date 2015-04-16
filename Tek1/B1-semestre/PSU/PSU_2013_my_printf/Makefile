##
## Makefile for Makefile in /home/somasu_b/rendu/PSU_2013_my_printf
## 
## Made by a
## Login   <somasu_b@epitech.net>
## 
## Started on  Mon Nov 17 11:04:09 2013 a
## Last update Sun Nov 17 19:16:50 2013 a
##

RM	= rm -f

NAME	= libmy.a

SRCS	= fct_1.c \
	  fct_2.c \
	  my_fct_num.c \
	  my_fct_str.c \
	  my_printf.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all
