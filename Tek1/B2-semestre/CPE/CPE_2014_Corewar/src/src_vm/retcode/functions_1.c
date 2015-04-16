/*
** functions_1.c for Corewar in /home/somasu_b/rendu/corewar/VM/retcode
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Mar 22 21:12:03 2014 somasu_b
** Last update Sun Apr 13 21:07:54 2014 somasu_b
*/

#include "vm.h"
#include "my_strings.h"

static int	copy_data(t_core *corewar, t_champs *tmp)
{
  int		i;

  if (tmp->my_father == 0)
    corewar->winner.pid = tmp->my_number;
  else
    corewar->winner.pid = tmp->my_father;
  i = -1;
  while (++i < PROG_NAME_LENGTH + 1)
    corewar->winner.name[i] = tmp->header.prog_name[i];
  i = -1;
  while (++i < COMMENT_LENGTH + 1)
    corewar->winner.comment[i] = tmp->header.comment[i];
  return (0);
}

int	live(t_core *corewar, t_champs **champs, t_champs **elem)
{
  t_champs	*tmp;
  int		param;

  tmp = *elem;
  param = my_get_param(corewar, *elem, 0);
  (void)param;
  if (tmp->my_number == (*elem)->registers[0])
    {
      if (tmp->my_father == 0)
      	{
  	  my_putstr("Le joueur ");
  	  my_put_nbr(tmp->my_number);
  	  my_putstr(", ");
  	  my_putstr(tmp->header.prog_name);
  	  my_putstr(", est en vie \n");
  	  copy_data(corewar, tmp);
  	}
      tmp->cycle_to_live = 0;
    }
  return (0);
}

int	load(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[2];

  (void)champs;
  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = REG_NBR(my_get_param(corewar, *elem, 1));
  (*elem)->carry = CARRY_MOD(param[0]);
  (*elem)->registers[param[1]] = param[0];
  return (0);
}

int	store(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[2];

  (void)champs;
  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = my_get_param(corewar, *elem, 1);
  if ((*elem)->opcode.type[0] == 1)
    param[0] = (*elem)->registers[REG_NBR(param[0])];
  if ((*elem)->opcode.type[1] == 1)
    (*elem)->registers[REG_NBR(param[1])] = param[0];
  else if ((*elem)->opcode.type[1] == 2)
    corewar->arena[PC((*elem)->pc + (param[1] % IDX_MOD))] = param[0];
  return (0);
}
