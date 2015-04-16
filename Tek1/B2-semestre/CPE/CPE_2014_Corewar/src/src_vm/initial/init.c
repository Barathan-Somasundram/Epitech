/*
** init.c for corewar in /home/somasu_b/rendu/corewar/VM/retcode/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Apr  1 17:53:55 2014 somasu_b
** Last update Sun Apr 13 19:18:04 2014 somasu_b
*/

#include "my_strings.h"
#include "vm.h"

int	init_retcode(t_core *corewar)
{
  corewar->retcode[0] = &live;
  corewar->retcode[1] = &load;
  corewar->retcode[2] = &store;
  corewar->retcode[3] = &add;
  corewar->retcode[4] = &sub;
  corewar->retcode[5] = &and;
  corewar->retcode[6] = &or;
  corewar->retcode[7] = &xor;
  corewar->retcode[8] = &zjump;
  corewar->retcode[9] = &load_index;
  corewar->retcode[10] = &store_index;
  corewar->retcode[11] = &cor_fork;
  corewar->retcode[12] = &long_load;
  corewar->retcode[13] = &long_load_index;
  corewar->retcode[14] = &cor_long_fork;
  corewar->retcode[15] = &aff;
  return (0);
}

int	init_champs(t_champs **champs, int ac, char **av, int begin)
{
  if (create_root_champ(champs) == -1)
    return (-1);
  while (begin < ac)
    {
      if (stock_champ(av, champs, &begin) == -1)
	return (-1);
      ++begin;
    }
  return (0);
}

int	init_arena(t_core *corewar)
{
  int	i;

  i = 0;
  while (i <= MEM_SIZE)
    corewar->arena[i++] = 0;
  corewar->arena[MEM_SIZE] = 0;
  return (0);
}

int	init_dump(t_core *corewar, int ac, char **av, int *begin)
{
  int	i;

  i = 1;
  corewar->dump = -1;
  if (my_strcmp(av[1], "-dump") == 0)
    {
      if (i + 2 < ac)
	{
	  corewar->dump = my_get_nbr(av[i + 1]);
	  if (corewar->dump <= 0)
	    return (my_perror("Error : the number of cycles must be positiv\n"
			      , NULL));
	}
      else
	return (my_perror("Error : there is may be no champion\n", NULL));
    }
  if (corewar->dump > 0)
    *begin = *begin + 2;
  return (0);
}

int	init_corewar(t_core *corewar)
{
  corewar->nb_champ = 0;
  corewar->proc = 0;
  corewar->nbr_live = 0;
  corewar->cycle_to_die = CYCLE_TO_DIE;
  corewar->cycle_of_now = 1;
  init_arena(corewar);
  return (0);
}
