/*
** tools.c for alum-1 in /home/somasu_b/TEST/alum-1/Bonus
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 16 15:13:04 2014 somasu_b
** Last update Sun Feb 16 21:29:33 2014 somasu_b
*/

#include "../../includes/bonus.h"

int	my_getchar(void)
{
  int	ret;
  char	s[1];

  if ((ret = read(0, &s, 1)) == -1)
    return (-1);
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	compare;

  compare = 0;
  while ((s1[compare] == s2[compare]) &&
	 (s1[compare] != '\0' || s2[compare] != '\0'))
    compare = compare + 1;
  return (s1[compare] - s2[compare]);
}

int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
    my_putchar('0' + nb);
  return (0);
}
