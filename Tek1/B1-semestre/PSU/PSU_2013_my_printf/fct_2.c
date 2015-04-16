/*
** fct_2.c for my_printf.c in /home/somasu_b/rendu/PSU_2018_my_printf
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Nov 14 13:54:40 2013 a
** Last update Sun Nov 17 19:10:33 2013 a
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_string.h"

int	my_put_un_hex_low(va_list ap, int size)
{
  size = my_put_unsigned_nbr_base(va_arg(ap, int), "0123456789abcdef", size);
  return (size);
}

int	my_put_un_hex_up(va_list ap, int size)
{
  size = my_put_unsigned_nbr_base(va_arg(ap, int), "0123456789ABCDEF", size);
  return (size);
}

int     my_put_long(va_list ap, int size)
{
  size = my_put_long_nbr_base(va_arg(ap, long), "0123456789", size);
  return (size);
}

int	my_put_char_ap(va_list ap, int size)
{
  size = my_put_char(va_arg(ap, int), size);
  return (size);
}

int	my_put_str_ap(va_list ap, int size)
{
  char	*str;

  str = va_arg(ap, char *);
  if (str == NULL)
    size = my_put_str("(null)", size);
  else
    size = my_put_str(str, size);
  return (size);
}
