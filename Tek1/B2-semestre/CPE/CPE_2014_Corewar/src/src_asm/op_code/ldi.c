/*
** ldi.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Fri Mar 28 18:20:10 2014 taille_a
** Last update Thu Apr 10 11:35:30 2014 taille_a
*/

#include "asm.h"

void		resize_tab(int *tab)
{
  tab[0] = (tab[0] == T_REG) ? 1 : IND_SIZE;
  tab[1] = (tab[1] == T_DIR) ? DIR_SIZE : (tab[1] == T_REG) ? 1 : 0;
  tab[2] = 1;
}

int		ldi(t_list **list)
{
  t_toke	*elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 10;
  if (!elem)
    return (INVALID_FILE);
  if (((*list)->tab[0] = get_type_argument(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  elem = elem->prev;
  if (!elem)
    return (INVALID_FILE);
  if (((*list)->tab[1] = get_type_argument(elem->buff)) ==
      INVALID_FILE || (*list)->tab[1] == T_IND)
    return (INVALID_FILE);
  elem = elem->prev;
  if (!elem)
    return (INVALID_FILE);
  if ((verif_register(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->code = get_byte_code((*list)->tab);
  resize_tab((*list)->tab);
  if (elem->prev != NULL)
    return (INVALID_FILE);
  return ((*list)->tab[0] + (*list)->tab[1] + (*list)->tab[2] + 1);
}
