##
## Makefile for  in /home/somasu_b/rendu/PSU_2014_lemipc
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Mon Mar  2 15:36:07 2015 SOMASUNDRAM Barathan
## Last update Sun Mar  8 18:55:11 2015 SOMASUNDRAM Barathan
##

CC		=		gcc

RM		=		rm -f

NAME		=		lemipc

SRCS_PATH	=		./sources

INC_PATH	=		./includes

SRCS		=		$(SRCS_PATH)/main.c		\
				$(SRCS_PATH)/signal.c		\
				$(SRCS_PATH)/game.c		\
				$(SRCS_PATH)/init_shm.c		\
				$(SRCS_PATH)/move.c		\
				$(SRCS_PATH)/print_map.c	\
				$(SRCS_PATH)/print_player.c	\
				$(SRCS_PATH)/recup_pos.c	\
				$(SRCS_PATH)/recup_target.c	\
				$(SRCS_PATH)/semaphore.c

OBJS		=		$(SRCS:.c=.o)

CFLAGS		=		-W -Wall -Wextra -Werror -I $(INC_PATH)

SDLFLAGS	=		-lSDL

LDFLAGS		=		-lm -pthread

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(SDLFLAGS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
