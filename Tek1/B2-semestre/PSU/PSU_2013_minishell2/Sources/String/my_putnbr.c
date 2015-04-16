/*
** my_putnbr.c for allum1 in /home/song_e// allum1/src/display
**
** Made by emilie song
** Login   <song_e@epitech.net>
**
** Started on  Tue Feb  5 14:58:33 2013 emilie song
** Last update Mon Mar  3 18:02:41 2014 somasu_b
*/

#include "../../Includes/my_string.h"

void	my_putnbr(int nb)
{
  int	div;

  div = 1;
  if (nb < 0)
    my_putchar('-', 1);
  if (nb > 0)
    nb = -nb;
  while (nb / div <= -10)
    div = div * 10;
  while (div > 0)
    {
      my_putchar(-(nb / div) + '0', 1);
      nb = nb % div;
      div = div / 10;
    }
}
