## Makefile for make_my in /u/all/collio_v/rendu/piscine/Jour_13/cat
##
## Made by vincent colliot
## Login   <collio_v@epitech.net>
##
## Started on Thu Oct 25 22:06:03 2012 vincent colliot
## Last update Sun Jun  9 22:16:40 2013 quentin cloarec
## Last update Tue Jun  4 16:00:10 2013 thomas lecorre
##

NAME    = rt

RM      = rm -f

FO	=./

SRCF	=$(FO)src/

######################

X_LIB	=$(SRCF)x_lib/

S_LIB	=$(SRCF)s_lib/
LIB	=$(S_LIB)s_lenth.c\
	$(S_LIB)s_match.c\
	$(S_LIB)s_token.c\
	$(S_LIB)s_xml.c\
	$(S_LIB)s_alloc.c\
	$(X_LIB)xmalloc.c\
	$(X_LIB)lerror.c\

F_CONVERT=$(SRCF)convert/
CONVERT	=$(F_CONVERT)convert.c\
	$(F_CONVERT)convert2.c\

F_COLLIDE=$(SRCF)collide/
COLLIDE	=$(F_COLLIDE)collide.c\

F_GTN	=$(SRCF)get/
GTN	=$(F_GTN)get_next_line.c\

F_MAIN	=$(SRCF)main/
MAIN	=$(F_MAIN)main.c\

F_LOAD	=$(SRCF)screen_load/
LOAD	=$(F_LOAD)img.c\
	$(F_LOAD)screen.c\
	$(F_LOAD)put_pixel.c\
	$(F_LOAD)filtre.c\
	$(F_LOAD)filtre2.c\

F_RAY	=$(SRCF)ray_tracing/
RAY	=$(F_RAY)load.c\
	$(F_RAY)zbuff.c\

F_COLOR	=$(SRCF)color/
COLOR	=$(F_COLOR)color.c

F_SPOT	=$(SRCF)spot/
SPOT	=$(F_SPOT)spot.c\

F_MOVE	=$(SRCF)move/
MOVE	=$(F_MOVE)move.c\
	$(F_MOVE)move_call.c\

F_LIMIT	=$(SRCF)limit/
LIMIT	=$(F_LIMIT)limit.c

##     CLASSE       ##
#		     #
FCLASSE	=$(SRCF)classe/
#		     #
###### DISPLAY #######

F_DPRIV	=$(FCLASSE)display/private/

DU_FINIT=$(F_DPRIV)init/
DU_INIT	=$(DU_FINIT)call_init.c\

DPRIV	=$(DU_INIT)\

##

F_DPUB	=$(FCLASSE)display/public/

DP_FSCAN=$(F_DPUB)scan/
DP_SCAN	=$(DP_FSCAN)scan.c\

DPUB	=$(DP_SCAN)\

##

DISPLAY	=$(DPRIV)\
	$(DPUB)

######  LIGHT  #######

F_LPRIV	=$(FCLASSE)light/private/

LPRIV	=$(LU_INIT)\
	$(LU_SCAN)\

##

F_LPUB	=$(FCLASSE)light/public/

LP_FINIT=$(F_LPUB)init/
LP_INIT	=$(LP_FINIT)init.c

LP_FSCAN=$(F_LPUB)scan/
LP_SCAN	=$(LP_FSCAN)def.c\
	$(LP_FSCAN)scan.c\

LPUB	=$(LP_INIT)\
	$(LP_SCAN)

##

LIGHT	=$(LPUB)\

######  LIGHT  #######

F_EPRIV	=$(FCLASSE)eye/private/

TRANSLATE=$(F_EPRIV)calc/clic.c

EPRIV	=$(TRANSLATE)\

##

F_EPUB	=$(FCLASSE)eye/public/

EP_FINIT=$(F_EPUB)init/
EP_INIT	=$(EP_FINIT)init.c

EP_FSCAN=$(F_EPUB)scan/
EP_SCAN	=$(EP_FSCAN)def.c\
	$(EP_FSCAN)def2.c\
	$(EP_FSCAN)scan.c\

EPUB	=$(EP_INIT)\
	$(EP_SCAN)

##

EYE	=$(EPUB)\
	$(EPRIV)\

###### OBJECTS #######

F_OPRIV	=$(FCLASSE)object/private/

F_CONE	=$(F_OPRIV)cone/

CONE	=$(F_CONE)init/init.c\
	$(F_CONE)scan/scan.c\
	$(F_CONE)calc/collide.c\
	$(F_CONE)calc/normal.c\
	$(F_CONE)calc/clic.c\

F_SPHERE=$(F_OPRIV)sphere/

SPHERE	=$(F_SPHERE)init/init.c\
	$(F_SPHERE)scan/scan.c\
	$(F_SPHERE)calc/collide.c\
	$(F_SPHERE)calc/normal.c\
	$(F_SPHERE)calc/clic.c\

F_PLAN	=$(F_OPRIV)plan/

PLAN	=$(F_PLAN)init/init.c\
	$(F_PLAN)scan/scan.c\
	$(F_PLAN)calc/collide.c\
	$(F_PLAN)calc/normal.c\
	$(F_PLAN)calc/clic.c\

F_CYLIND=$(F_OPRIV)cylindre/

CYLINDER=$(F_CYLIND)init/init.c\
	$(F_CYLIND)scan/scan.c\
	$(F_CYLIND)calc/collide.c\
	$(F_CYLIND)calc/normal.c\
	$(F_CYLIND)calc/clic.c\

SUBF	=$(CONE)\
	$(CYLINDER)\
	$(SPHERE)\
	$(PLAN)\

OPRIV	=$(SUBF)\

##

F_OPUB	=$(FCLASSE)object/public/

OP_SCAN=$(F_OPUB)scan/scan.c\
	$(F_OPUB)scan/def.c\
	$(F_OPUB)scan/def2.c\

OP_INIT=$(F_OPUB)init/init.c\

OPUB	=$(OP_SCAN)\
	$(OP_INIT)\

##

OBJECTS	=$(OPRIV)\
	$(OPUB)\

######################
#		     #
#		     #
######################

SRC     =$(MAIN)\
	$(GTN)\
	$(LIB)\
	$(DISPLAY)\
	$(LIGHT)\
	$(EYE)\
	$(OBJECTS)\
	$(CONVERT)\
	$(COLLIDE)\
	$(LOAD)\
	$(RAY)\
	$(COLOR)\
	$(SPOT)\
	$(MOVE)\
	$(LIMIT)\

######################

INC	=-I $(FO)include/ -I include/classe -I include/classe/methode/ -lm -lpthread 	\
	-L/usr/lib64 -lmlx_${HOSTTYPE} -L/usr/lib64/X11 -lXext -lX11 -I/usr/X11R6/include \


CFLAGS	= -Wall -Wextra $(INC) -O2 -O3

DOTO    = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	@ $(CC) $(CFLAGS) -c -o $@ $< \
	&& echo -e "[\e[35mGCC\e[m]\e[33m" $< "\e[m=>\e[36m" $@ "\e[m" \
	|| echo -e "[\e[35mGCC\e[m]\e[33m" $< "\e[m=>" "\e[31mERROR\e[m"

$(NAME): $(DOTO)
	@ cc -o $(NAME) $(DOTO) $(CFLAGS)
	@ echo -e "\e[32m"$(NAME)"\e[m" "is alive !"
	@ echo -e "\e[37mActivated CFLAGS :\e[m" $(CFLAGS)

debug:
	cc -o $(NAME) $(SRC) $(INC) -g3

clean:
	$(RM) $(DOTO)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean
