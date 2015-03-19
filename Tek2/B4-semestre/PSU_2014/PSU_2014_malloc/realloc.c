/*
** realloc.c for  in /home/somasu_b/double/PSU_2014_malloc
**
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 15 11:40:42 2015 SOMASUNDRAM Barathan
** Last update Sun Feb 15 23:14:02 2015 song kevin
*/

#include <stdlib.h>
#include <string.h>
#include "malloc.h"

static void	*eat_next_part(t_data *tmp, size_t size)
{
  void		*p;

  tmp->size += tmp->next->size + tmp->next->lost + sizeof(t_data);
  tmp->next = tmp->next->next;
  if (tmp->next)
    tmp->next->prev = tmp;
  p = re_use_mem(tmp, size);
  return (p);
}

void		*realloc(void *ptr, size_t size)
{
  void		*p;
  t_data	*tmp;

  if (size == 0)
    {
      free(ptr);
      return (ptr);
    }
  if (ptr == NULL)
    return (malloc(size));
  tmp = ptr - sizeof(t_data);
  if (tmp->next && tmp->next->free == IS_FREE
      && tmp->next->size + sizeof(t_data) + tmp->size >= size)
    return (eat_next_part(tmp, size));
  if ((p = malloc(size)) == NULL)
    return (NULL);
  p = memcpy(p, ptr, size < tmp->size ? size : tmp->size);
  free(ptr);
  return (p);
}
