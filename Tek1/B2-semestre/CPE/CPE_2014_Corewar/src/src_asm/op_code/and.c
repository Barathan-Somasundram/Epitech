/*
** or.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Mar 27 13:15:05 2014 taille_a
** Last update Sun Apr 13 13:05:08 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

int		get_type_argument(char *buff)
{
  if (buff == NULL)
    return (INVALID_FILE);
  if (verif_register(buff) == 0)
    return (T_REG);
  else if (verif_direct(buff) == 0)
    return (T_DIR);
  else if (verif_indirect(buff) == 0)
    return (T_IND);
  else
    return (INVALID_FILE);
}

char		get_byte_code(int *tab)
{
  char		code;

  code = (tab[0] == T_REG) ? 0b01 << 6 :
    (tab[0] == T_DIR) ? 0b10 << 6 : (tab[0] == T_IND) ? 0b11 << 6 : 0;
  code += (tab[1] == T_REG) ? 0b01 << 4 :
    (tab[1] == T_DIR) ? 0b10 << 4 : (tab[1] == T_IND) ? 0b11 << 4 : 0;
  code += 0b01 << 2;
  tab[0] = tab[0] == T_REG ? 1 : tab[0] == T_DIR ?
    DIR_SIZE : tab[1] == T_IND ? IND_SIZE : 0;
  tab[1] = tab[1] == T_REG ?  1 : tab[1] == T_DIR ?
    DIR_SIZE : tab[1] == T_IND ? IND_SIZE : 0;
  tab[2] = 1;
  return (code);
}

int		and(t_list **list)
{
  t_toke	*elem;
  int		i;

  i = 0;
  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 6;
  while (elem != NULL && i < 2)
    {
      if (((*list)->tab[i++] =
	   get_type_argument(elem->buff)) == INVALID_FILE)
	return (INVALID_FILE);
      elem = elem->prev;
    }
  if (elem == NULL)
    return (INVALID_FILE);
  if (verif_register(elem->buff) == INVALID_FILE)
    return (INVALID_FILE);
  if (elem->prev != NULL)
    return (INVALID_FILE);
  (*list)->tab[i] = 1;
  (*list)->code = get_byte_code((*list)->tab);
  return ((*list)->tab[0] + (*list)->tab[1] + (*list)->tab[2] + 1);
}
