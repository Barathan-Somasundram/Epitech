/*
** fct_1.c for my_printf.c in /home/somasu_b/rendu/PSU_2018_my_printf
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Nov 14 13:41:30 2013 a
** Last update Sun Nov 17 19:10:25 2013 a
*/

#include <stdarg.h>
#include "my_string.h"

int	my_put_dec(va_list ap, int size)
{
  size = my_put_nbr_base(va_arg(ap, int), "0123456789", size);
  return (size);
}

int	my_put_un_dec(va_list ap, int size)
{
  size = my_put_unsigned_nbr_base(va_arg(ap, int), "0123456789", size);
  return (size);
}


int	my_put_un_bin(va_list ap, int size)
{
  size = my_put_unsigned_nbr_base(va_arg(ap, int), "01", size);
  return (size);
}

int	my_put_un_oct(va_list ap, int size)
{
  size = my_put_unsigned_nbr_base(va_arg(ap, int), "01234567", size);
  return (size);
}

int	my_put_point(va_list ap, int size)
{
  void	*point;

  point = va_arg(ap, void*);
  if (point == 0)
    size = my_put_str("(nil)", size);
  else
  {
    size = my_put_str("0x", size);
    size = my_put_long_nbr_base(point, "0123456789abcdef", size);
  }
  return (size);
}
