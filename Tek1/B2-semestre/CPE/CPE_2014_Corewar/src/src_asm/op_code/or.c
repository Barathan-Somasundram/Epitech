/*
** or.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Fri Mar 28 11:11:40 2014 taille_a
** Last update Sun Apr 13 13:17:55 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"

int		or(t_list **list)
{
  t_toke	*elem;
  int		i;

  i = 0;
  elem = (*list)->token_list;
  (*list)->op_code = 7;
  elem = elem->prev;
  while (elem != NULL && i < 2)
    {
      if (((*list)->tab[i++] =
	   get_type_argument(elem->buff)) == INVALID_FILE)
	return (INVALID_FILE);
      elem = elem->prev;
    }
  if (elem == NULL || i < 2)
    return (INVALID_FILE);
  if (verif_register(elem->buff) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->tab[i] = 1;
  (*list)->code = get_byte_code((*list)->tab);
  (*list)->tab[0] = (*list)->tab[0] == T_REG ? 1 : (*list)->tab[0] == T_DIR ?
    DIR_SIZE : (*list)->tab[1] == T_IND ? IND_SIZE : 0;
  (*list)->tab[1] = (*list)->tab[1] == T_REG ?  1 : (*list)->tab[1] == T_DIR ?
    DIR_SIZE : (*list)->tab[1] == T_IND ? IND_SIZE : 0;
  return ((*list)->tab[0] + (*list)->tab[1] + (*list)->tab[2] + 1);
}
