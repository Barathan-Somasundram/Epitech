/*
** zbuff.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 00:47:07 2013 vincent colliot
** Last update Sun Jun  9 15:41:39 2013 vincent colliot
*/

#include <strings.h>
#include "display.h"
#include "screen.h"
#include "dim.h"
#include "spot.h"
#include "get_color.h"
#include "bool.h"
#include "view.h"

static BOOL	fill_collide(CLASS_OBJECT *object, t_3d ray, t_3d pos,
			     t_collide *collide)
{
  size_t	prev;
  t_collide	fill;

  bzero(&fill, sizeof(fill));
  if (!object->collide)
    return (FALSE);
  fill.collide = (object->collide)((void*)object, pos, ray, &fill);
  if (fill.defined == 0)
    return (FALSE);
  prev = fill.up_to;
  if (limitless(&fill, object->limit, pos, ray) == FALSE ||
      (prev != fill.up_to && collide->up_to == 5))
    return (FALSE);
  if (collide->defined == MAX_DEGREE_LVL + 1 ||
      (fill.k)[fill.up_to] < (collide->k)[collide->up_to])
    memcpy(collide, &fill, sizeof(*collide));
  else
    return (FALSE);
  collide->shining = object->shine;
  if (!object->normal)
    return (TRUE);
  else
    collide->normal =
      convert_norm((object->normal)((void*)object, collide->collide, collide));
  return (TRUE);
}

t_color	zbuffering(CLASS_DISPLAY *d, CLASS_OBJECT *object, t_3d view[2], double reverb)
{
  t_collide	collide;

  bzero(&collide, sizeof(collide));
  collide.defined = MAX_DEGREE_LVL + 1;
  while (object)
    {
      if (fill_collide(object, view[V_RAY], view[V_POSIT], &collide))
	{
	  collide.shading = d->eye->render;
	  collide.alpha = reverb - (1 - object->alpha) - 0.05;
	  collide.gamma = reverb - (1 - object->gamma) - 0.05;
	  collide.ld = d;
	  collide.color = get_color(d, object, collide, view);
	  collide.color = add_spot_color(collide, d->lights, d->objects, reverb);
	  collide.color = mod_color(d, object, collide, view);
	}
      object = object->next;
    }
  return (collide.color);
}

static BOOL	verif(t_collide new, t_collide collide, size_t i)
{
  t_3d	n;

 n.x = collide.collide.x - collide.light.x;
  n.y = collide.collide.y - collide.light.y;
  n.z = collide.collide.z - collide.light.z;
  if ((new.k)[new.up_to + i] < sqrt(C(n.x) + C(n.y) + C(n.z)) - 0.1)
    return (TRUE);
  return (FALSE);
}

t_color	spot_add(t_collide collide, t_color color, double ct,
		 CLASS_OBJECT *object)
{
  t_3d		view[2];
  size_t	i;
  t_collide     new;
  t_color	new_color;

  bzero(&new_color, sizeof(new_color));
  new.defined  = MAX_DEGREE_LVL + 1 + (i = 0);
  if ((!object || !color.i || ct <= 0) && collide.ct_init != 1)
    return (add_color(color, new_color, 1 - ct, &color));
  else if (!object || !color.i || ct <= 0)
    return (add_color(color, new_color, ct, &color));
  new.up_to = 5;
  if (!fill_collide(object, collide.r_light, collide.light, &new))
    return (spot_add(collide, color, ct, object->next));
  while (new.up_to + i < new.defined && ct > 0 && verif(new, collide, i))
    {
      new.alpha = ct - (1 - object->alpha) - 0.05;
      new.gamma = ct - (1 - object->gamma) - 0.05;
      new.collide = dist_convert(collide.light, collide.r_light,
		       (new.k)[new.up_to + (i++)]);
      view[V_RAY] = collide.r_light;
      color = add_color(color, object->get_color(collide.ld,
						 (void*)object, new, view),
			ct -= 1 - object->gamma, &color);
    }
  return (spot_add(collide, color, ct, object->next));
}
