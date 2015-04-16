/*
** convert.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:40:03 2013 vincent colliot
** Last update Tue Jun  4 14:42:04 2013 vincent colliot
*/

#include <strings.h>
#include "math.h"
#include "dim.h"

t_3d	convert_focus(t_3d c)
{
  t_3d	k;
  t_3d	focus;

  k.x = 0;
  k.y = 1;
  k.z = 0;
  focus.x = k.x * cos(c.y) * cos(c.z)
    + k.y * (cos(c.x) * (-sin(c.z)) + sin(c.x) * sin(c.y) * cos(c.z))
    + k.z * (sin(c.x) * sin(c.z) + cos(c.x) * sin(c.y) * cos(c.z));
  focus.y = k.x * (cos(c.y) * sin(c.z))
    + k.y * (cos(c.x) * cos(c.z) + sin(c.x) * sin(c.y) * sin(c.z))
    + k.z * (-sin(c.x) * cos(c.z) + cos(c.x) * sin(c.y) * sin(c.z));
  focus.z = k.x * (-sin(c.y))
    + k.y * (sin(c.x) * cos(c.y))
    + k.z * (cos(c.x)) * cos(c.y);
  return (focus);
}

t_3d	dist_convert(t_3d pos, t_3d vect, double n)
{
  t_3d	dist;

  dist.x = pos.x + vect.x * n;
  dist.y = pos.y + vect.y * n;
  dist.z = pos.z + vect.z * n;
  return (dist);
}

t_3d	convert_norm(t_3d v)
{
  double	n;
  t_3d		norm;

  bzero(&norm, sizeof(norm));
  n = sqrt(C(v.x) + C(v.y) + C(v.z));
  if (!n || n == 1)
    return (v);
  norm.x = v.x / n;
  norm.y = v.y / n;
  norm.z = v.z / n;
  return (norm);
}

t_3d	convert_ray(t_3d pf, t_3d pt)
{
  t_3d	r;

  r.x = pt.x - pf.x;
  r.y = pt.y - pf.y;
  r.z = pt.z - pf.z;
  r = convert_norm(r);
  return (r);
}

double	convert_scal(t_3d v1, t_3d v2)
{
  t_3d	r;

  r.x = v1.x * v2.x;
  r.y = v1.y * v2.y;
  r.z = v1.z * v2.z;
  return (sqrt(r.x + r.y + r.z));
}
