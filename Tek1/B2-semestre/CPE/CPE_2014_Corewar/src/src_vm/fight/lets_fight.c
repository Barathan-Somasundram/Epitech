/*
** lets_fight.c for corewar in /home/somasu_b/rendu/corewar/VM/retcode/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Apr  1 18:20:29 2014 somasu_b
** Last update Sun Apr 13 21:06:22 2014 somasu_b
*/

#include "vm.h"
#include "my_strings.h"

static int	exec_command(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int		i;

  corewar->retcode[(*elem)->opcode.code - 1](corewar, champs, elem);
  if ((*elem)->opcode.code != 9)
    move_pc(corewar, elem, AFTER_CMD);
  i = 0;
  while (i < 4)
    (*elem)->opcode.type[i++] = 0;
  if ((*elem)->opcode.code == 1)
    ++corewar->nbr_live;
  return (0);
}

static int	is_champs_alive(t_core *corewar, t_champs **champs)
{
  t_champs	*elem;
  int		nb_champ;

  nb_champ = 0;
  elem = (*champs)->next;
  while (elem != *champs)
    {
      if (elem->cycle_to_live > corewar->cycle_to_die)
	{
	  kill_champs(champs, elem);
	  elem = (*champs)->next;
	  nb_champ = 0;
	}
      else
	{
	  if (elem->my_father == 0 || elem->my_father < 4)
	    ++nb_champ;
	  elem = elem->next;
	}
    }
  if (nb_champ > 0)
    return (1);
  return (0);
}

static int	check_if_exec(t_core *corewar, t_champs **champs
			      , t_champs **elem)
{
  if ((*elem)->cycle_to_exec == 0)
    {
      if (corewar->arena[PC((*elem)->pc)] > 0
	  && corewar->arena[PC((*elem)->pc)] < 17)
	{
	  my_get_cmd(corewar, elem);
	  (*elem)->cycle_to_exec = (*elem)->opcode.nbr_cycles;
	  move_pc(corewar, elem, PARAM_OCT);
	}
      else
	(*elem)->pc++;
    }
  else if ((*elem)->cycle_to_exec == 1)
    {
      exec_command(corewar, champs, elem);
      (*elem)->cycle_to_exec = 0;
    }
  else
    --(*elem)->cycle_to_exec;
  return (0);
}

static int	exec_champs_cmd(t_core *corewar, t_champs **champs)
{
  t_champs	*elem;

  elem = (*champs)->next;
  while (elem != *champs)
    {
      check_if_exec(corewar, champs, &elem);
      ++elem->cycle_to_live;
      elem = elem->next;
      if (corewar->nbr_live >= NBR_LIVE)
      	{
      	  corewar->cycle_to_die = corewar->cycle_to_die - CYCLE_DELTA;
      	  corewar->nbr_live = 0;
      	}
    }
  return (0);
}

int		lets_fight(t_core *corewar, t_champs *champs)
{
  while (corewar->cycle_to_die > 0)
    {
      if (is_champs_alive(corewar, &champs) == 0)
	{
	  corewar_winner(corewar, champs);
	  return (0);
	}
      exec_champs_cmd(corewar, &champs);
      if (corewar->cycle_of_now == corewar->dump)
	{
	  arena_dump(corewar, champs);
	  return (0);
	}
      ++(corewar->cycle_of_now);
    }
  corewar_winner(corewar, champs);
  return (0);
}
