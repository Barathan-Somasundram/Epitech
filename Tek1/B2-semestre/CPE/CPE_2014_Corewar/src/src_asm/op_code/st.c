/*
** st.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Mar 27 11:29:46 2014 taille_a
** Last update Thu Apr 10 11:36:39 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static int	st_second_arg(char *buff)
{
  int		i;

  i = 0;
  if (buff == NULL)
    return (INVALID_FILE);
  while (buff[i] == ' ' || buff[i] == '\t')
    ++i;
  if (buff[i] == 'r')
    {
      if (verif_register(buff) == INVALID_FILE)
	return (INVALID_FILE);
      return (T_REG);
    }
  else
    {
      if (verif_indirect(buff) == INVALID_FILE)
	return (INVALID_FILE);
      return (T_IND);
    }
}

static int	st_first_arg(char *buff)
{
  if (buff == NULL)
    return (INVALID_FILE);
  if (verif_register(buff) == INVALID_FILE)
    return (INVALID_FILE);
  return (T_REG);
}

static int	st_get_byte_used(int *tab)
{
  int		res;

  res = 0;
  if (tab[0] == T_REG)
    {
      tab[0] = 1;
      res += 1;
    }
  if (tab[1] == T_IND)
    {
      tab[1] = IND_SIZE;
      res += IND_SIZE;
    }
  else if (tab[1] == T_REG)
    {
      tab[1] = 1;
      res += 1;
    }
  return (res);
}

static char	get_code_byte(int *tab)
{
  char		code;

  code = 0b01 << 6;
  if (tab[1] == T_REG)
    code += 0b01 << 4;
  else
    code += 0b11 << 4;
  return (code);
}

int		st(t_list **list)
{
  t_toke	*elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 3;
  if (elem == NULL)
    return (INVALID_FILE);
  if (((*list)->tab[0] = st_first_arg(elem->buff)) == INVALID_FILE)
      return (INVALID_FILE);
  elem = elem->prev;
  if (elem == NULL)
      return (INVALID_FILE);
  if (((*list)->tab[1] = st_second_arg(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  if (elem->prev != NULL)
    return (INVALID_FILE);
  (*list)->code = get_code_byte((*list)->tab);
  return (st_get_byte_used((*list)->tab) + 1);
}
