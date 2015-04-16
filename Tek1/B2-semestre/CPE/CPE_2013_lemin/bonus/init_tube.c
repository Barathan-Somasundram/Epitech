/*
** init_tube.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sat Apr 26 18:13:02 2014 potier_g
** Last update Sun May  4 01:48:59 2014 potier_g
*/

#include <stdlib.h>
#include "struct.h"

t_tube          *init_tube(char *file, int line_s, int line_e, t_param *param)
{
  t_tube        *tube;
  int		line_act;
  char		*line;
  int		len;
  int		pos;

  pos = 0;
  len = line_e - line_s + 1;
  param->size_tube = len;
  if ((tube = malloc(sizeof(*tube) * len)) == NULL)
    return (NULL);
  line_act = line_s;
  while (pos < len)
    {
      line = recup_line(file, line_act);
      if (line[0] != '#')
        {
	  tube[pos].name1 = recup_word(line, 0);
	  tube[pos++].name2 = recup_word(line, 1);
	}
      line_act++;
    }
  return (tube);
}
