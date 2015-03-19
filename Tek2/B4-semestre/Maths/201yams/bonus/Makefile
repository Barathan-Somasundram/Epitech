##
## Makefile for  in /home/somasu_b/Downloads/ISO/l
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Sun Mar  1 20:02:38 2015 SOMASUNDRAM Barathan
## Last update Sun Mar  1 22:02:29 2015 SOMASUNDRAM Barathan
##

CC	=	g++

RM	=	rm -f

NAME	=	yams

NAME1	=	sources/mainpart/yams

NAME2	=	sources/playpart/yams

NAME3	=	sources/reglepart/yams

CP	=	cp

all: $(NAME)

$(NAME):
	make -C ./sources/mainpart/
	make -C ./sources/playpart/
	make -C ./sources/reglepart/
	$(CP) $(NAME1) .

clean:
	make clean -C ./sources/mainpart/
	make clean -C ./sources/playpart/
	make clean -C ./sources/reglepart/

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(RM) $(NAME3)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

