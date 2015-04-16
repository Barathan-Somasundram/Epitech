##
## Makefile for fil de fer in /home/somasu_b/rendu/PSU_2013_minishell1
##
## Made by a
## Login   <somasu_b@epitech.net>
##
## Started on  Tue Dec 10 10:13:50 2013 a
## Last update Mon Jan  6 19:19:24 2014 a
##

CC	= gcc -g3

RM	= rm -f

NAME	= mysh

SRCS	= my_strdup.c \
	  my_str_to_wordtab.c \
	  minishell1.c \
	  my_cd.c \
	  built_ins.c \
	  my_strncmp.c \
	  my_signal.c \
	  execute.c \
	  position.c \
	  my_unsetenv.c \
	  main.c

OBJS	= $(SRCS:.c=.o)

LDFLAG	= -L ./my_lib/ -lmy ./my_lib/includes/my_lib.h


all: 	$(NAME)

$(NAME):	$(OBJS)
	@make -C ./my_lib/
	$(CC) -o $(NAME) $(SRCS) $(LDFLAG)

clean:
	@make -C ./my_lib/ clean
	$(RM) $(OBJS)

fclean:		clean
	@make -C ./my_lib/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
