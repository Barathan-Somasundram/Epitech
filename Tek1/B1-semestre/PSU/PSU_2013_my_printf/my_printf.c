/*
** my_printf.c for my_printf.c in /home/somasu_b/rendu/PSU_2018_my_printf
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Nov 14 11:28:54 2013 a
** Last update Sun Nov 17 20:30:31 2013 a
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"
#include "my_string.h"

int	flags_func(int (**flag_func)(va_list, int))
{
  flag_func[0] = &my_put_dec;
  flag_func[1] = &my_put_dec;
  flag_func[2] = &my_put_un_dec;
  flag_func[3] = &my_put_un_bin;
  flag_func[4] = &my_put_un_oct;
  flag_func[5] = &my_put_un_hex_low;
  flag_func[6] = &my_put_un_hex_up;
  flag_func[7] = &my_put_char_ap;
  flag_func[8] = &my_put_str_ap;
  flag_func[9] = &my_put_str_ap;
  flag_func[10] = &my_put_unprintable;
  flag_func[11] = &my_put_point;
  flag_func[12] = NULL;
}

char	flags_char(char *flag_char)
{
  flag_char[0] = 'd';
  flag_char[1] = 'i';
  flag_char[2] = 'u';
  flag_char[3] = 'b';
  flag_char[4] = 'o';
  flag_char[5] = 'x';
  flag_char[6] = 'X';
  flag_char[7] = 'c';
  flag_char[8] = 's';
  flag_char[9] = '%';
  flag_char[10] = 'S';
  flag_char[11] = 'p';
  flag_char[12] = 'l';
  flag_char[13] = '\0';
}

int	flag_and_func(const char *str, int (**flag_func)(va_list, int),
		      va_list ap, int *ent)
{
  char	flag_char[14];
  int	ind;

  ind = 0;
  flags_char(flag_char);
  while (str[ent[0]] != flag_char[ind] && ind < 13)
    ind = ind + 1;
  if (ind == 9)
    ent[1] = my_put_char('%', ent[1]);
  else if (ind > 12)
    {
      ent[1] = my_put_char('%', ent[1]);
      ent[1] = my_put_char(str[ent[0]], ent[1]);
    }
  else if (ind == 12 && str[ent[0] + 1] == 'd')
    {
      ent[1] = my_put_long_nbr_base(va_arg(ap, long), "0123456789", ent[1]);
      ent[0] = ent[0] + 1;
    }
  else
    ent[1] = flag_func[ind](ap, ent[1]);
  return (ent[1]);
}

int		my_printf(const char *format, ...)
{
  int		ent[2];
  va_list	ap;
  int		(*flag_func[14])(va_list, int);
  char		*str;

  if (format == NULL)
    return (-1);
  va_start(ap, format);
  ent[0] = 0;
  ent[1] = 0;
  flags_func(flag_func);
  while (format[ent[0]] != '\0')
    {
      while (format[ent[0]] == '%')
	{
	  ent[0] = ent[0] + 1;
	  ent[1] = flag_and_func(format, flag_func, ap, ent) - 1;
	  ent[0] = ent[0] + 1;
	}
      ent[1] = my_put_char(format[ent[0]], ent[1]);
      ent[0] = ent[0] + 1;
    }
  va_end(ap);
  return (ent[1]);
}
