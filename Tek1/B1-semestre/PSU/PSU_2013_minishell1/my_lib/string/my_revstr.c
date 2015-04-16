/*
** my_revstr.c for my_revstr in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 13:34:05 2013 a
** Last update Wed Dec 18 19:34:49 2013 a
*/

#include "../includes/my_lib.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	tmp;

  if (str == NULL)
    return (NULL);
  i = 0;
  j = my_strlen(str);
  while (i < j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i = i + 1;
      j = j - 1;
    }
  return (str);
}
