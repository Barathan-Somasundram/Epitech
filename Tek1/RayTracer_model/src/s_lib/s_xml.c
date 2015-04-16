/*
** s_xml.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 00:28:06 2013 vincent colliot
** Last update Thu Jun  6 22:17:09 2013 vincent colliot
*/

#include "token.h"
#include "strings.h"
#include "get_next_line.h"

char	*move_to_end_comment(char *s, FD xml)
{
  BOOL	b;

  b = FALSE;
  if (!NMATCH(OPEN_COMMENT, s) && !empty(s))
    return (s);
  if (empty(s) || (b = !S_IN(END_COMMENT, s))
      || empty(s + strslen(s, END_COMMENT) + strlen(END_COMMENT)))
    s = get_next_line(xml);
  if (b && !S_IN(END_COMMENT, s))
    while ((s = get_next_line(xml)) && !S_IN(END_COMMENT, s))
      free(s);
  if (empty(s))
    while ((s = get_next_line(xml)) && empty(s))
      free(s);
  if (!s)
    return (NULL);
  return (s + (b || NMATCH(OPEN_COMMENT, s))
	  * (strslen(s, END_COMMENT) + strlen(END_COMMENT)));
}
