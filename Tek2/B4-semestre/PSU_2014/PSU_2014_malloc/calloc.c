/*
** calloc.c for  in /home/somasu_b/double/PSU_2014_malloc
**
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 15 11:47:11 2015 SOMASUNDRAM Barathan
** Last update Sun Feb 15 19:03:25 2015 song kevin
*/

#include <stdlib.h>
#include <string.h>
#include "malloc.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*p;

  if (!size)
    return (malloc(size));
  if (!nmemb)
    return (NULL);
  if ((p = malloc(nmemb * size)) == NULL)
    return (NULL);
  p = memset(p, 0, nmemb * size);
  return (p);
}
