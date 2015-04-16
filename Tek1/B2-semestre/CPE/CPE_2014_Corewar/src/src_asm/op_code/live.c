/*
** live.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Mar 27 11:27:10 2014 taille_a
** Last update Thu Apr 10 13:19:09 2014 taille_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

int		live(t_list **list)
{
  t_toke	*elem;

  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 1;
  (*list)->tab[0] = 4;
  if (elem == NULL)
    return (INVALID_FILE);
  if (verif_direct(elem->buff) == INVALID_FILE)
    return (INVALID_FILE);
  (*list)->code = 0;
  if (elem->prev != NULL)
    return (INVALID_FILE);
  return (4);
}
