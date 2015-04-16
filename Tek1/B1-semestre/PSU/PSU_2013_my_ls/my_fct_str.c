/*
** my_fct_str.c for my_ls in /home/somasu_b/my_files
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Nov 29 23:52:32 2013 a
** Last update Sun Dec  1 18:58:07 2013 a
*/

#include "my_ls.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[j] != '\0')
    j = j + 1;
  dest[j] = ' ';
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      i = i + 1;
      j = j + 1;
    }
  dest[j] = '\0';
  return (dest);
}

void	my_putnbr(long nb)
{
  if (nb >= 10)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
    my_putchar(nb + '0');
}
