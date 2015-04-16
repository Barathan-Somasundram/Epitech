/*
** collide.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 02:47:48 2013 vincent colliot
** Last update Mon Jun  3 20:08:40 2013 vincent colliot
*/

#include "object.h"

t_3d	collide_sphere(void *sphere, t_3d pos, t_3d r, t_collide *k)
{
  t_3d	p;
  t_3e	D;
  double rayon;

  rayon = ((t_sphere*)sphere)->rayon;
  p = ((t_sphere*)sphere)->position;
  D.a = C(r.x) + C(r.y) + C(r.z);
  D.b = 2 * (r.x * (pos.x - p.x) + r.y * (pos.y - p.y) + r.z * (pos.z - p.z));
  D.c = C(pos.x - p.x) + C(pos.y - p.y) + C(pos.z - p.z) - C(rayon);
  if ((k->defined = 2 * (C(D.b) - 4 * D.a * D.c > 0)))
    {
      (k->k)[0] = (-D.b + sqrtf(C(D.b) - 4 * D.a * D.c)) / (2 * D.a);
      (k->k)[1] = (-D.b - sqrtf(C(D.b) - 4 * D.a * D.c)) / (2 * D.a);
      return (collide_arrange(k, pos, r));
    }
  else if ((k->defined = 1 * (C(D.b) - 4 * D.a * D.c == 0)))
    return (dist_convert(pos, r, (k->k)[0] = (-D.b) / (2 * D.a)));
  return (pos);//pos
}
