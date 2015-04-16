/*
** my_power_rec.c for my_power_rec in /home/somasu_b/Desktop/my_lib/math
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 10:49:17 2013 a
** Last update Wed Dec 18 19:30:28 2013 a
*/

#include "../includes/my_lib.h"

int	my_pow(int nb, int power)
{
  long	tmp;

  if (power == 1)
    return (nb);
  else if (power < 0)
    return (0);
  else if (power == 0)
    return (1);
  tmp = my_pow(nb, power - 1);
  tmp = tmp * nb;
  return (nb);
}
