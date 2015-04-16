##
## Makefile for my_lib in /home/somasu_b/Desktop/my_lib
##
## Made by a
## Login   <somasu_b@epitech.net>
##
## Started on  Wed Dec 18 19:39:15 2013 a
## Last update Thu Dec 19 14:39:58 2013 a
##

RM	= rm -f

NAME	= libmy.a

SRCS	= ./string/char_is_alpha.c \
	  ./string/char_is_num.c \
	  ./string/my_putchar.c \
	  ./string/my_putchar_error.c \
	  ./string/my_putstr.c \
	  ./string/my_putstr_error.c \
	  ./string/my_revstr.c \
	  ./string/my_show_word_tab.c \
	  ./string/my_strcapitalize.c \
	  ./string/my_strcat.c \
	  ./string/my_strcmp.c \
	  ./string/my_strcpy.c \
	  ./string/my_strdup.c \
	  ./string/my_str_isalpha.c \
	  ./string/my_str_islower.c \
	  ./string/my_str_isnum.c \
	  ./string/my_str_isprintable.c \
	  ./string/my_str_isupper.c \
	  ./string/my_strlen.c \
	  ./string/my_strlen_tab.c \
	  ./string/my_strlowcase.c \
	  ./string/my_strupcase.c \
	  ./math/my_find_prime_sup.c \
	  ./math/my_isneg.c \
	  ./math/my_power_rec.c \
	  ./math/my_is_prime.c \
	  ./math/my_square_root.c \
	  ./number/my_put_nbr.c \
	  ./number/my_get_nbr.c

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME):	$(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
clean:
	@echo -e "Cleaning in progress ..."
	@$(RM) $(OBJS)
	@echo -e "Cleaning done"

fclean:		clean
	@$(RM) $(NAME)
	@echo -e "library is delete"

re: fclean all

.PHONY: all clean fclean
