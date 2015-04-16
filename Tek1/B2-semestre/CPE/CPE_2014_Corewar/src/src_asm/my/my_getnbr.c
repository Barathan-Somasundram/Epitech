/*
** my_getnbr.c for my_getnbr in /home/taille_a
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sat Oct 12 19:46:16 2013 taille_a
** Last update Sat Apr 12 16:22:15 2014 taille_a
*/

#include <stdlib.h>

static int	negativity(char *str)
{
  int		idx;
  int		neg;

  idx = 0;
  neg = 0;
  while ((str[idx] <= '0' && str[idx] != '\0')
         || (str[idx] >= '9' && str[idx] != '\0'))
    {
      if (str[idx] == '-')
	neg = neg + 1;
      idx = idx + 1;
    }
  if (neg % 2 == 0)
    return (1);
  else
    return (-1);
}

static int		countuntilthenbr(char *str)
{
  int			idx;

  idx = 0;
  while ((str[idx] < '0' && str[idx] != '\0')
         || (str[idx] > '9' && str[idx] != '\0'))
    idx = idx + 1;
  return (idx);
}

long			my_getnbr(char *str)
{
  int			idx;
  int			neg;
  int			tmp;
  long			nb;
  unsigned long long	ut;

  if (str == NULL)
    return (0);
  idx = countuntilthenbr(str);
  neg = negativity(str);
  ut = 0;
  while (str[idx] <= '9' && str[idx] >= '0')
    {
      ut = ut + (str[idx] - '0');
      ut = ut * 10;
      if ((ut > 21474836470 && neg == 1) ||
	  (ut > 21474836480 && neg == -1))
        return (ut);
      idx = idx + 1;
    }
  tmp = ut / 10;
  nb = tmp * neg;
  return (nb);
}
