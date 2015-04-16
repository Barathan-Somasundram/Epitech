/*
** zjmp.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Fri Mar 28 11:44:45 2014 taille_a
** Last update Thu Apr 10 11:32:20 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"

int		zjmp(t_list **list)
{
  t_toke        *elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 9;
  (*list)->tab[0] = T_DIR;
  if (elem == NULL)
    return (INVALID_FILE);
  if ((verif_direct(elem->buff)) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->code = 0;
  return (2);
}
