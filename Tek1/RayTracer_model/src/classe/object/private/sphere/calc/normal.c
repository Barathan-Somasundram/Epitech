/*
** normal.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:21:18 2013 vincent colliot
** Last update Thu Jun  6 18:56:01 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "dim.h"

t_3d	normal_sphere(void *sphere, t_3d collide, t_collide *k)
{
  t_3d	narmol;

  bzero(&narmol, sizeof(narmol));
  (void)k;
  narmol.x -= collide.x - ((t_sphere*)sphere)->position.x;
  narmol.y -= collide.y - ((t_sphere*)sphere)->position.y;
  narmol.z -= collide.z - ((t_sphere*)sphere)->position.z;
  if (((t_object*)sphere)->to_deform & dsX)
    narmol.x += (cos(collide.x * ((((t_object*)sphere)->deform)[dX]).space)
    		 * ((((t_object*)sphere)->deform)[dX]).scale);
  if (((t_object*)sphere)->to_deform & dsY)
    narmol.y += (cos(collide.y * ((((t_object*)sphere)->deform)[dY]).space)
    		 * ((((t_object*)sphere)->deform)[dY]).scale);
  if (((t_object*)sphere)->to_deform & dsZ)
    narmol.z += (cos(collide.z * ((((t_object*)sphere)->deform)[dZ]).space)
    		 * ((((t_object*)sphere)->deform)[dZ]).scale);
  return (narmol);
}
