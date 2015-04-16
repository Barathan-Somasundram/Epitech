/*
** my_putstr.c for my_putstr in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 10:31:10 2013 a
** Last update Wed Dec 18 20:04:34 2013 a
*/

#include "../includes/my_lib.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
