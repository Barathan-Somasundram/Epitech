/*
** normal.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:23:44 2013 vincent colliot
** Last update Thu Jun  6 22:07:38 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "dim.h"

# define NORMAL(n) ((n > 0) ? (n) : (-n))

t_3d	normal_cylindre(void *cylindre, t_3d collide, t_collide *v)
{
  t_3d	normal;
  t_3d	narmol;

  bzero(&narmol, sizeof(normal));
  bzero(&normal, sizeof(normal));
  (void)v;
  narmol.x -= collide.x - ((t_cylindre*)cylindre)->position.x;
  narmol.y -= collide.y - ((t_cylindre*)cylindre)->position.y;
  narmol.z -= collide.z - ((t_cylindre*)cylindre)->position.z;
  narmol = convert_norm(narmol);
  normal.x = narmol.x * (1 - ((t_cylindre*)cylindre)->focus.x);
  normal.y = narmol.y * (1 - ((t_cylindre*)cylindre)->focus.y);
  normal.z = narmol.z * (1 - ((t_cylindre*)cylindre)->focus.z);
  if (((t_object*)cylindre)->to_deform & dsX)
    normal.x += (cos(collide.x * ((((t_object*)cylindre)->deform)[dX]).space)
		 * ((((t_object*)cylindre)->deform)[dX]).scale);
  if (((t_object*)cylindre)->to_deform & dsY)
    normal.y += (cos(collide.y * ((((t_object*)cylindre)->deform)[dY]).space)
		 * ((((t_object*)cylindre)->deform)[dY]).scale);
  if (((t_object*)cylindre)->to_deform & dsZ)
    normal.z += (cos(collide.z * ((((t_object*)cylindre)->deform)[dZ]).space)
		 * ((((t_object*)cylindre)->deform)[dZ]).scale);
  return (normal);
}
