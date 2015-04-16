/*
** my_get_nbr.c for my_get_nbr in /home/somasu_b/Desktop/my_lib/math
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 11:14:43 2013 a
** Last update Wed Dec 18 19:31:57 2013 a
*/

#include "../includes/my_lib.h"

int	my_get_nbr(char *str)
{
  int	i;
  int	res;
  int	sign;

  i = 0;
  res = 0;
  sign = 1;
  while (char_is_num(str[i]) == 0)
    i = i + 1;
  if (str[i - 1] == '-')
    sign = -1;
  while (char_is_num(str[i]) == 1)
    {
      res = res * 10 + (str[i] - '0');
      i = i + 1;
    }
  res = res * sign;
  return (res);
}
