/*
** add.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Mar 27 12:40:19 2014 taille_a
** Last update Thu Apr 10 11:42:52 2014 taille_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

int		add(t_list **list)
{
  t_toke	*elem;
  int		i;

  i = 0;
  elem = (*list)->token_list;
  (*list)->op_code = 4;
  elem = elem->prev;
  while (elem != NULL)
    {
      if ((verif_register(elem->buff)) == INVALID_FILE)
	  return (INVALID_FILE);
      (*list)->tab[i] = 1;
      elem = elem->prev;
      ++i;
    }
  if (i < 3 || i > 3)
    return (INVALID_FILE);
  (*list)->code = 0b01010100;
  return (1 * 3 + 1);
}
