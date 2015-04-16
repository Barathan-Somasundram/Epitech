
/*
** collide.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Jun  1 23:42:08 2013 vincent colliot
** Last update Wed Jun  5 22:47:50 2013 vincent colliot
*/

#include "object.h"

static void	init(t_3d *pos, t_3d *focus, double *angle, t_cone *cone)
{
  *pos = cone->position;
  *focus = cone->focus;
  *angle = cone->angle;
}

t_3d	collide_cone(void *cone, t_3d pos, t_3d r, t_collide *k)
{
  t_3d	 p;
  t_3d	 f;
  double angle;
  t_3e   D;

  init(&p, &f, &angle, (t_cone*)cone);
  D.a = C(r.x) + C(r.y) + C(r.z) - C(f.x * r.x + f.y * r.y + f.z * r.z)
    - C(f.x * r.x + f.y * r.y + f.z * r.z) * C(tan(angle));
  D.b = 2 * (r.x * (pos.x - p.x) + r.y * (pos.y - p.y) + r.z * (pos.z - p.z))
    - 2 * (r.x * f.x + r.y * f.y + r.z * f.z)
    * (f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z))
    - 2 * (r.x * f.x + r.y * f.y + r.z * f.z) * C(tan(angle))
    * (f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z));
  D.c = C(pos.x - p.x) + C(pos.y - p.y) + C(pos.z - p.z)
    - C(f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z))
    - C(tan(angle)) *
    C(f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z));
  if ((k->defined = 2 * (C(D.b) - 4 * D.a * D.c > 0)))
    {
      (k->k)[0] = (-D.b + sqrtf(C(D.b) - 4 * D.a * D.c)) / (2 * D.a);
      (k->k)[1] = (-D.b - sqrtf(C(D.b) - 4 * D.a * D.c)) / (2 * D.a);
      return (collide_arrange(k, pos, r));
    }
  else if ((k->defined = 1 * (C(D.b) - 4 * D.a * D.c == 0)))
    return (dist_convert(pos, r, (k->k)[0] = (-D.b) / (2 * D.a)));
  return (pos);
}
