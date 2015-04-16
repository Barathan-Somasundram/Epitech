/*
** my_str_isupper.c for my_str_isupper in /home/somasu_b/Desktop/my_lib/string
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 17 14:37:17 2013 a
** Last update Wed Dec 18 19:37:13 2013 a
*/

#include "../includes/my_lib.h"

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 'A' || str[i] > 'Z')
	return (0);
      i = i + 1;
    }
  return (1);
}
