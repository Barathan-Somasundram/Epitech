/*
** limit.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Wed Apr 23 18:18:56 2014 potier_g
** Last update Mon Apr 28 18:18:30 2014 potier_g
*/

#include <stdlib.h>
#include "struct.h"

char	*detect_start(char *file)
{
  char	*line;
  int	pos;

  pos = 0;
  while ((line = recup_line(file, pos)) != NULL)
    {
      if (my_strcmp(line, "##start\0") == 1)
	{
	  line = recup_line(file, pos + 1);
	  return (recup_word(line, 0));
	}
      pos++;
    }
  return (NULL);
}

int	limit_x(t_base *base, int len, int sign)
{
  int	x;
  int	tmp;
  int	pos;

  x = base[0].x;
  pos = 1;
  while (pos < len)
    {
      tmp = base[pos].x;
      if ((sign > 0 && tmp > x) || (sign < 0 && tmp < x))
	x = tmp;
      pos++;
    }
  return (x);
}

int	limit_y(t_base *base, int len, int sign)
{
  int	y;
  int	tmp;
  int	pos;

  y = base[0].y;
  pos = 1;
  while (pos < len)
    {
      tmp = base[pos].y;
      if ((sign > 0 && tmp > y) || (sign < 0 && tmp < y))
        y = tmp;
      pos++;
    }
  return (y);
}
