/*
** lerror.h<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 30 23:38:27 2013 vincent colliot
** Last update Thu May 30 23:42:11 2013 vincent colliot
*/

#include <stdio.h>
#include <stdlib.h>
#include "lerror.h"

void	lerror(char *s)
{
  fprintf(stderr, "%s", s);
  exit(EXIT_FAILURE);
}
