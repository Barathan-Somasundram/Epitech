##
## Makefile for  in /home/somasu_b/rendu/asm_minilibc/sources
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Sun Mar 22 22:36:09 2015 SOMASUNDRAM Barathan
## Last update Sun Mar 22 23:14:49 2015 SOMASUNDRAM Barathan
##

NASM		=	nasm

CC		=	gcc

SRCS 		=	./sources/my_strlen.S 		\
			./sources/my_strchr.S 		\
			./sources/my_memset.S 		\
			./sources/my_memcpy.S		\
			./sources/my_strcmp.S 		\
			./sources/my_memmove.S 		\
			./sources/my_strncmp.S 		\
			./sources/my_strcasecmp.S	\
			./sources/my_rindex.S		\
			./sources/my_strstr.S		\
			./sources/my_strpbrk.S		\
			./sources/my_strcspn.S

OBJS		=	$(SRCS:.S=.o)

NASMFLAGS	=	-f elf64

LDFLAGS		=	-shared

NAME		=	libasm.so

%.o:			%.S
			$(NASM) $< $(NASMFLAGS) -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:			clean
			rm -f $(NAME)

re:			fclean all
