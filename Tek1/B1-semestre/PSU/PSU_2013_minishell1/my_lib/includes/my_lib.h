/*
** my_lib.h for my_lib in /home/somasu_b/Desktop
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 15:10:15 2013 a
** Last update Mon Jan  6 18:44:59 2014 a
*/

#ifndef MY_LIB_H_
# define MY_LIB_H_

/*
** Includes
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
** Macros
*/

# define BUF_LEN 4096

/*
** Macros of errors
*/

# define MALLOC			1
# define OPEN			2
# define READ			3
# define CLOSE			4
# define PERMISSION		5
# define PATH_NOT_FOUND		6

/*
** Prototypes of char
*/

void	my_putchar(char c);
void	my_putchar_error(char e);
int	char_is_num(char c);
int	char_is_alpha(char c);

/*
** Prototypes of string
*/

void	my_putstr(char *str);
void	my_putstr_error(char *str);
char	*my_revstr(char *str);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strcpy(char *dest, char *src);
char	*my_strlowcase(char *str);
char	*my_strupcase(char *str);
char	*my_strdup(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);

/*
** Prototypes of string array
*/

void	my_show_word_tab(char **tab);
int	my_strlen_tab(char **tab);

/*
** Prototypes of number
*/

int	my_get_nbr(char *str);
void	my_put_nbr(int nb);

/*
** Prototypes for maths
*/

char	my_isneg(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
int	my_pow(int nb, int power);
int	my_square_root(int nb);

#endif /* !MY_LIB_H_ */
