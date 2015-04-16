/*
** my_getnbr.c for my_getnbr in /home/song_k/rendu/Piscine-C-lib/my
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Mon Oct 14 11:03:57 2013 song_k
** Last update Wed Apr 23 10:52:43 2014 somasu_b
*/

#include <stdlib.h>
#include "lemin.h"

static int	minegetnbr(char *str, int i)
{
  int		chk;
  int		n;

  n = 1;
  chk = 0;
  while (i > 0 && str[i - 1] == '-')
    --i;
  while (str[i] && str[i] == '-')
    {
      n = -n;
      ++i;
    }
  if (n < 0)
    chk = -1;
  n = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    n = n * 10 + (str[i++] - '0');
  if (chk == -1)
    n = -n;
  return (n);
}

int	my_getnbr(char *str)
{
  int	i;

  if ((i = my_isnum(str)) == -1)
    return (0);
  else
    return (minegetnbr(str, i));
  return (0);
}
