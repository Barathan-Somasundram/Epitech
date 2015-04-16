/*
** xor.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Fri Mar 28 11:14:59 2014 taille_a
** Last update Sun Apr 13 13:18:35 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"

void		put_value_to_tab(t_list **list)
{
  (*list)->tab[2] = 1;
  (*list)->code = get_byte_code((*list)->tab);
  (*list)->tab[0] = (*list)->tab[0] == T_REG ? 1 : (*list)->tab[0] == T_DIR ?
    DIR_SIZE : (*list)->tab[1] == T_IND ? IND_SIZE : 0;
  (*list)->tab[1] = (*list)->tab[1] == T_REG ?  1 : (*list)->tab[1] == T_DIR ?
    DIR_SIZE : (*list)->tab[1] == T_IND ? IND_SIZE : 0;

}

int		xor(t_list **list)
{
  t_toke	*elem;
  int		i;

  i = 0;
  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 8;
  if (elem == NULL)
    return (INVALID_FILE);
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
  put_value_to_tab(list);
  return ((*list)->tab[0] + (*list)->tab[1] + (*list)->tab[2] + 1);
}
