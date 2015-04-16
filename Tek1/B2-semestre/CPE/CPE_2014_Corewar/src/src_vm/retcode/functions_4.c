/*
** functions_4.c for Corewar in /home/somasu_b/rendu/corewar/VM/retcode
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Mar 22 21:19:40 2014 somasu_b
** Last update Sun Apr 13 18:42:49 2014 a
*/

#include "vm.h"
#include "my_strings.h"

static int	copy_data(t_champs **elem, t_champs **son, int param, int id)
{
  int		i;

  (*son)->my_number = id;
  if ((*elem)->my_father != 0)
    (*son)->my_father = (*elem)->my_father;
  else
    (*son)->my_father = (*elem)->my_number;
  (*son)->registers[0] = (*son)->my_number;
  i = 0;
  while (++i < REG_NUMBER)
    (*son)->registers[i] = (*elem)->registers[i];
  (*son)->pc = ((*elem)->pc + param) % MEM_SIZE;
  (*son)->carry = (*elem)->carry;
  (*son)->cycle_to_live = 0;
  (*son)->cycle_to_exec = 0;
  i = -1;
  while (++i < PROG_NAME_LENGTH)
    (*son)->header.prog_name[i] = (*elem)->header.prog_name[i];
  i = -1;
  while (++i < COMMENT_LENGTH)
    (*son)->header.comment[i] = (*elem)->header.comment[i];
  (*son)->header.prog_size = (*elem)->header.prog_size;
  return (0);
}

int		cor_fork(t_core *corewar, t_champs **champs, t_champs **elem)
{
  t_champs	*son;
  t_champs	*tmp;
  int		param;
  int		i;

  i = 0;
  tmp = (*champs)->next;
  while (tmp != *champs)
    {
      tmp = tmp->next;
      ++i;
    }
  param = my_get_param(corewar, *elem, 0);
  if ((son = malloc(sizeof(*son))) == NULL)
    return (0);
  param = param % IDX_MOD;
  copy_data(elem, &son, param, i);
  son->prev = (*champs)->prev;
  son->next = *champs;
  (*champs)->prev->next = son;
  (*champs)->prev = son;
  return (0);
}

int	cor_long_fork(t_core *corewar, t_champs **champs, t_champs **elem)
{
  t_champs	*son;
  t_champs	*tmp;
  int		param;
  int		i;

  i = 0;
  while (tmp != *champs)
    {
      tmp = tmp->next;
      ++i;
    }
  param = my_get_param(corewar, *elem, 0);
  if ((son = malloc(sizeof(*son))) == NULL)
    return (0);
  copy_data(elem, &son, param, i);
  son->prev = (*champs)->prev;
  son->next = *champs;
  (*champs)->prev->next = son;
  (*champs)->prev = son;
  return (0);
}

int	aff(t_core *corewar, t_champs **champs, t_champs **elem)
{
  int	param;

  (void)champs;
  param = my_get_param(corewar, *elem, 0);
  if ((*elem)->opcode.type[0] == 1)
    param = (*elem)->registers[REG_NBR(param)];
  my_putchar(STDOUT_FILENO, (unsigned char)param);
  return (0);
}
