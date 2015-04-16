/*
** my_fct.c for my_printf in /home/somasu_b/rendu/PSU_2018_my_printf
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Wed Nov 13 13:46:28 2013 a
** Last update Sun Nov 17 16:20:09 2013 a
*/

#include <stdarg.h>
#include "my_string.h"

int	my_put_nbr_base(int nb, char *base, int size)
{
  int	len;
  int	ind;

  len = my_str_len(base);
  if (nb == -2147483648)
    {
      size = my_put_char('-', size);
      size = my_put_long_nbr_base(-nb, base, size);
      return (size);
    }
  if (nb < 0)
    {
      size = my_put_char('-', size);
      nb = - nb;
    }
  ind = nb % len;
  nb = nb / len;
  if (nb > 0)
    size = my_put_nbr_base(nb, base, size);
  size = my_put_char(base[ind], size);
  return (size);
}

int	my_put_long_nbr_base(long nb, char *base, int size)
{
  int	len;
  int	ind;

  len = my_str_len(base);
  if (nb < 0)
    {
      size = my_put_char('-', size);
      nb = - nb;
    }
  ind = nb % len;
  nb = nb / len;
  if (nb > 0)
    size = my_put_long_nbr_base(nb, base, size);
  size = my_put_char(base[ind], size);
  return (size);
}

int	my_put_unsigned_nbr_base(unsigned int nb, char *base, int size)
{
  int	len;
  int	ind;

  len = my_str_len(base);
  ind = nb % len;
  nb = nb / len;
  if (nb > 0)
    size = my_put_unsigned_nbr_base(nb, base, size);
  size = my_put_char(base[ind], size);
  return (size);
}

int	my_put_unprintable(va_list ap, int size)
{
  int	i;
  char	*str;

  i = 0;
  str = va_arg(ap, char*);
  while (str[i])
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  size = my_put_str("\\", size);
	  if (str[i] < 7)
	    size = my_put_str("00", size);
	  else if (str[i] < 63)
	    size = my_put_str("0", size);
	  size = my_put_unsigned_nbr_base(str[i], "01234567", size);
	}
      else
	size = my_put_char(str[i], size);
      i = i + 1;
    }
  return (size);
}
