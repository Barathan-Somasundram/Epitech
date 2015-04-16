/*
** my_gets_info.c for corewar in /home/somasu_b/rendu/corewar/vm
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Apr  7 23:25:56 2014 somasu_b
** Last update Sun Apr 13 18:04:00 2014 a
*/

#include "vm.h"

int		args_type_in_4(t_champs **elem, int value)
{
  int		i;

  i = 0;
  while (i < MAX_ARGS_NUMBER)
    (*elem)->opcode.type[i++] = 0;
  i = MAX_ARGS_NUMBER - 1;
  while (i >= 0)
    {
      (*elem)->opcode.type[i--] = value % 4;
      value /= 4;
    }
  i = 0;
  while (i < 4)
    {
      if (((*elem)->opcode.code == 10 || (*elem)->opcode.code == 11)
	  && (*elem)->opcode.type[i] == 2)
	(*elem)->opcode.type[i] = 3;
      if ((*elem)->opcode.type[i] == 2)
	(*elem)->opcode.type[i] = 4;
      else if ((*elem)->opcode.type[i] == 3)
	(*elem)->opcode.type[i] = 2;
      ++i;
    }
  return (0);
}

int		my_get_value(t_core *corewar, int pc, int size)
{
  int		res;
  int		oct;
  int		exp;

  res = 0;
  oct = 256;
  exp = size - 1;
  while (exp >= 0)
    {
      res = res * 256 + corewar->arena[PC(pc)];
      pc++;
      exp--;
    }
  while (size > 1)
    {
      oct = oct * 256;
      size--;
    }

  if (res > oct / 2)
    res = res - oct;
  return (res);
}

int		my_get_param(t_core *corewar, t_champs *elem, int nb_param)
{
  int		i;
  int		mov;

  i = 0;
  mov = 0;
  while (i < nb_param)
    {
      mov += elem->opcode.type[i];
      i++;
    }
  while (elem->opcode.type[nb_param] == 0 && nb_param < 4)
    ++nb_param;
  if (elem->opcode.type[nb_param] == 1)
    return (corewar->arena[PC(elem->pc + mov)]);
  else if (elem->opcode.type[nb_param] == 4)
    return (my_get_value(corewar, elem->pc + mov, 4));
  else if (elem->opcode.type[nb_param] == 2)
    {
      i = my_get_value(corewar, elem->pc + mov, 2);
      return (i);
    }
  return (0);
}

int		check_exception(t_core *corewar, t_champs **elem)
{
  int		i;

  i = 0;
  while (i < MAX_ARGS_NUMBER)
    (*elem)->opcode.type[i++] = 0;
  if ((*elem)->opcode.code == 1)
    (*elem)->opcode.type[0] = DIR_SIZE;
  else if ((*elem)->opcode.code == 9)
    (*elem)->opcode.type[0] = IND_SIZE;
  else if ((*elem)->opcode.code == 12 || (*elem)->opcode.code == 15)
    (*elem)->opcode.type[0] = IND_SIZE;
  else
    return (0);
  return (1);
}

int		my_get_cmd(t_core *corewar, t_champs **elem)
{
  (*elem)->opcode = op_tab[corewar->arena[PC((*elem)->pc)] - 1];
  if (check_exception(corewar, elem) == 1)
    return (0);
  else
    args_type_in_4(elem, corewar->arena[PC(((*elem)->pc + 1))]);
  (*elem)->pc++;
  return (0);
}
