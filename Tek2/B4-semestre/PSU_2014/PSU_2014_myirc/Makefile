##
## Makefile for ftp in /home/potier_g/rendu/PSU_2014_myftp
##
## Made by Guillaume Potier
## Login   <potier_g@epitech.net>
##
## Started on  Sun Mar 22 19:20:53 2015 Guillaume Potier
## Last update Sun Apr 12 21:54:51 2015 potier_g
##

CC		=	gcc

RM		=	rm -f

NAME1		=	client

NAME2		=	server

SRCS1_PATH	=	./client_src

SRCS2_PATH	=	./server_src

INC_PATH	=	./includes

SRCS1		=	$(SRCS1_PATH)/apply_cmd.c	\
			$(SRCS1_PATH)/client.c		\
			$(SRCS1_PATH)/join.c		\
			$(SRCS1_PATH)/send.c		\
			$(SRCS1_PATH)/connect.c

SRCS2		=	$(SRCS2_PATH)/channel.c		\
			$(SRCS2_PATH)/new_user.c	\
			$(SRCS2_PATH)/serv_cmd.c	\
			$(SRCS2_PATH)/server.c		\
			$(SRCS2_PATH)/new_channel.c	\
			$(SRCS2_PATH)/users.c		\
			$(SRCS2_PATH)/error.c		\
			$(SRCS2_PATH)/transf_file.c	\
			$(SRCS2_PATH)/quit.c

OBJS1		=	$(SRCS1:.c=.o)

OBJS2		=	$(SRCS2:.c=.o)

CFLAGS		=	-I $(INC_PATH) -Wall -Wextra -Werror -g3

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
		$(CC) -o $(NAME1) $(OBJS1)

$(NAME2):	$(OBJS2)
		$(CC) -o $(NAME2) $(OBJS2)

clean:
		$(RM) $(OBJS1) $(OBJS2)

fclean:		clean
		$(RM) $(NAME1) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
