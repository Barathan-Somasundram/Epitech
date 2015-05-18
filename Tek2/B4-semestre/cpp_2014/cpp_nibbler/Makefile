##
## Makefile for  in /home/somasu_b/rendu/snake
## 
## Made by SOMASUNDRAM Barathan
## Login   <somasu_b@epitech.net>
## 
## Started on  Tue Mar 10 16:39:38 2015 SOMASUNDRAM Barathan
## Last update Sun Apr  5 21:20:00 2015 SOMASUNDRAM Barathan
##

GPP		=		g++

RM		=		rm -f

NAME		=		nibbler

NAME_SDL	=		lib_nibbler_sdl.so

NAME_OPENGL	=		lib_nibbler_opengl.so

NAME_NCURSE	=		lib_nibbler_ncurse.so

SRCS_PATH	=		./sources

SRCS_CORE	=		$(SRCS_PATH)/algo/main.cpp	\
				$(SRCS_PATH)/algo/dll.cpp	\
				$(SRCS_PATH)/algo/Nibbler.cpp

SRCS_SDL	=		$(SRCS_PATH)/SDL/sdl.cpp

SRCS_OPENGL	=		$(SRCS_PATH)/OpenGL/opengl.cpp

SRCS_NCURSE	=		$(SRCS_PATH)/Ncurses/main.cpp	\
				$(SRCS_PATH)/Ncurses/putchar_int.cpp

OBJS_SDL	=		$(SRCS_SDL:.cpp=.o)

OBJS_CORE	=		$(SRCS_CORE:.cpp=.o)

OBJS_NCURSE	=		$(SRCS_NCURSE:.cpp=.o)

OBJS_OPENGL	=		$(SRCS_OPENGL:.cpp=.o)

INCLUDES	=		./includes

CPPFLAGS	=		-W -Wall -Wextra -I ./includes 

LDFLAGS_SDL	=		-I ./includes -lSDL -lSDL_image

LDFLAGS_NCURSE	=		-I ./includes -lncurses -pthread

LDFLAGS_OPENGL	=		-I ./includes -lSDL -lGL -lGLU

all:				$(NAME)

$(NAME):			$(OBJS_SDL) $(OBJS_CORE) $(OBJS_NCURSE) $(OBJS_OPENGL)
				$(GPP) -shared -fPIC -o $(NAME_SDL) $(SRCS_SDL) $(LDFLAGS_SDL)
				$(GPP) -shared -fPIC -o $(NAME_NCURSE) $(SRCS_NCURSE) $(LDFLAGS_NCURSE)
				$(GPP) -shared -fPIC -o $(NAME_OPENGL) $(SRCS_OPENGL) $(LDFLAGS_OPENGL)
				$(GPP) -o $(NAME) $(OBJS_CORE) -ldl

clean:
				$(RM) $(OBJS_CORE)
				$(RM) $(OBJS_SDL)
				$(RM) $(OBJS_NCURSE)
				$(RM) $(OBJS_OPENGL)

fclean:				clean
				$(RM) $(NAME)
				$(RM) $(NAME_SDL)
				$(RM) $(NAME_NCURSE)
				$(RM) $(NAME_OPENGL)

re:				fclean all

.PHONY:				all clean fclean re
