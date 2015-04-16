/*
** ia.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Feb  5 14:55:59 2014 somasu_b
** Last update Fri Feb 14 14:47:34 2014 somasu_b
*/

#include "../../includes/game.h"

static void	calc_sol_upper(int *line, int *nb, int *sizes, int len)
{
  int		save;
  int		curs;
  int		res;

  curs = 0;
  res = my_xor(len, sizes);
  save = sizes[curs];
  if (res != 0)
    while (res != 0 && curs < len)
      {
	if (sizes[curs] == 0)
	  {
	    sizes[curs] = save;
	    curs = curs + 1;
	    save = sizes[curs];
	  }
	sizes[curs] = sizes[curs] - 1;
	res = my_xor(len, sizes);
	if (res == 0)
	  {
	    *line = curs;
	    *nb = save - sizes[curs];
	  }
      }
}

static int	calc_sol_lower(int *line, int *nb, int *sizes, int len)
{
  int		save;
  int		xor;
  int		curs;

  curs = 0;
  save = sizes[curs];
  xor = my_xor(len, sizes);
  while (xor != 1 && curs < len)
    {
      if (sizes[curs] == 0)
	{
	  sizes[curs] = save;
	  curs = curs + 1;
	  save = sizes[curs];
	}
      sizes[curs] = sizes[curs] - 1;
      xor = my_xor(len, sizes);
      if (xor == 1)
	{
	  *line = curs;
	  *nb = save - sizes[curs];
	  return (1);
	}
    }
  return (0);
}

static int	calc_sol(int *line, int *nb, int *sizes, int len)
{
  int		sum;
  int		xor;
  int		curs;

  curs = 0;
  sum = 0;
  while (curs < len)
    sum = sum + sizes[curs++];
  xor = my_xor(len, sizes);
  if (sum <= 5 || xor == 0)
    {
      if (calc_sol_lower(line, nb, sizes, len) == 1)
	return (1);
      *line = 1;
      *nb = 1;
    }
  else
    calc_sol_upper(line, nb, sizes, len);
  return (0);
}

static int	play(int line, int nb, t_alum **alum)
{
  int		y;
  int		x;

  y = 0;
  x = 0;
  while (y < line)
    {
      move_down(alum);
      y++;
    }
  while (x < nb)
    {
      select_it(alum);
      x++;
    }
  my_clear_full_screen();
  if (valide_it(alum) == 2)
    return (3);
  return (0);
}

int	ia(t_alum **alum)
{
  int	*sizes;
  int	len;
  int	line;
  int	nb;

  nb = 0;
  line = 0;
  len = strlen_alum(alum);
  if ((int_tab(len, alum, &sizes)) == -1)
    return (-1);
  calc_sol(&line, &nb, sizes, len);
  free(sizes);
  if (play(line, nb, alum) == 3)
    return (3);
  else
    my_clear_full_screen();
  return (0);
}
