/*
** scan.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 02:20:08 2013 vincent colliot
** Last update Wed Jun  5 15:30:30 2013 vincent colliot
*/

#include <stdio.h>
#include "eye.h"
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
    fprintf(stderr, "no <eye> close\n");
  if (!s)
    return (FALSE);
  if (i == END && MATCH("</eye>", s + hempty(s)))
    return (FALSE);
  else if (i == END)
    return (TRUE);
  return (FALSE);
}

static void	scan_line(CLASS_EYE *eye, FD xml, char *s)
{
  t_token	*token;
  char		*name;
  size_t	i;

  if ((name = xml_token(&token, s, INIT, xml)))
    {
      i = 0;
      while ((eye->scan)[i].name)
	if (NMATCH(((eye->scan)[i]).name, name))
	  {
	    (((eye->scan)[i]).call)(eye, token);
	    return ;
	  }
	else
	  i++;
    }
  (void)printf("error :%s not recognized", name);
  exit(-42);
}

void	add_eye(void *d, FD xml, char *s)
{
  BOOL check;
  CLASS_EYE	*eye;

  check = TRUE;
  eye = xmalloc(sizeof(*eye));
  eye_init(eye, d);
  while ((check = check_fd(s, xml, END, &s)))
    scan_line(eye, xml, s);
}
