/*
** my_exit.c for core in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Apr  7 11:09:50 2014 taille_a
** Last update Sun Apr 13 17:30:16 2014 a
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

void		free_list(t_toke **list)
{
  t_toke	*elem;

  elem = *list;
  while (elem != NULL)
    {
      if (elem->buff)
      	free(elem->buff);
      *list = elem->prev;
      free(elem);
      elem = *list;
    }
}

void		my_exit(t_list **list, char *msg)
{
  t_list	*elem;

  elem = *list;
  while (elem->next != NULL)
    elem = elem->next;
  *list = elem;
  while (elem != NULL)
    {
      free(elem->buff);
      if (elem->token_list)
      	free_list(&elem->token_list);
      *list = elem->prev;
      free(elem);
      elem = *list;
    }
  write(2, msg, my_strlen(msg));
  exit(-1);
}

void		free_all(t_list **list)
{
  t_list	*elem;

  if (*list != NULL)
    {
      elem = *list;
      while (elem->next != NULL)
	elem = elem->next;
      *list = elem;
      while (elem != NULL)
	{
	  free(elem->buff);
	  free(elem->ne_buff);
	  if (elem->token_list)
	    free_list(&elem->token_list);
	  *list = elem->prev;
	  free(elem);
	  elem = *list;
	}
    }
}
