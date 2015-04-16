/*
** my_putstr_error.c for my_putstr_error in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 10:36:06 2013 a
** Last update Wed Dec 18 19:34:38 2013 a
*/

#include "../includes/my_lib.h"

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_error(str[i]);
      i = i + 1;
    }
}
