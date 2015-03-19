/*
** free.c for malloc in /home/song_k/rendu/PSU_2014_malloc/project
**
** Made by song kevin
** Login   <song_k@epitech.net>
**
** Started on  Thu Feb 12 17:43:04 2015 song kevin
** Last update Sun Feb 15 23:40:31 2015 song kevin
*/

#include <stdlib.h>
#include <string.h>
#include "malloc.h"

static void		free_next(t_data *elem)
{
  elem->size += elem->next->size + elem->next->lost + sizeof(t_data);
  elem->next = elem->next->next;
  if (elem->next)
    elem->next->prev = elem;
  if (elem->next && elem->next->free == IS_FREE)
    free_next(elem);
}

static void		free_prev(t_data *elem)
{
  elem->prev->size += elem->size + sizeof(t_data);
  elem->prev->next = elem->next;
  if (elem->next)
    elem->next->prev = elem->prev;
  elem = elem->prev;
  if (elem->prev && elem->prev->free == IS_FREE)
    free_prev(elem);
}

void			free(void *ptr)
{
  t_data		*tmp;

  if (g_mem == NULL || ptr == NULL)
    return;
  tmp = ptr - sizeof(t_data);
   if (tmp->free == IS_FREE)
    return;
  tmp->size += tmp->lost;
  tmp->lost = 0;
  tmp->free = IS_FREE;
  if (tmp->next && tmp->next->free == IS_FREE)
    free_next(tmp);
  if (tmp->prev && tmp->prev->free == IS_FREE)
    free_prev(tmp);
}
