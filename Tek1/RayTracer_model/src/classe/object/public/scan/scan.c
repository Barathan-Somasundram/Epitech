/*
** scan.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 16:57:37 2013 vincent colliot
** Last update Mon Jun  3 17:36:31 2013 vincent colliot
*/

#include <stdio.h>
#include "object.h"
#include "bool.h"
#include "strings.h"
#include "xmalloc.h"
#include "get_next_line.h"

static BOOL check_fd(char *s, FD xml, FLAG i, char **r)
{
  s = get_next_line(xml);
  while (s && NMATCH(OPEN_COMMENT, s += hempty(s)))
    s = move_to_end_comment(s, xml);
  *r = s;
  if (!s)
    fprintf(stderr, "no <object> close\n");
  if (!s)
    return (FALSE);
  if (i == END && MATCH("</object>", s + hempty(s)))
    return (FALSE);
  else if (i == END)
    return (TRUE);
  return (FALSE);
}

static void	scan_line(CLASS_OBJECT *object, FD xml, char *s)
{
  t_token	*token;
  char		*name;
  size_t	i;

  if ((name = xml_token(&token, s, INIT, xml)))
    {
      i = 0;
      while ((object->scan)[i].name)
	if (NMATCH(((object->scan)[i]).name, name))
	  {
	    (((object->scan)[i]).call)(object, token);
	    return ;
	  }
	else
	  i++;
    }
  (void)printf("in object def: error :%s not recognized\n", name);
  (void)(exit(-42));
}

void	add_object(void *d, FD xml, char *s)
{
  BOOL check;
  CLASS_OBJECT	*object;

  check = TRUE;
  objects_init(&object, d, s, xml);
  while ((check = check_fd(s, xml, END, &s)))
    scan_line(object, xml, s);
}
