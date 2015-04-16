/*
** my_isneg.c for my_isneg in /home/somasu_b/Desktop/my_lib/math
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 10:46:35 2013 a
** Last update Wed Dec 18 20:07:56 2013 a
*/

#include "../includes/my_lib.h"

char	my_isneg(int nb)
{
  char	pos;
  char	neg;

  pos = 'P';
  neg = 'N';
  if (nb < 0)
    my_putchar(neg);
  else
    my_putchar(pos);
}
