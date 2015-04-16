/*
** my_putnbr.c for yolo in /home/taille_a/rendu/PSU_2013_minitalk/server
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sun Mar 23 18:23:47 2014 taille_a
** Last update Sat Apr 12 13:07:44 2014 taille_a
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putnbr(int nb)
{
  int	mult;
  int	div;

  div = 1;
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  mult = nb;
  while (mult >= 10)
    {
      mult = mult / 10;
      div = div * 10;
    }
  while (div >= 1)
    {
      my_putchar((nb / div) % 10 + '0');
      div = div / 10 ;
    }
}
