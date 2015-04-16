/*
** my_string1.c for lem_in in /home/somasu_b/rendu/prog_elem/somasu_b/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Apr 22 21:41:56 2014 somasu_b
** Last update Sun May  4 22:40:04 2014 song_k
*/

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

static int	my_putchar(const char c, const int fd)
{
  if (write(fd, &c, 1) == -1)
    return (-1);
  return (0);
}

void	my_putstr(char *str, const int fd)
{
  write(fd, str, my_strlen(str));
}

int	my_putnbr(int n)
{
  int 	p;

  p = 1;
  if (n == -2147483648)
    my_putstr("-2147483648", 1);
  else
    {
      if (n < 0)
	{
	  my_putchar('-', 1);
	  n = -n;
	}
      while (n / p > 9)
	p = p * 10;
      while (p > 0)
	{
	  my_putchar(n / p + '0', 1);
	  n = n % p;
	  p = p / 10;
	}
    }
  return (0);
}
