/*
** my_strings.h for my_strings.h in /home/somasu_b/rendu/corewar/VM/retcode
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Mar 30 23:11:48 2014 somasu_b
** Last update Sat Apr  5 16:07:15 2014 somasu_b
*/

#ifndef _MY_STRINGS_H_
# define _MY_STRINGS_H_

int	my_putchar(const int fd, const int c);
int	my_putstr(const char *str);
int	my_perror(const char *error1, const char *error2);
void	my_put_nbr(int nb);
void	my_put_nbr_base(int nb, const int base);
int	my_strlen(const char *str);
int	my_get_nbr(const char *str);
int	my_strcmp(const char *s1, const char *s2);
char	*my_strdup(const char *str);
char	*my_strndup(const char *str, int len);

#endif /* !_MY_STRINGS_H_ */
