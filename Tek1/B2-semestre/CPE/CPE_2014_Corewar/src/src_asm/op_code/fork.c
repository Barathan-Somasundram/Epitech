/*
** fork.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sun Mar 30 16:42:07 2014 taille_a
** Last update Thu Apr 10 12:01:52 2014 taille_a
*/

#include "asm.h"

int		fork_asm(t_list **list)
{
  t_toke	*elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 12;
  if (elem == NULL)
    return (INVALID_FILE);
  if ((verif_direct(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->tab[0] = IND_SIZE;
  (*list)->code = 0;
  if (elem->prev != NULL)
    return (INVALID_FILE);
  return (2);
}
