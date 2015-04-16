/*
** ld.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Mar 27 10:10:56 2014 taille_a
** Last update Thu Apr 10 11:35:19 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

static int	ld_second_arg(char *buff)
{
  if (buff == NULL)
    return (INVALID_FILE);
  if (verif_register(buff) == INVALID_FILE)
    return (INVALID_FILE);
  else
    return (T_REG);
}

static int	ld_first_arg(char *buff)
{
  int		i;

  i = 0;
  if (buff == NULL)
    return (INVALID_FILE);
  while (buff[i] == ' ' || buff[i] == '-')
    ++i;
  if (buff[i] == 'r')
    {
      if (verif_register(buff) == INVALID_FILE)
	return (INVALID_FILE);
      return (T_REG);
    }
  else if (buff[i] == '%')
    {
      if (verif_direct(buff) == INVALID_FILE)
	return (INVALID_FILE);
      return (T_DIR);
    }
  else
    {
      if (verif_indirect(buff) == INVALID_FILE)
	return (INVALID_FILE);
      return (T_IND);
    }
}

int	get_bytes_used(int *tab)
{
  int		res;

  res = (tab[0] == T_REG) ? 1 : (tab[0] == T_DIR) ?
    DIR_SIZE : (tab[0] == T_IND) ? IND_SIZE : 0;
  res += (tab[1] == T_REG) ? 1 : (tab[1] == T_DIR) ?
    DIR_SIZE : (tab[1] == T_IND) ? IND_SIZE : 0;
  res += (tab[2] == T_REG) ? 1 : (tab[2] == T_DIR) ?
    DIR_SIZE : (tab[2] == T_IND) ? IND_SIZE : 0;
  return (res);
}

static char	get_code_byte(int *tab)
{
  char		code;

  if (tab[0] == T_REG)
    code = 0b01 << 6;
  else if (tab[0] == T_DIR)
    code = 0b10 << 6;
  else
    code = 0b11 << 6;
  code += 0b01 << 4;
  return (code);
}

int		ld(t_list **list)
{
  t_toke        *elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 2;
  if (elem == NULL)
    return (INVALID_FILE);
  if (((*list)->tab[0] = ld_first_arg(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  elem = elem->prev;
  if (elem == NULL)
    return (INVALID_FILE);
  if (((*list)->tab[1] = ld_second_arg(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->code = get_code_byte((*list)->tab);
  (*list)->byte_used = get_bytes_used((*list)->tab) + 1;
  (*list)->tab[0] = 4;
  if (elem->prev != NULL)
    return (INVALID_FILE);
  return ((*list)->byte_used);
}
