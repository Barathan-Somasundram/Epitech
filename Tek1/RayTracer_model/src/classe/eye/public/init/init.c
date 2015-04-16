/*
** init.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 02:33:31 2013 vincent colliot
** Last update Sun Jun  9 06:17:45 2013 vincent colliot
*/

#include "eye.h"
#include "string.h"
#include "xmalloc.h"
#include "display.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (5 + 1));
  (tab[0]).call = eye_pos;
  (tab[0]).name = "position";
  (tab[1]).call = eye_focus;
  (tab[1]).name = "direction";
  (tab[2]).call = eye_scale;
  (tab[2]).name = "scale";
  (tab[3]).call = eye_shading;
  (tab[3]).name = "shading";
  (tab[4]).call = eye_filter;
  (tab[4]).name = "filter";
  (tab[5]).call = NULL;
  (tab[5]).name = NULL;
  return (tab);
}

void	eye_init(void *eye, void *d)
{
  bzero(eye, sizeof(eye));
  ((CLASS_EYE*)eye)->scan = ini_scan();
  ((CLASS_DISPLAY*)d)->eye = eye;
  ((CLASS_EYE*)eye)->scale = 1;
  ((CLASS_EYE*)eye)->render.n = -1;
}
