/*
** init_move.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sat Apr 26 18:13:32 2014 potier_g
** Last update Sun May  4 19:47:08 2014 potier_g
*/

#include <stdlib.h>
#include "struct.h"

int		detect_nbr_ant(char *line)
{
  int		nbr_ant;

  nbr_ant = 0;
  while (recup_word(line, nbr_ant) != NULL)
    nbr_ant++;
  return (nbr_ant / 2);
}

char		*my_new(char *str)
{
  int		size;
  int		a;
  char		*new;

  size = my_strlen(str);
  a = 0;
  if ((new = malloc(sizeof(int) * (size + 1))) == NULL)
    return (NULL);
  while (a < size)
    new[a] = str[a++];
  new[a] = '\0';
  return (new);
}

char		**reinit(char **tab, int size)
{
  int		a;

  a = 0;
  while (a < size)
    {
      if ((tab[a] = my_new("#null\0")) == NULL)
	return (NULL);
      a++;
    }
  return (tab);
}

int		init_move2(char *line, int pos, t_move *move, t_param *param)
{
  int		id_ant;
  int		tmp_id;
  char		*name;

  tmp_id = 0;
  if ((move[pos].nxt_base = malloc(sizeof(char *) * param->nbr_ant)) == NULL
      || (move[pos].prev_base = malloc(sizeof(char *)
				       * param->nbr_ant)) == NULL)
    return (-1);
  reinit(move[pos].nxt_base, param->nbr_ant);
  reinit(move[pos].prev_base, param->nbr_ant);
  while (tmp_id < move[pos].nbr_ant)
    {
      name = recup_word(line, tmp_id * 2);
      id_ant = my_get_nbr(name + 1) - 1;
      move[pos].nxt_base[id_ant] = recup_word(line, (tmp_id * 2) + 1);
      if (pos == 0 || my_strcmp(move[pos - 1].nxt_base[id_ant]
				, "#null\0") == 1)
	move[pos].prev_base[id_ant] = param->name_start;
      else
	move[pos].prev_base[id_ant] = move[pos - 1].nxt_base[id_ant];
      tmp_id++;
    }
  return (0);
}

t_move          *init_move(char *file, int line_s, int line_e, t_param *param)
{
  t_move        *move;
  int		line_act;
  int		pos;
  int		len;
  char		*line;

  pos = 0;
  len = line_e - line_s;
  param->size_move = len;
  if ((move = malloc(sizeof(*move) * len)) == NULL)
    return (NULL);
  line_act = line_s;
  while (pos < len)
    {
      line = recup_line(file, line_act);
      if (line[0] != '#')
	{
	  move[pos].nbr_ant = detect_nbr_ant(line);
	  if (init_move2(line, pos, move, param) == -1)
	    return (NULL);
	  pos++;
	}
      line_act++;
    }
  return (move);
}
