/*
** load.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:40:44 2013 vincent colliot
** Last update Sun Jun  9 21:03:45 2013 vincent colliot
*/

#include <strings.h>
#include <stdio.h>
#include "screen.h"
#include "zbuffer.h"
#include "thread.h"

t_3d	ray_adapt(t_3d f, t_2d pix)
{
  t_3d ray;
  t_2d i;

  i.x = ((pix.x - (SCREEN_SIZE_X / 2.0))) / 100.0;
  i.y = -((pix.y - (SCREEN_SIZE_Y / 2.0))) / 100.0;
  ray.x = i.x * cosf(f.y) * cosf(f.z)
    + i.y * (cosf(f.x) * (-sinf(f.z)) + sinf(f.x) * sinf(f.y) * cosf(f.z))
    + FOV * (sinf(f.x) * sinf(f.z) + cosf(f.x) * sinf(f.y) * cosf(f.z));
  ray.y = i.x * (cosf(f.y) * sinf(f.z))
    + i.y * (cosf(f.x) * cosf(f.z) + sinf(f.x) * sinf(f.y) * sinf(f.z))
    + FOV * (-sinf(f.x) * cosf(f.z) + cosf(f.x) * sinf(f.y) * sinf(f.z));
  ray.z = i.x * (-sin(f.y))
    + i.y * (sinf(f.x) * cosf(f.y))
    + FOV * (cosf(f.x)) * cosf(f.y);
  return (ray);
}

static void	success_pix_it(CLASS_EYE *eye, t_screen *screen,
			       t_2d pix, t_color color)
{
  t_2d	i;
  t_2d	p;

  bzero(&i, sizeof(i));
  while (i.y < eye->scale && i.y + pix.y < SCREEN_SIZE_Y)
    {
      i.x = 0;
      while (i.x < eye->scale && i.x + pix.x < SCREEN_SIZE_X)
	{
	  p.x = i.x + pix.x;
	  p.y = i.y + pix.y;
	  pix_it(screen, p, color, eye->filter);
	  i.x += 1;
	}
      i.y += 1;
    }
}

void	*load_img_then(void *tld)
{
  t_screen *screen;
  CLASS_DISPLAY *d;
  t_color	color;
  t_3d		view[2];
  t_2d		pix;

  pix.y = (TLD_CAST(tld))->begin;
  screen = (TLD_CAST(tld))->screen;
  d = (TLD_CAST(tld))->d;
  while (pix.y < TLD_CAST(tld)->end)
    {
      pix.x = 0;
      while (pix.x < SCREEN_SIZE_X)
	{
	  view[0] = convert_norm(ray_adapt(d->eye->focus, pix));
	  view[1] = d->eye->position;
	  color = zbuffering(d, d->objects, view, 1);
	  success_pix_it(d->eye, screen, pix, color);
	  pix.x += d->eye->scale;
	}
      pix.y += d->eye->scale;
    }
  return (tld);
}

void	load_img(t_screen *screen, CLASS_DISPLAY *d)
{
  size_t	i;
  pthread_t	thread[NTHREAD];
  t_load_thread	load_thread[NTHREAD];

  i = 0;
  (load_thread[i]).screen = screen;
  (load_thread[i]).d = d;
  (load_thread[i]).begin = 0;
  (load_thread[i]).end = SCREEN_SIZE_Y;
  if (NTHREAD == 1)
    load_img_then(&(load_thread[i]));
  if (NTHREAD == 1)
    return ;
  while (i < NTHREAD)
    {
      (load_thread[i]).screen = screen;
      (load_thread[i]).d = d;
      (load_thread[i]).begin = i * (SCREEN_SIZE_Y / NTHREAD);
      (load_thread[i]).end = (i + 1) * (SCREEN_SIZE_Y / NTHREAD);
      pthread_create(&(thread[i]), NULL, load_img_then, &(load_thread[i]));
      i++;
    }
  i = 0;
  while (i < NTHREAD)
    pthread_join(thread[i++], NULL);
}

void	preload_img(t_screen *screen, CLASS_DISPLAY *d)
{
  bzero(((t_image*)(screen->screensave))->stack, sizeof(char)
	* (SCREEN_SIZE_X * (((t_image*)(screen->screensave))->bpp / 8)
	   + SCREEN_SIZE_Y * (((t_image*)(screen->screensave))->size_line)));
  load_img(screen ,d);

}
