/*
** label_search.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Tue Apr  8 10:57:06 2014 taille_a
** Last update Sat Apr 12 14:06:15 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

int		label_search_down(t_list **list, char *label)
{
  int		nbr;
  t_list	*elem;

  nbr = 0;
  elem = *list;
  while (elem != NULL && my_strcmp(label, elem->is_a_label) != 0)
    {
      nbr += elem->byte_used + 1;
      elem = elem->prev;
    }
  if (elem != NULL)
    return (nbr);
  return (-1);
}

int		label_search_up(t_list **list, char *label)
{
  int		nbr;
  t_list	*elem;
  int		i;

  nbr = 0;
  i = 0;
  elem = *list;
  while (elem != NULL && my_strcmp(label, elem->is_a_label) != 0)
    {
      nbr -= (i > 0) ?  elem->byte_used : 0;
      if (elem->token_list != NULL)
	++i;
      elem = elem->next;
    }
  if (elem != NULL)
    {
      if (i > 1)
	return (nbr - (elem->byte_used + i - 1));
      else if (i == 0)
	return (nbr);
      else
	return (nbr - (elem->byte_used + 1));
    }
  else
    return (1);
}
