/*
** convert2.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 16:15:19 2013 vincent colliot
** Last update Mon Jun  3 22:26:16 2013 vincent colliot
*/

#include <strings.h>
#include "math.h"
#include "dim.h"

double	convert_cos(t_3d v1, t_3d v2)
{
  double	d;

  v1 = convert_norm(v1);
  v2 = convert_norm(v2);
  d = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) /
    (sqrt((C(v1.x) + C(v1.y) + C(v1.z)) *
	  (C(v2.x) + C(v2.y) + C(v2.z))));
  return (d);
}
