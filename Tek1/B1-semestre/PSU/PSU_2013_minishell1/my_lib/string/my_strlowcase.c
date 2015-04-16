/*
** my_strlowcase.c for my_strlowcase in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 14:43:25 2013 a
** Last update Wed Dec 18 19:38:00 2013 a
*/

#include "../includes/my_lib.h"

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
