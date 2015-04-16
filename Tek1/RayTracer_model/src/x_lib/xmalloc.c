/*
** xmalloc.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 18:21:19 2013 vincent colliot
** Last update Tue May 28 18:26:16 2013 vincent colliot
*/

#include <stdio.h>
#include "xmalloc.h"

void	*xmalloc(size_t	t)
{
  void	*n;

  if ((n = malloc(t)) == NULL)
    {
      fprintf(stderr, "after a malloc of %u size, WTF BOOOOM\n",
	      (unsigned int)t);
      exit(EXIT_FAILURE);
    }
  return (n);
}
