/*
** my_strcpy.c for my_strcpy in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 13:57:03 2013 a
** Last update Wed Dec 18 19:35:57 2013 a
*/

#include "../includes/my_lib.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
