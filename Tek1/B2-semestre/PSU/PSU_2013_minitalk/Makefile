##
## Makefile for minitalk in /home/somasu_b/minitalk
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Thu Mar 20 16:43:29 2012 somasu_b
## Last update Sun Mar 23 18:55:14 2014 somasu_b
##

CC =		gcc

RM =		rm -f

CLIENT =	./client/client

SERVER =	./server/server

SRCLIENT =	./src/client.c 		\
		./src/string.c

OBJCLIENT =	$(SRCLIENT:.c=.o)

SRCSERVER =	./src/server.c 		\
		./src/string.c

OBJSERVER =	$(SRCSERVER:.c=.o)

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJCLIENT)
		$(CC) $(OBJCLIENT) -o $(CLIENT)

$(SERVER):	$(OBJSERVER)
		$(CC) $(OBJSERVER) -o $(SERVER)

clean:
		$(RM) $(OBJCLIENT) $(OBJSERVER)
fclean:		clean
		$(RM) $(CLIENT) $(SERVER)

re:		fclean all

.PHONY: all fclean re