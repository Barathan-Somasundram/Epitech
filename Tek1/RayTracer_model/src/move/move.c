/*
** move.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu Jun  6 23:28:12 2013 vincent colliot
** Last update Sun Jun  9 17:46:09 2013 vincent colliot
*/

#include <unistd.h>
#include <pthread.h>
#include <strings.h>
#include "screen.h"
#include "display.h"
#include "select.h"
#include "move.h"

static t_object	*get_object(t_3d pos, t_3d ray, t_object *current, double k)
{
  t_object	*yep;
  t_collide	collide;

  bzero(&collide, sizeof(collide));
  if (!current)
    return (NULL);
  (void)(current->collide)((void*)current, pos, ray, &collide);
  if (collide.defined == 0 || ((k != -1) &&
			       ((collide.k)[collide.up_to] > k)))
    return (get_object(pos, ray, current->next, k));
  k = (collide.k)[collide.up_to];
  if ((yep = get_object(pos, ray, current->next, k)) != NULL)
    return (yep);
  return (current);
}

int	get(int button, int x, int y, t_select *select)
{
  t_2d	pix;

  (void)button;
  pix.y = y;
  pix.x = x;
  select->oselect = get_object(select->d->eye->position,
			       convert_norm(ray_adapt(select->d->eye->focus,
						      pix)),
			      select->d->objects,
			      -1);
  if (select->oselect)
    {
      select->type = OSELECT;
      select->oselect->selected = TRUE;
    }
  else
    select->type = VSELECT;
  return (0);
}

static int	keypress2(int k, t_select *select)
{
  if (k == MSCALE)
    select->changed = (select->d->eye->scale += 1);
  if (k == LSCALE)
    select->changed = (select->d->eye->scale /= 2);
  select->key_m |= ((k == Kup)    ? (MKup)   :
		    (k == Kdown)  ? (MKdown) :
		    (k == Kleft)  ? (MKleft) :
		    (k == Kright) ? (MKright):
		    (k == Kback)  ? (MKback) :
		    (k == Kfront) ? (MKfront):
		    (0));
  select->key_r |= ((k == Rup)    ? (MRup)   :
		    (k == Rdown)  ? (MRdown) :
		    (k == Rleft)  ? (MRleft) :
		    (k == Rright) ? (MRright):
		    (k == Rback)  ? (MRback) :
		    (k == Rfront) ? (MRfront):
		    (0));
  if (k == KCOPY && select->type == OSELECT && select->oselect)
    select->oselect = (select->oselect->copy)(select->oselect);
  return (0);
}

int	keypress(int k, t_select *select)
{
  if (k == EXIT)
    pthread_exit(select);
  if (k == LIGHT)
    {
      select->type = LSELECT;
      select->lselect = select->d->lights;
    }
  if (k == VIEW)
    select->type = VSELECT;
  if (k == PLIGHT && select->type == LSELECT && select->lselect
      && select->lselect->next)
    select->lselect = select->lselect->next;
  if (k == NLIGHT && select->type == LSELECT && select->lselect
      && select->lselect->prev)
    select->lselect = select->lselect->prev;
  select->rgb |= ((k == Rless) ? (MRless):
		  (k == Rmore) ? (MRmore):
		  (k == Gless) ? (MGless):
		  (k == Gmore) ? (MGmore):
		  (k == Bless) ? (MBless):
		  (k == Bmore) ? (MBmore):
		  (0));
  return (keypress2(k, select));
}

int	keyrelease(int k, t_select *select)
{
  select->changed = FALSE;
  select->rgb &= ((k == Rless) ? (~MRless):
		  (k == Rmore) ? (~MRmore):
		  (k == Gless) ? (~MGless):
		  (k == Gmore) ? (~MGmore):
		  (k == Bless) ? (~MBless):
		  (k == Bmore) ? (~MBmore):
		  (0));
  select->key_m &= ((k == Kup)    ? (~MKup)   :
		    (k == Kdown)  ? (~MKdown) :
		    (k == Kleft)  ? (~MKleft) :
		    (k == Kright) ? (~MKright):
		    (k == Kback)  ? (~MKback) :
		    (k == Kfront) ? (~MKfront):
		    (0));
  select->key_r &= ((k == Rup)    ? (~MRup)   :
		    (k == Rdown)  ? (~MRdown) :
		    (k == Rleft)  ? (~MRleft) :
		    (k == Rright) ? (~MRright):
		    (k == Rback)  ? (~MRback) :
		    (k == Rfront) ? (~MRfront):
		    (0));
  if (k == FIXED)
    select->fixed = !select->fixed;
  return (0);
}

int	__stay_alert(t_select *select)
{
  usleep(5000);
  if (!(select->rgb || select->key_m || select->key_r))
    {
      if (select->d->eye->scale - 1 > MIN_MOD && !select->fixed)
	select->d->eye->scale -= 1;
      else if (select->d->eye->scale - 1 < MIN_MOD && select->d->eye->scale > MIN_MOD
	       && !select->fixed)
	select->d->eye->scale = MIN_MOD;
      else if (!select->changed)
	return (-1);
      preload_img(select->screen, select->d);
      return (nfn(select->screen));
    }
  select->d->eye->scale = MAX_MOD;
  if (select->rgb)
    rgb_move(select, select->rgb);
  if (select->key_m)
    rotation_move(select, select->key_m);
  if (select->key_r)
    translation_move(select, select->key_r);
  preload_img(select->screen, select->d);
  return (nfn(select->screen));
}

