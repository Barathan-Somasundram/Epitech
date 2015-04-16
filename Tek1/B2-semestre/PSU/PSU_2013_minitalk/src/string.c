/*
** string.c for minitalk in /home/somasu_b/rendu/minitalk/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Mar 22 22:11:28 2014 somasu_b
** Last update Sat Mar 22 23:47:07 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>

int	my_putchar(const int fd, const char c)
{
  write (fd, &c, 1);
}

int	my_putstr(const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      my_putchar(STDOUT_FILENO, str[i++]);
  return (0);
}

int	my_perror(const char *error)
{
  int	i;

  i = 0;
  if (error != NULL)
    while (error[i] != '\0')
      my_putchar(STDERR_FILENO, error[i++]);
  return (-1);
}

int	my_get_nbr(const char *str)
{
  int	i;
  int	res;
  int	sign;

  i = 0;
  res = 0;
  sign = 1;
  while (str[i] < '0' || str[i] > '9')
    ++i;
  if (str[i - 1] == '-')
    sign = sign * -1;
  while (str[i] >= '0' && str[i] <= '9')
    res = res * 10 + (str[i++] - '0');
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

