/*
** my_square_root.c for my_square_root in /home/somasu_b/Desktop/my_lib/math
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 11:03:22 2013 a
** Last update Wed Dec 18 19:30:15 2013 a
*/

#include "../includes/my_lib.h"

int	my_square_root(int nb)
{
  int	res;

  res = 0;
  if (nb == 1 || nb == 0)
    return (nb);
  else if (nb < 0)
    return (0);
  while (res <= (nb / 2))
    {
      if (res * res == nb)
	return (res);
      else
	res = res + 1;
    }
  return (0);
}
