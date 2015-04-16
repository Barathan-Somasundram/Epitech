##
## Makefile for 42sh in /home/somasu_b/Music/PSU_2013_42sh/PSU_2013_42sh
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Sun Jun  1 17:13:16 2014 somasu_b
## Last update Sun Jun  1 20:22:01 2014 a
##

CC	=	gcc

RM	=	rm -f

NAME	=	42sh

SRCS	=	src/main.c				\
		src/alias.c				\
		src/free.c				\
		\
		src/init/init.c				\
		src/init/init_env.c			\
		\
		src/built/prompt.c			\
		src/built/echo.c			\
		src/built/alias.c			\
		src/built/unalias.c			\
		src/built/env.c				\
		src/built/exit.c			\
		src/built/history.c			\
		src/built/setenv.c			\
		src/built/unsetenv.c			\
		src/built/cd2.c				\
		src/built/cd.c				\
		src/built/set_vars.c			\
		src/built/unset_vars.c			\
		\
		src/command/get_next_line.c		\
		src/command/epur_command.c		\
		src/command/my_get_cmd.c		\
		src/command/gnl_termcaps.c		\
		src/command/gere_functions.c		\
		src/command/gere_functions1.c		\
		src/command/aff_cursor.c		\
		\
		src/parser/command_center.c		\
		src/parser/cmd_to_list.c		\
		src/parser/lexer.c			\
		src/parser/parser.c			\
		src/parser/epur_parser.c		\
		src/parser/structs.c			\
		\
		src/exec/redirection.c			\
		src/exec/left2.c			\
		src/exec/my_str_to_wordtab.c		\
		src/exec/path.c				\
		src/exec/execve.c			\
		src/exec/cmd_execution.c		\
		src/exec/type.c				\
		src/exec/main.c				\
		src/exec/to_tab.c			\
		src/exec/pipe.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra  -I./inc


all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lncurses

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all fclean re
