/*
** my_string.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Feb  4 12:24:22 2014 somasu_b
** Last update Thu Feb 13 15:50:24 2014 somasu_b
*/

#include "../../includes/game.h"

int	my_putchar(int c)
{
  write(1, &c, 1);
  return (0);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      my_putchar(str[i++]);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	compare;

  compare = 0;
  if (!s1 || !s2)
    return (-1);
  while (compare < n && s1[compare] == s2[compare]
  	 && s1[compare] != '\0' && s2[compare] != '\0')
    compare = compare + 1;
  return (s1[compare] - s2[compare]);
}
