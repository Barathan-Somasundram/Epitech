/*
** my_strcat.c for my_strcat in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 13:42:43 2013 a
** Last update Mon Jan  6 13:59:04 2014 a
*/

#include "../includes/my_lib.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  if (dest == NULL || src == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (dest[j] != '\0')
    j = j + 1;
  dest[j] = ' ';
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      j = j + 1;
      i = i + 1;
    }
  dest[j] = '\0';
  return (dest);
}
