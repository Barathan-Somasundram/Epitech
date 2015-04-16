/*
** color.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 13:28:19 2013 vincent colliot
** Last update Sun Jun  9 20:33:58 2013 vincent colliot
*/

#define IN_
#include <strings.h>
#include "collide.h"
#include "display.h"
#include "get_color.h"
#include "zbuffer.h"
#include "view.h"

static t_3d	alpha_ray(t_collide collide, t_3d ray)
{
  t_3d		r_alpha;
  double	scal;

  ray = convert_norm(ray);
  scal = convert_scal(collide.normal = convert_norm(collide.normal), ray);
  if (collide.n_spec && convert_cos(collide.normal, ray) < 0)
    scal = -scal;
  r_alpha.x = -2 * scal * (collide.normal).x + ray.x;
  r_alpha.y = -2 * scal * (collide.normal).y + ray.y;
  r_alpha.z = -2 * scal * (collide.normal).z + ray.z;
  return (r_alpha);
}

static t_3d	gamma_ray(t_collide collide, t_3d ray, t_object *o)
{
  t_3d		r_alpha;
  double	scal;
  double	n;

  bzero(&r_alpha, sizeof(r_alpha));
  ray = convert_norm(ray);
  scal = convert_scal(collide.normal = convert_norm(collide.normal), ray);
  n = o->diffract;

  r_alpha.x = n * ray.x + (n * scal - sqrt(1 + C(n) * (C(scal) - 1)))
    * (collide.normal).x;
  r_alpha.y = n * ray.y + (n * scal - sqrt(1 + C(n) * (C(scal) - 1)))
    * (collide.normal).y;
  r_alpha.z = n * ray.z + (n * scal - sqrt(1 + C(n) * (C(scal) - 1)))
    * (collide.normal).z;
  return (r_alpha);
}

static t_color	direct_light(t_3d reflect, CLASS_LIGHT *light, t_color color,
			     t_collide collide)
{
  t_color	add;
  double	cosy;

  if (!light || !collide.shining)
    return (color);
  cosy = convert_cos(reflect,
		     convert_norm(convert_ray(collide.collide, light->position)));
  cosy *= cosy * cosy;
  if (cosy < 0)
    return (direct_light(reflect, light->next, color, collide));
  add = spot_add(collide, light->color, 0.1,
		 ((CLASS_DISPLAY*)collide.ld)->objects);
  if (((color.rgb)[R] + (add.rgb)[R] * cosy * collide.shining) <= 255)
    (color.rgb)[R] += (add.rgb)[R] * cosy * collide.shining;
  else
    (color.rgb)[R] = 255;
  if (((color.rgb)[G] + (add.rgb)[G] * cosy * collide.shining) <= 255)
    (color.rgb)[G] += (add.rgb)[G] * cosy * collide.shining;
  else
    (color.rgb)[G] = 255;
  if (((color.rgb)[B] + (add.rgb)[B] * cosy * collide.shining) <= 255)
    (color.rgb)[B] += (add.rgb)[B] * cosy * collide.shining;
  else
    (color.rgb)[B] = 255;
  return (direct_light(reflect, light->next, color, collide));
}

t_color	mod_color(CLASS_DISPLAY *d, void *object, t_collide collide, t_3d view[2])
{
  t_3d		ray;
  t_3d		posit;
  t_color	color;
  t_color	calpha;
  t_color	cgamma;

  bzero(&calpha, sizeof(calpha));
  bzero(&cgamma, sizeof(cgamma));
  color = collide.color;
  ray = view[V_RAY];
  posit = view[V_POSIT];
  view[V_POSIT] = collide.collide;
  view[V_RAY] = alpha_ray(collide, ray);
  if (collide.alpha > 0)
    calpha = zbuffering(d, d->objects, view, collide.alpha);
  view[V_RAY] = gamma_ray(collide, ray, object);
  view[V_POSIT] = dist_convert(posit, ray, (collide.k)[collide.defined - 1] * 1.0001);
  if (collide.gamma > 0)
    cgamma = zbuffering(d, d->objects, view, collide.gamma);
  if (collide.alpha > 0)
    add_color(color, calpha, collide.alpha, &color);
  if (collide.gamma > 0)
    add_color(color, cgamma, collide.gamma, &color);
  view[V_RAY] = ray;
  view[V_POSIT] = posit;
  return (direct_light(alpha_ray(collide, ray), d->lights,
		       color, collide));
}

t_color	get_color(CLASS_DISPLAY *d, void *object, t_collide collide, t_3d view[2])
{
  t_color	color;

  (void)d;
  (void)view;
  (void)collide;
  color = ((CLASS_OBJECT*)object)->color;
  return (color);
}


t_color	add_color(t_color c1, t_color c2, double value, t_color *r)
{
  if (value <= 0)
    {
      bzero(r, sizeof(r));
      return (*r);
    }
  value -= (int)value;
  (r->rgb)[R] = (double)((c1.rgb)[R] * (1 - value)) + ((double)(c2.rgb)[R] * value);
  (r->rgb)[G] = (double)((c1.rgb)[G] * (1 - value)) + ((double)(c2.rgb)[G] * value);
  (r->rgb)[B] = (double)((c1.rgb)[B] * (1 - value)) + ((double)(c2.rgb)[B] * value);
  return (*r);
}
