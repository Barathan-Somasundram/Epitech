/*
** collide.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Jun  1 23:42:58 2013 vincent colliot
** Last update Mon Jun  3 01:48:25 2013 vincent colliot
*/

#include "object.h"
#include "dim.h"

t_3d    collide_plan(void *plan, t_3d pos, t_3d ray, t_collide *k)
{
  t_3d		p;
  float		q;
  double	d;

  p = (((t_plan*)plan)->focus);
  d = (((t_plan*)plan)->d);
  q = -(p.x * pos.x + p.y * pos.y + p.z * pos.z + d) /
    (p.x * ray.x + p.y * ray.y + p.z * ray.z);
  k->defined  = 0;
  if (q < K_COL)
    return (dist_convert(pos, ray, q));
  k->defined = 1;
  k->k[0] = q;
  return (dist_convert(pos, ray, q));
}
