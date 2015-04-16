/*
** call_init.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:36:06 2013 vincent colliot
** Last update Tue Jun  4 15:56:39 2013 vincent colliot
*/

#include "xmalloc.h"
#include "display.h"

static t_scan	*ini_scan(void)
{
  t_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (3 + 1));
  tab[0].call = add_lum;
  tab[0].div = "<light>";
  tab[1].call = add_eye;
  tab[1].div = "<eye>";
  tab[2].call = add_object;
  tab[2].div = "<object";
  tab[3].call = NULL;
  tab[3].div = NULL;
  return (tab);
}

static t_token_scan	*def_init(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (4 + 1));
  tab[0].call = sphere_init;
  tab[0].name = "sphere";
  tab[1].call = plan_init;
  tab[1].name = "plan";
  tab[2].call = cone_init;
  tab[2].name = "cone";
  tab[3].call = cylindre_init;
  tab[3].name = "cylindre";
  tab[4].call = NULL;
  tab[4].name = NULL;
  return (tab);
}

void	display_init(CLASS_DISPLAY *d)
{
  d->eye = NULL;
  d->lights = NULL;
  d->objects = NULL;
  d->scan = ini_scan();
  d->objects_def = def_init();
}
