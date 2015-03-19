/*
** malloc.c for malloc in /home/song_k/rendu/PSU_2014_malloc
**
** Made by song kevin
** Login   <song_k@epitech.net>
**
** Started on  Wed Jan 28 10:37:11 2015 song kevin
** Last update Sun Feb 15 23:35:43 2015 song kevin
*/

#include <stdlib.h>
#include "malloc.h"

static size_t		g_pagesize;
t_data			*g_mem = NULL;
size_t			g_maxsize;

static t_data		*create_rest_list(t_data *new, size_t size,
					  size_t siz)
{
  t_data		*rest;

  rest = NULL;
  if (size - siz > sizeof(t_data) * 2)
    {
      rest = new->ptr + siz;
      rest->ptr = (void*)rest + sizeof(t_data);
      rest->lost = 0;
      rest->free = IS_FREE;
      rest->size = size - siz - sizeof(t_data) * 2;
      rest->prev = new;
      rest->next = NULL;
    }
  return (rest);
}

static void		*put_in_page_list2(t_data *elem, size_t size,
					   size_t tsize)
{
  t_data		*tmp;

  elem->ptr = (void*)elem + sizeof(*elem);
  elem->free = NOT_FREE;
  elem->size = size;
  elem->lost = tsize - size > sizeof(t_data) * 2
    ? 0 : tsize - size - sizeof(t_data);
  elem->prev = g_mem;
  elem->next = NULL;
  elem->next = create_rest_list(elem, tsize, size);
  tmp = g_mem;
  while (tmp->next)
    tmp = tmp->next;
  if (tmp->next)
    tmp->next->prev = elem;
  tmp->next = elem;
  return (elem->ptr);
}

static void		*put_in_page_list(size_t size)
{
  t_data		*elem;
  size_t		tsize;
  void			*ptr;
  char			check;

  check = 1;
  if (g_mem && size <= g_maxsize && (ptr = find_in_mem(size, &check)))
    return (ptr);
  tsize = size + sizeof(t_data) > g_pagesize
    ? size + sizeof(t_data) : g_pagesize;
  while (tsize % 8)
    ++tsize;
  if ((elem = sbrk(tsize)) == (void*)-1)
    return (NULL);
  g_maxsize = size > g_maxsize ? size : g_maxsize;
  return (put_in_page_list2(elem, size, tsize));
}

static void		*init_list(size_t size)
{
  size_t		tsize;

  g_pagesize = getpagesize() * 33;
  g_maxsize = g_pagesize + 1;
  tsize = size + sizeof(t_data) > g_pagesize
    ? size + sizeof(t_data) : g_pagesize;
  while (tsize % 8)
    ++tsize;
  if ((g_mem = sbrk(sizeof(t_data) + tsize)) == (void*)-1)
    return (NULL);
  g_mem->ptr = (void*)g_mem + sizeof(t_data);
  g_mem->lost = 0;
  g_mem->size = tsize;
  g_mem->free = IS_FREE;
  g_mem->next = NULL;
  g_mem->prev = NULL;
  return (re_use_mem(g_mem, size));
}

void			*malloc(size_t size)
{
  if (g_mem == NULL)
    return (init_list(size));
  if ((ssize_t)size < 0 || g_mem == (void*)-1)
    return (NULL);
  return (put_in_page_list(size));
}
