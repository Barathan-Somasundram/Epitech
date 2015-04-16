/*
** place_champs.c for corewar in /home/somasu_b/rendu/corewar/vm
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri Apr  4 21:05:42 2014 somasu_b
** Last update Sun Apr 13 18:40:23 2014 a
*/

#include "vm.h"
#include "my_strings.h"

int		calc_mem_sep(t_champs *champs, t_core *corewar)
{
  t_champs	*tmp;
  int		sep;
  int		mem_total;

  mem_total = 0;
  sep = 0;
  tmp = champs->next;
  while (tmp != champs)
    {
      mem_total = mem_total + tmp->header.prog_size;
      ++corewar->nb_champ;
      tmp = tmp->next;
    }
  sep = (MEM_SIZE - 1) - mem_total;
  sep = sep / corewar->nb_champ;
  return (sep);
}

int		place_each_champs(t_champs **tmp, t_core *corewar
				  , int who, int **pos)
{
  int		i;
  int		j;

  j = -1;
  if (who == 1 && (*pos)[who] == -2)
    (*pos)[who] = 0;
  if ((*pos)[who] >= 0 && (*pos)[who] < MEM_SIZE)
    {
      (*tmp)->pc = (*pos)[who];
      if ((*tmp)->address == -2)
	(*tmp)->address = (*pos)[who];
      i = (*tmp)->pc;
      while (++j < (*tmp)->header.prog_size)
      	{
	  if (corewar->arena[i] != 0)
	    return (my_perror("Error : Overlap\n", NULL));
      	  corewar->arena[i] = (*tmp)->commands[j];
	  ++i;
      	}
      if (who < 4)
	(*pos)[who + 1] = (*pos)[who] + (*tmp)->header.prog_size + (*pos)[0];
    }
  else
    return (-1);
  return (0);
}

int		places_champs(t_champs **champs, t_core *corewar)
{
  t_champs	*tmp;
  int		*pos;
  int		count;
  int		sep;

  tmp = (*champs)->next;
  sep =	calc_mem_sep(*champs, corewar);
  if ((pos = malloc(sizeof(int) * 5)) == NULL)
    return (-1);
  count = 0;
  while (count < 5)
    pos[count++] = -2;
  count = 0;
  pos[0] = sep;
  while (tmp != *champs)
    {
      ++count;
      if (tmp->address >= 0)
	pos[count] = tmp->address;
      if (place_each_champs(&tmp, corewar, count, &pos) == -1)
	return (-1);
      tmp = tmp->next;
    }
  free(pos);
  return (0);
}
