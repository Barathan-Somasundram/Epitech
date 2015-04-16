/*
** functions_2.c for Corewar in /home/somasu_b/rendu/corewar/VM/retcode
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Mar 22 21:14:38 2014 somasu_b
** Last update Sun Apr 13 18:05:28 2014 a
*/

#include "vm.h"

int	add(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];

  (void)champs;
  param[0] = (*elem)->registers[REG_NBR(my_get_param(corewar, *elem, 0))];
  param[1] = (*elem)->registers[REG_NBR(my_get_param(corewar, *elem, 1))];
  param[2] = REG_NBR(my_get_param(corewar, *elem, 2));
  (*elem)->registers[param[2]] = param[0] + param[1];
  (*elem)->carry = CARRY_MOD(param[0] + param[1]);
  return (0);
}

int	sub(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];

  (void)champs;
  param[0] = (*elem)->registers[REG_NBR(my_get_param(corewar, *elem, 0))];
  param[1] = (*elem)->registers[REG_NBR(my_get_param(corewar, *elem, 1))];
  param[2] = REG_NBR(my_get_param(corewar, *elem, 2));
  (*elem)->registers[param[2]] = param[0] - param[1];
  (*elem)->carry = CARRY_MOD(param[0] - param[1]);
  return (0);
}

int	and(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];

  (void)champs;
  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = my_get_param(corewar, *elem, 1);
  param[2] = REG_NBR(my_get_param(corewar, *elem, 2));
  if ((*elem)->opcode.type[0] == 1)
    param[0] = (*elem)->registers[REG_NBR(param[0])];
  if ((*elem)->opcode.type[1] == 1)
    param[1] = (*elem)->registers[REG_NBR(param[1])];
  (*elem)->registers[param[2]] = param[0] & param[1];
  (*elem)->carry = CARRY_MOD((param[0] & param[1]));
  return (0);
}

int	or(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];

  (void)champs;
  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = my_get_param(corewar, *elem, 1);
  param[2] = REG_NBR(my_get_param(corewar, *elem, 2));
  if ((*elem)->opcode.type[0] == 1)
    param[0] = (*elem)->registers[REG_NBR(param[0])];
  if ((*elem)->opcode.type[1] == 1)
    param[1] = (*elem)->registers[REG_NBR(param[1])];
  (*elem)->registers[param[2]] = param[0] | param[1];
  (*elem)->carry = CARRY_MOD((param[0] | param[1]));
  return (0);
}

int	xor(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param[3];

  (void)champs;
  param[0] = my_get_param(corewar, *elem, 0);
  param[1] = my_get_param(corewar, *elem, 1);
  param[2] = REG_NBR(my_get_param(corewar, *elem, 2));
  if ((*elem)->opcode.type[0] == 1)
    param[0] = (*elem)->registers[REG_NBR(param[0])];
  if ((*elem)->opcode.type[1] == 1)
    param[1] = (*elem)->registers[REG_NBR(param[1])];
  (*elem)->registers[param[2]] = param[0] ^ param[1];
  (*elem)->carry = CARRY_MOD((param[0] ^ param[1]));
  return (0);
}
