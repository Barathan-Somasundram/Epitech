/*
** my_put_nbr.c for my_put_nbr in /home/somasu_b/Desktop/my_lib/math
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 10:56:28 2013 a
** Last update Wed Dec 18 20:09:47 2013 a
*/

#include "../includes/my_lib.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar('0' + nb);
}
