/*
** utils.c for malloc in /home/song_k/rendu/PSU_2014_malloc
**
** Made by song kevin
** Login   <song_k@epitech.net>
**
** Started on  Sun Feb 15 16:48:14 2015 song kevin
** Last update Sun Feb 15 19:10:53 2015 song kevin
*/

#include "malloc.h"

void		*re_use_mem(t_data *data, size_t size)
{
  t_data	*new;

  data->free = NOT_FREE;
  if (data->size > size + sizeof(t_data))
    {
      new = data->ptr + size;
      new->ptr = (void*)new + sizeof(t_data);
      new->free = IS_FREE;
      new->size = data->size - size - sizeof(t_data);
      new->lost = 0;
      new->prev = data;
      new->next = data->next;
      if (data->next)
	data->next->prev = new;
      data->next = new;
    }
  else
    data->lost = data->size - size;
  data->size = size;
  return (data->ptr);
}

void		*find_in_mem(size_t size, char *check)
{
  t_data	*tmp;
  t_data	*best;

  best = NULL;
  tmp = g_mem;
  while (tmp && best == NULL)
    {
      if (tmp->free == IS_FREE && tmp->size >= size)
	best = tmp;
      tmp = tmp->next;
    }
  if (best == NULL)
    return (NULL);
  *check = 0;
  g_maxsize = size > g_maxsize ? size : g_maxsize;
  return (re_use_mem(best, size));
}
