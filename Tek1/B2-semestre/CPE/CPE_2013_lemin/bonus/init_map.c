/*
** init_map.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sat Apr 26 16:24:24 2014 potier_g
** Last update Sun May  4 21:06:04 2014 potier_g
*/

#include <stdlib.h>
#include "struct.h"

int		my_get_nbr(char *nb)
{
  int		a;
  int		new_nb;

  a = 0;
  new_nb = 0;
  if (nb == NULL)
    return (-1);
  while (nb[a] != '\0' && nb[a] != '\n')
    new_nb = (new_nb * 10) + (nb[a++] - 48);
  return (new_nb);
}

int		check_char(char *line, char c)
{
  int		a;

  a = 0;
  if (line == NULL)
    return (-1);
  while (line[a] != '\0')
    if (line[a++] == c)
      return (1);
  return (0);
}

t_param		*init_file2(char *file, t_param *param, int line_s, int line_e)
{
  while (check_char(recup_line(file, line_e), 'P') == 0)
    line_e++;
  if ((param->tube = init_tube(file, line_s, line_e - 1, param)) == NULL)
    return (NULL);
  line_s = line_e;
  while (recup_line(file, line_e) != NULL)
    line_e++;
  if ((param->move = init_move(file, line_s, line_e, param)) == NULL)
    return (NULL);
  return (param);
}

t_param		*init_file(t_param *param)
{
  char		*file;
  int		line_start;
  int		line_end;
  int		a;

  a = 0;
  param->cam = 0;
  param->view = 0;
  param->camy = 100;
  if ((file = my_read()) == NULL)
    return (NULL);
  line_start = 0;
  if ((param->nbr_ant = my_get_nbr(recup_line(file, line_start++))) == -1)
    return (NULL);
  param->name_start = detect_start(file);
  line_end = line_start;
  while (check_char(recup_line(file, line_end), '-') == 0)
    line_end++;
  if ((param->base = init_base(file, line_start, line_end - 1, param)) == NULL)
    return (NULL);
  line_start = line_end;
  return (init_file2(file, param, line_start, line_end));
}
