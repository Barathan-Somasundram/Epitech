/*
** limit.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  9 06:43:07 2013 vincent colliot
** Last update Sun Jun  9 07:38:05 2013 vincent colliot
*/

#include <strings.h>
#include "display.h"
#include "screen.h"
#include "dim.h"
#include "spot.h"
#include "get_color.h"
#include "bool.h"
#include "view.h"

static size_t	get_lim(t_collide *collide, t_limit limit, size_t i, BOOL *t)
{
  size_t	prev;

  prev = collide->up_to;
  if ((i / 2) == 0 && !(i % 2) && (collide->collide).x > limit.on)
    collide->up_to += 1;
  if ((i / 2) == 0 && (i % 2) && (collide->collide).x < limit.on)
    collide->up_to += 1;
  if ((i / 2) == 1 && !(i % 2) && (collide->collide).y > limit.on)
    collide->up_to += 1;
  if ((i / 2) == 1 && (i % 2) && (collide->collide).y < limit.on)
    collide->up_to += 1;
  if ((i / 2) == 2 && !(i % 2) && (collide->collide).z > limit.on)
    collide->up_to += 1;
  if ((i / 2) == 2 && (i % 2) && (collide->collide).z < limit.on)
    collide->up_to += 1;
  if (collide->up_to >= collide->defined)
    *t = FALSE;
  return (prev == collide->up_to);
}

BOOL	limitless(t_collide *collide, t_limit limit[6], t_3d pos, t_3d ray)
{
  BOOL		t;
  size_t	i;

  i = 0;
  t = TRUE;
  while (i < 6 && t == TRUE)
    {
      if (limit[i].valid == TRUE)
	i *= get_lim(collide, limit[i], i, &t);
      if (t)
	collide->collide = dist_convert(pos, ray, (collide->k)[collide->up_to]);
      i++;
    }
  return (t);
}

