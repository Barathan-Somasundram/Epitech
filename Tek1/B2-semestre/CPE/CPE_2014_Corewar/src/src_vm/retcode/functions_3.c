/*
** functions_3.c for Corewar in /home/somasu_b/rendu/corewar/VM/retcode
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Mar 22 21:16:29 2014 somasu_b
** Last update Sun Apr 13 18:42:05 2014 a
*/

#include "vm.h"
#include "my_strings.h"

int	zjump(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	mov;

  if ((*elem)->carry == 0)
    return (0);
  mov = my_get_param(corewar, *elem, 0) % IDX_MOD;
  mov = mov - 1;
  (*elem)->pc = PC((*elem)->pc + mov);
  return (0);
}

int	load_index(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];
  int	s;

  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = my_get_param(corewar, *elem, 1);
  param[2] = REG_NBR(my_get_param(corewar, *elem, 2));
  if ((*elem)->opcode.type[0] == 1)
    param[0] = (*elem)->registers[REG_NBR(param[0])];
  if ((*elem)->opcode.type[1] == 1)
    param[1] = (*elem)->registers[REG_NBR(param[1])];
  s = my_get_value(corewar, (*elem)->pc + (param[0] % IDX_MOD), IND_SIZE);
  s += param[1];
  s = s % IDX_MOD;
  (*elem)->registers[param[2]] = corewar->arena[PC((*elem)->pc + s)];
  (*elem)->carry = CARRY_MOD((*elem)->registers[param[2]]);
  return (0);
}

int	store_index(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];
  int	tmp;

  param[0] = (*elem)->registers[REG_NBR(my_get_param(corewar, *elem, 0))];
  param[1] = my_get_param(corewar, *elem, 1);
  param[2] = my_get_param(corewar, *elem, 2);
  if ((*elem)->opcode.type[1] == 1)
    param[1] = (*elem)->registers[REG_NBR(param[1])];
  if ((*elem)->opcode.type[2] == 1)
    param[2] = (*elem)->registers[REG_NBR(param[2])];
  tmp = (*elem)->pc + (param[1] + param[2]) % IDX_MOD;
  corewar->arena[tmp] = (unsigned char)param[0];
  return (0);
}

int	long_load(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[2];

  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = REG_NBR(my_get_param(corewar, *elem, 1));
  (*elem)->registers[0] = param[0];
  (*elem)->carry = CARRY_MOD(param[0]);
  return (0);
}

int	long_load_index(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];
  int	s;

  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = my_get_param(corewar, *elem, 1);
  param[2] = REG_NBR(my_get_param(corewar, *elem, 2));
  if ((*elem)->opcode.type[0] == 1)
    param[0] = (*elem)->registers[REG_NBR(param[0])];
  if ((*elem)->opcode.type[1] == 1)
    param[1] = (*elem)->registers[REG_NBR(param[1])];
  s = my_get_value(corewar, (*elem)->pc + param[0], IND_SIZE);
  s += param[1];
  (*elem)->registers[param[2]] = corewar->arena[PC((*elem)->pc + s)];
  (*elem)->carry = CARRY_MOD((*elem)->registers[param[2]]);
  return (0);
}
