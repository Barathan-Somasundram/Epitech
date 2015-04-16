/*
** main.c for corewar in /home/somasu_b/rendu/corewar/VM/retcode/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Mar 30 23:18:58 2014 somasu_b
** Last update Sun Apr 13 19:36:02 2014 somasu_b
*/

#include <fcntl.h>
#include "my_strings.h"
#include "vm.h"

int		move_pc(t_core *corewar, t_champs **elem, int why)
{
  if (why == AFTER_CMD)
    {
      (*elem)->pc += ((*elem)->opcode.type[0]
		  + (*elem)->opcode.type[1]
		  + (*elem)->opcode.type[2]
		  + (*elem)->opcode.type[3]);
    }
  else if (why == PARAM_OCT)
    (*elem)->pc++;
  return (0);
}

int		virtual_machine(int ac, char **av)
{
  t_core	corewar;
  t_champs	*champs;
  int		begin;

  begin = 1;
  champs = NULL;
  if (init_dump(&corewar, ac, av, &begin) == -1)
    return (-1);
  if (check_champs_opt(ac, av, begin) == -1)
    return (-1);
  init_corewar(&corewar);
  if (init_champs(&champs, ac, av, begin) == -1)
    return (-1);
  if (places_champs(&champs, &corewar) == -1)
    return (-1);
  init_retcode(&corewar);
  if (lets_fight(&corewar, champs) == -1)
    return (-1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac <= 1)
    return (my_perror("Error : Too few arguments\ncorewar minimum champion"
		      " is one(1)\nUsage: corewar [-dump number of cycles]"
		      " [[-n programme number][-a load address]] file_name[.s]\n"
		      , NULL));
  if (ac > 23)
    return (my_perror("Error : Too many arguments\ncorewar maximum number "
		      "of arguments with options is 23\n", NULL));
  if (virtual_machine(ac, av) == -1)
    return (-1);
  return (0);
}
