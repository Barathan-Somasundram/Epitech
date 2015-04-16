/*
** my_str_islower.c for my_str_islower in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 14:30:02 2013 a
** Last update Wed Dec 18 19:36:31 2013 a
*/

#include "../includes/my_lib.h"

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	return (0);
      i = i + 1;
    }
  return (1);
}
