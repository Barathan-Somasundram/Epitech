/*
** sub.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Mar 27 13:12:39 2014 taille_a
** Last update Thu Apr 10 11:37:49 2014 taille_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

int		sub(t_list **list)
{
  t_toke	*elem;
  int		i;

  i = 0;
  elem = (*list)->token_list;
  elem = elem->prev;
  (*list)->op_code = 5;
  if (elem == NULL)
    return (INVALID_FILE);
  while (elem != NULL && i < 3)
    {
      if ((verif_register(elem->buff)) == INVALID_FILE)
	return (INVALID_FILE);
      (*list)->tab[i] = 1;
      elem = elem->prev;
      ++i;
    }
  (*list)->code = 0b01010100;
  if (i < 3 || (i == 3 && elem != NULL))
    return (INVALID_FILE);
  return (get_bytes_used((*list)->tab) + 1);
}
