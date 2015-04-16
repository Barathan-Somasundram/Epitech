/*
** my_strings_2.c for corewar in /home/somasu_b/rendu/corewar/VM/retcode/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Apr  1 17:16:42 2014 somasu_b
** Last update Sun Apr 13 18:05:06 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_strings.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      ++i;
  return (i);
}

static int	char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	my_get_nbr(const char *str)
{
  int	i;
  int	res;
  int	sign;

  i = 0;
  res = 0;
  sign = 1;
  while (char_is_num(str[i]) == 0 && str[i] != '\0')
    ++i;
  if (str[i - 1] == '-')
    sign = -1;
  while (char_is_num(str[i]) == 1 && str[i] != '\0')
    res = res * 10 + (str[i++] - '0');
  res = res * sign;
  return (res);
}

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar(STDOUT_FILENO, '-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(STDOUT_FILENO, '0' + nb);
}

void		my_put_nbr_base(int nb, const int base)
{
  int		res;

  res = nb % base;
  nb = nb / base;
  if (nb)
    my_put_nbr_base(nb, base);
  if (res > 9)
    my_putchar(STDOUT_FILENO, 'A' + res % 10);
  else
    my_put_nbr(res);
}
