/*
** normal.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:10:41 2013 vincent colliot
** Last update Thu Jun  6 18:56:09 2013 vincent colliot
*/

#include "object.h"
#include "dim.h"

t_3d	normal_plan(void *plan, t_3d collide, t_collide *v)
{
  t_3d	narmol;

  (void)collide;
  v->n_spec = 1;
  narmol = ((t_plan*)plan)->focus;
  if (((t_object*)plan)->to_deform & dsX)
    narmol.x += (cos(collide.x * ((((t_object*)plan)->deform)[dX]).space)
		 * ((((t_object*)plan)->deform)[dX]).scale);
  if (((t_object*)plan)->to_deform & dsY)
    narmol.y += (cos(collide.y * ((((t_object*)plan)->deform)[dY]).space)
		 * ((((t_object*)plan)->deform)[dY]).scale);
  if (((t_object*)plan)->to_deform & dsZ)
    narmol.z += (cos(collide.z * ((((t_object*)plan)->deform)[dZ]).space)
		 * ((((t_object*)plan)->deform)[dZ]).scale);
  return (narmol);
}
