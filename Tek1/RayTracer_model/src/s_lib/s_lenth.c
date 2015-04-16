/*
** s_lenth.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 21:27:15 2013 vincent colliot
** Last update Tue May 28 18:43:08 2013 vincent colliot
*/

#include <string.h>
#include "strings.h"

size_t	strilen(const char *s, char c)
{
  size_t	i;

  i = 0;
  while (s[i] && s[i] != c)
    i++;
  return (i);
}

size_t	strslen(const char *s, const char *c)
{
  size_t	i;

  i = 0;
  while (s[i] && !NMATCH(c, s + i))
    i++;
  return (i);
}

size_t	sstrlen(const char *s, const char *c)
{
  return (strcspn(s, c));
}
