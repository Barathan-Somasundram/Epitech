/*
** spot.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 14:30:25 2013 vincent colliot
<<<<<<< HEAD
** Last update Sun Jun  9 19:53:43 2013 vincent colliot
=======
** Last update Tue Jun  4 14:05:18 2013 pierre-louis rebours
>>>>>>> 786e49a2cc6941b4bc6ef4031ec3a1fd25a2152e
*/

/*
 * ¤¤¤¤¤¤¤¤¤
 * shuriken!
 * ¤¤¤¤¤¤¤¤¤
**/

#include <strings.h>
#include "display.h"
#include "zbuffer.h"
#include "spot.h"

static double	add_dist(t_collide collide)
{
  t_3d	n;

  return (1);
  n.x = collide.collide.x - collide.light.x;
  n.y = collide.collide.y - collide.light.y;
  n.z = collide.collide.z - collide.light.z;
  return (sqrt(C(n.x) + C(n.y) + C(n.z)));
}

static t_color	spot_modify(t_collide collide, t_color final, double angle)
{
  t_color	r;

  bzero(&r, sizeof(r));
  if (angle <= 0 && collide.n_spec)
    angle = -angle;
  else if (!collide.n_spec && angle <= 0)
    return (r);
  (r.rgb)[R] = N_C(angle * (final.rgb)[R] * (((collide.color).rgb)[R] / 255.0
					     + 0))
    / add_dist(collide);
  (r.rgb)[G] = N_C(angle * (final.rgb)[G] * (((collide.color).rgb)[G] / 255.0
					     + 0))
    / add_dist(collide);
  (r.rgb)[B] = N_C(angle * (final.rgb)[B] * (((collide.color).rgb)[B] / 255.0
					     + 0))
    / add_dist(collide);
  return (r);
}

static void	add_all_color(t_color c1, int c2[3], int r[3])
{
  (r)[R] = (c1.rgb)[R] + (c2)[R];
  (r)[G] = (c1.rgb)[G] + (c2)[G];
  (r)[B] = (c1.rgb)[B] + (c2)[B];
}

static inline t_color	div_all_color(int c[3], size_t i)
{
  t_color r;

  bzero(&r, sizeof(r));
  if (!i)
    return (r);
  (c)[R] /= i;
  (c)[G] /= i;
  (c)[B] /= i;
  (r.rgb)[R] = c[R];
  (r.rgb)[G] = c[G];
  (r.rgb)[B] = c[B];
  return (r);
}

static BOOL shadow_rendering(t_collide *collide, CLASS_LIGHT *light, int n)
{
  t_3d	alt_light;

  alt_light = light->position;
  collide->light = light->position;
  if (collide->shading.n == -1 && n == 0)
    return (TRUE);
  if (n >= collide->shading.n)
    return (FALSE);
  alt_light.x += ((random() % 100) * collide->shading.scale) / 100
    - collide->shading.scale;
  alt_light.y += ((random() % 100) * collide->shading.scale) / 100
    - collide->shading.scale;
  alt_light.z += ((random() % 100) * collide->shading.scale) / 100
    - collide->shading.scale;
  collide->light = alt_light;
  return (TRUE);
}

t_color	add_spot_color(t_collide collide, CLASS_LIGHT *light,
		       CLASS_OBJECT *object, double reverb)
{
  size_t	i;
  int		n;
  int		final[3];
  t_color	cont;
  double	cosy;

  bzero(&final, sizeof(final));
  i = 0;
  while (light)
    {
      n = 0;
      cosy = convert_cos(convert_ray(light->position, collide.collide),
			 collide.normal);
      while (shadow_rendering(&collide, light, n))
	{
	  collide.r_light = convert_ray(collide.light, collide.collide);
	  collide.ct_init = reverb;
	  cont = spot_add(collide, light->color, reverb, object);
	  cont = spot_modify(collide, cont, cosy);
	  (void)add_all_color(cont, final, final);
	  n++;
	}
      light = light->next;
      i++;
    }
  return (div_all_color(final, i * n));
}
