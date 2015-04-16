/*
** my_strlen.c for my_strlen in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 10:32:17 2013 a
** Last update Wed Dec 18 19:37:28 2013 a
*/

#include "../includes/my_lib.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
