/*
** clic.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri Jun  7 05:59:49 2013 vincent colliot
** Last update Sun Jun  9 16:31:15 2013 vincent colliot
*/

# include <strings.h>
# include "screen.h"
# include "display.h"
# include "select.h"
# include "xmalloc.h"

void	translation_sphere(void *sphere, FLAG move)
{
  t_3d	*position;

  position = &(((t_sphere*)sphere)->position);
  if (move & (MKup | MKdown))
    position->y += TMOVE * (((move & MKup) != 0) - ((move & MKdown) != 0));
  if (move & (MKleft | MKright))
    position->x += TMOVE * (((move & MKright) != 0) - ((move & MKleft) != 0));
  if (move & (MKfront | MKback))
    position->z += TMOVE * (((move & MBmore) != 0) - ((move & MBless) != 0));
}

void	rotation_sphere(void *sphere, FLAG move)
{
  (void)sphere;
  (void)move;
  return ;
}

void	*copy_sphere(void *sphere)
{
  t_sphere	*copy;

  copy = xmalloc(sizeof(*copy));
  memcpy(copy, sphere, sizeof(*copy));
  ((t_sphere*)sphere)->next = copy;
  return (copy);
}
