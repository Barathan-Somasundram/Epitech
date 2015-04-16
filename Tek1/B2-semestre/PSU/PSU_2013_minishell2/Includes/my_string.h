/*
** my_string.h for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 15:20:44 2014 somasu_b
** Last update Thu Feb 27 13:03:21 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>

#ifndef _MY_STRING_H_
# define _MY_STRING_H_

int	my_putchar(int c, int fd);
int	my_strlen(char *str);
int	my_putstr(char *str);
int	my_puterror(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strdup(char *str);
char	*get_next_line(const int fd);
char	**my_str_to_wordtab(char *s, const char *nword);

#endif /* !MY_STRING_H_ */
