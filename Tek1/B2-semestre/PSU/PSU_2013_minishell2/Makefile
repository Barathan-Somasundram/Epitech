##
## Makefile for minishell in /home/somasu_b/TEST/minishell2/new_src
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Thu Jan 30 21:33:36 2014 somasu_b
## Last update Sun Mar  9 21:44:01 2014 somasu_b
##

CC	= 	gcc

RM	= 	rm -f

NAME	= 	mysh

SRCS	= 	./Sources/String/my_string_base.c	\
	 	./Sources/String/my_string_evol.c	\
	 	./Sources/String/my_str_to_wordtab.c	\
	 	./Sources/String/my_putnbr.c		\
		./Sources/Built-ins/my_cd.c		\
		./Sources/Built-ins/my_env.c		\
		./Sources/Built-ins/my_exit.c		\
		./Sources/Built-ins/my_setenv.c		\
		./Sources/Built-ins/my_unsetenv.c	\
		./Sources/Command/cmd_center.c		\
		./Sources/Command/cmd_env.c		\
		./Sources/Command/cmd_path.c		\
		./Sources/Command/cmd_exec.c		\
		./Sources/Command/cmd_parse.c		\
		./Sources/Command/cmd_pipe.c		\
		./Sources/get_next_line.c		\
		./Sources/init.c			\
		./Sources/signal.c			\
		./Sources/my_free.c			\
		./Sources/prompt.c			\
		./Sources/minishell2.c			\
		./Sources/env_tools.c			\
		./Sources/main.c			\

OBJS	= 	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
