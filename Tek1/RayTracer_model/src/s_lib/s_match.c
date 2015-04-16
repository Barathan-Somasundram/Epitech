/*
** s_match.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 17:43:17 2013 vincent colliot
** Last update Fri May 31 20:28:12 2013 vincent colliot
*/

#include "strings.h"

size_t	hempty(const char *s)
{
  return (strspn(s, " \t"));
}

BOOL	empty(const char *s)
{
  int	i;

  if (!s)
    return (TRUE);
  i = 0;
  while (s[i] == ' ' || s[i] == 9)
    i++;
  if (!s[i])
    return (TRUE);
  return (FALSE);
}
