/*
** my_is_prime.c for my_is_prime in /home/somasu_b/Desktop/my_lib/math
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 10:43:40 2013 a
** Last update Wed Dec 18 20:09:10 2013 a
*/

#include "../includes/my_lib.h"

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb == 0 || nb == 1)
    return (0);
  while (i < nb)
    {
      if (nb % i == 0)
	return (0);
      else
	i = i + 1;
    }
  return (1);
}
