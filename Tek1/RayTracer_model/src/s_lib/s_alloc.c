/*
** s_alloc.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 18:26:27 2013 vincent colliot
** Last update Tue May 28 18:30:49 2013 vincent colliot
*/

#include "string.h"
#include "xmalloc.h"

void	*my_strdup(const char *s)
{
  char		*r;
  size_t	i;

  i = 0;
  r = xmalloc(sizeof(char) * (strlen(s) + sizeof(char)));
  while (s[i])
    {
      r[i] = s[i];
      i++;
    }
  r[i] = 0;
  return (r);
}

void	*my_strndup(const char *s, size_t n)
{
  char		*r;
  size_t	i;

  i = 0;
  if (strlen(s) < n)
    r = xmalloc(sizeof(char) * (strlen(s) + sizeof(char)));
  else
    r = xmalloc(sizeof(char) * (n + sizeof(char)));
  while (s[i] && i < n)
    {
      r[i] = s[i];
      i++;
    }
  r[i] = 0;
  return (r);
}

