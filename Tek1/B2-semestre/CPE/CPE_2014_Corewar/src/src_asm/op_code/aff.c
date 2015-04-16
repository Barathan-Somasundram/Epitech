/*
** aff.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 31 10:18:53 2014 taille_a
** Last update Thu Apr 10 12:00:49 2014 taille_a
*/

#include "asm.h"

int		aff(t_list **list)
{
  t_toke	*elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 16;
  if (elem == NULL)
    return (INVALID_FILE);
  if (((*list)->tab[0] = verif_register(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->tab[0] = 1;
  (*list)->code = 0b01000000;
  if (elem->prev != NULL)
    return (INVALID_FILE);
  return (1 + 1);
}
