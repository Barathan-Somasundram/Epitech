/*
** init.c<5> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:27:54 2013 vincent colliot
** Last update Sun Jun  9 16:27:11 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "xmalloc.h"
#include "move.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (9 + 1));
  (tab[0]).call = cylindre_pos;
  (tab[0]).name = POSITION;
  (tab[1]).call = cylindre_color;
  (tab[1]).name = COLOR;
  (tab[2]).call = cylindre_focus;
  (tab[2]).name = FOCUS;//<--- serait bien de faire des defines;;;;plus tard
  (tab[3]).call = cylindre_rayon;
  (tab[3]).name = "rayon";
  (tab[4]).name = SHINING;
  (tab[4]).call = object_shining;
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

void	cylindre_init(void *o, t_token *token)
{
  t_cylindre	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  bzero(s, sizeof(t_cylindre));
  s->scan = ini_scan();
  s->collide = collide_cylindre;
  s->normal = normal_cylindre;
  s->focus = convert_focus(s->focus);
  s->translation = translation_cylindre;
  s->rotation = rotation_cylindre;
  s->copy = copy_cylindre;
  *((t_cylindre**)o) = s;
}
