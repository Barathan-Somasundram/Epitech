/*
** swap_byte.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sun Apr  6 15:45:35 2014 taille_a
** Last update Sun Apr 13 17:32:05 2014 a
*/

#include "asm.h"

int		my_get_endian()
{
  int		nb;

  nb = 1;
  if (*(char *)&nb == 1)
    return (LITTLE);
  else
    return (BIG);
}

char		swap_the_byte(char nb)
{
  char		res;
  int		nbr;
  int		i;

  nbr = 1;
  res = 0;
  i = 0;
  if (*(char *)&nbr == 1)
    {
      while (i < 8)
	{
	  res += (nb >> i) % 2 << (8 - i);
	  ++i;
	}
    }
  else
    return (nb);
  return (res);
}

int		swap_byte(int nb)
{
  int		nbr;
  int		res;

  nbr = 1;
  if (*(char *)&nbr == 1)
    {
      res = ((nb & 0xff) << 24) + ((nb & 0xff00) << 8)
	+ ((nb & 0xff0000) >> 8) + ((nb & 0xff000000) >> 24);
    }
  else
    return (nb);
  return (res);
}
