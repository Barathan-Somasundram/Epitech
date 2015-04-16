/*
** init.c<7> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:33:06 2013 vincent colliot
** Last update Sun Jun  9 16:25:57 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "xmalloc.h"
#include "move.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (8 + 1));
  (tab[0]).call = sphere_pos;
  (tab[0]).name = POSITION;
  (tab[1]).call = sphere_color;
  (tab[1]).name = COLOR;
  (tab[2]).call = sphere_rayon;
  (tab[2]).name = "rayon";//<--- serait bien de faire des defines;;;;plus tard
  (tab[3]).name = SHINING;
  (tab[3]).call = object_shining;
  (tab[4]).call = object_alpha;
  (tab[4]).name = ALPHA;
  (tab[5]).call = object_gamma;
  (tab[5]).name = GAMMA;
  (tab[6]).call = object_deform;
  (tab[6]).name = "wave";
  (tab[7]).call = object_limit;
  (tab[7]).name = "limit";
  (tab[8]).call = NULL;
  (tab[8]).name = NULL;
  return (tab);
}

void	sphere_init(void *o, t_token *token)
{
  t_sphere	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  bzero(s, sizeof(*s));
  s->scan = ini_scan();
  s->collide = collide_sphere;
  s->normal = normal_sphere;
  s->translation = translation_sphere;
  s->rotation = rotation_sphere;
  s->copy = copy_sphere;
  *((t_sphere**)o) = s;
}
