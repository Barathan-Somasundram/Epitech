/*
** init.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 03:06:12 2013 vincent colliot
** Last update Mon Jun  3 22:48:20 2013 vincent colliot
*/

#include "display.h"
#include "strings.h"
#include "lerror.h"
#include "get_color.h"

static void	*def_them(t_token_scan *scan, char *type, t_token *token)
{
  size_t	i;
  CLASS_OBJECT *o;

  i = 0;
  while ((scan[i]).name)
    if (MATCH((scan[i]).name, type))
      {
	((scan[i++]).call)(&o, token);
	if (xml_token(&token, NULL, END, 0))
	  lerror("error in object def\n");
	return (o);
      }
    else
      i++;
  lerror("error in object def\n");
  return (o);
}

void	objects_init(CLASS_OBJECT **object, void *d, char *s, FD xml)
{
  t_token	*token;

  if (!xml_token(&token, s, INIT | A_END, xml))
    lerror("error in object def\n");
  *object = def_them(((CLASS_DISPLAY*)d)->objects_def,
		     xml_token(&token, "type", RESOLVE, 0),
		     token);
  (*object)->next = ((CLASS_DISPLAY*)d)->objects;
  (*object)->get_color = get_color;
  (*object)->alpha = 0;
  (*object)->gamma = 0;
  ((CLASS_DISPLAY*)d)->objects = *object;
}
