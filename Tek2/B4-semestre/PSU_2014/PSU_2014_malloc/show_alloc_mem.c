/*
** show_alloc_mem.c for malloc in /home/song_k/rendu/PSU_2014_malloc
**
** Made by song kevin
** Login   <song_k@epitech.net>
**
** Started on  Fri Feb  6 12:21:47 2015 song kevin
** Last update Sun Feb 15 23:38:51 2015 song kevin
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

void		show_alloc_mem(void)
{
  t_data	*tmp;
  void		*a;

  a = sbrk(0);
  printf("break : %p\n", a);
  if (g_mem == NULL)
    return ;
  tmp = g_mem;
  while (tmp)
    {
      printf("%p - %p : %zu octets\n",
	     tmp, (void*)tmp + sizeof(t_data), sizeof(t_data));
      printf("%p - %p : %zu octets\n",
	     tmp->ptr, tmp->ptr + tmp->size, tmp->size);
      tmp = tmp->next;
    }
}
