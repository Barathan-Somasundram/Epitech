/*
** scan.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display/public/scan
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:48:42 2013 vincent colliot
** Last update Sat Jun  1 23:09:57 2013 vincent colliot
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "strings.h"
#include "bool.h"
#include "get_next_line.h"
#include "lerror.h"
#include "fd.h"
#include "display.h"

static BOOL check_fd(char *s, FD xml, FLAG i, char **r)
{
  while (s && NMATCH(OPEN_COMMENT, s += hempty(s)))
    s = move_to_end_comment(s, xml);
  *r = s;
  if (i == INIT && MATCH("<scene>", s + hempty(s)))
    return (TRUE);
  else if (i == INIT)
    return (FALSE);
  if ((s = (*r = get_next_line(xml))) == NULL)
    (void)lerror("no </scene> close");
  if (i == END && MATCH("</scene>", s + hempty(s)))
    return (FALSE);
  else if (i == END)
    return (TRUE);
  return (FALSE);
}

static void	scan_line(CLASS_DISPLAY *d, FD xml, char *s)
{
  size_t	i;

  i = 0;
  while (((d->scan)[i]).call)
    {
      if (NMATCH(((d->scan)[i]).div, s + hempty(s)))
	{
	  (((d->scan)[i]).call)(d, xml, s);
	  return ;
	}
      i++;
    }
  fprintf(stderr, "error :%s not recognized", s);
  exit(-1);
}

void	xml_scan(CLASS_DISPLAY *d, int ac, char **av)
{
  char	*s;
  BOOL  check;
  FD	xml;

  check = FALSE;
  display_init(d);
  if (ac != 2 || (xml = open(av[1], O_RDWR)) == -1)
    lerror(USAGE);
  if ((check = check_fd(get_next_line(xml), xml, INIT, &s)) == FALSE)
    lerror(USAGE);// || WRONG_FILE ?
  while ((check = check_fd(s, xml, END, &s)))
    scan_line(d, xml, s);
}
