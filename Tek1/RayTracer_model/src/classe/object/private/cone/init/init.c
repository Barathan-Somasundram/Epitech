/*
** init.c<6> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:30:13 2013 vincent colliot
** Last update Sun Jun  9 16:26:54 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "xmalloc.h"
#include "move.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (9 + 1));
  (tab[0]).call = cone_pos;
  (tab[0]).name = POSITION;
  (tab[1]).call = cone_focus;
  (tab[1]).name = FOCUS;//<--- serait bien de faire des defines;;;;plus tard
  (tab[2]).call = cone_color;
  (tab[2]).name = COLOR;
  (tab[3]).call = cone_angle;
  (tab[3]).name = "angle";
  (tab[4]).name = SHINING;
  (tab[4]).call = object_shining;
  (tab[5]).call = object_alpha;
  (tab[5]).name = ALPHA;
  (tab[6]).call = object_gamma;
  (tab[6]).name = GAMMA;
  (tab[7]).call = object_deform;
  (tab[7]).name = "wave";
  (tab[8]).call = object_limit;
  (tab[8]).name = "limit";
  (tab[9]).call = NULL;
  (tab[9]).name = NULL;
  return (tab);
}

void	cone_init(void *o, t_token *token)
{
  t_cone	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  bzero(s, sizeof(*s));
  s->scan = ini_scan();
  s->collide = collide_cone;
  s->normal = normal_cone;
  s->translation = translation_cone;
  s->rotation = rotation_cone;
  s->copy = copy_cone;
  *((t_cone**)o) = s;
}
