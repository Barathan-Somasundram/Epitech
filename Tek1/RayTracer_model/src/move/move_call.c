/*
** move_call.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri Jun  7 00:53:32 2013 vincent colliot
** Last update Sun Jun  9 06:19:23 2013 vincent colliot
*/

#include "screen.h"
#include "object.h"
#include "select.h"
#include "move.h"

void	rgb_move(t_select *select, FLAG rgb)
{
  t_color	*color;

  color = NULL;
  if (select->type == VSELECT || (select->type == OSELECT && !select->oselect) ||
      (select->type == LSELECT && !select->lselect))
    return ;
  if (select->type == OSELECT)
    color = &(select->oselect->color);
  if (select->type == LSELECT)
    color = &(select->lselect->color);
  if (!color)
    return ;
  if (rgb & (MRmore | MRless))
    (color->rgb)[R] += CMOVE * ((rgb & MRmore) != 0) - ((rgb & MRless) != 0);
  if (rgb & (MGmore | MGless))
    (color->rgb)[G] += CMOVE * ((rgb & MGmore) != 0) - ((rgb & MGless) != 0);
  if (rgb & (MBmore | MBless))
    (color->rgb)[B] += CMOVE * ((rgb & MBmore) != 0) - ((rgb & MBless) != 0);
}

void	translation_move(t_select *select, FLAG move)
{
  t_3d		*position;

  position = NULL;
  if ((select->type == OSELECT && !select->oselect) ||
      (select->type == LSELECT && !select->lselect))
    return ;
  if (select->type == VSELECT)
    position = &(select->d->eye->position);
  if (select->type == OSELECT)
    (select->oselect->translation(select->oselect, move));
  if (select->type == LSELECT && select->lselect)
    position = &(select->lselect->position);
  if (!position)
    return ;
  if (move & (MKup | MKdown))
    position->y += TMOVE * (((move & MKup) != 0) - ((move & MKdown) != 0));
  if (move & (MKleft | MKright))
    position->x += TMOVE * (((move & MKright) != 0) - ((move & MKleft) != 0));
  if (move & (MKfront | MKback))
    position->z += TMOVE * (((move & MBmore) != 0) - ((move & MBless) != 0));
}

void	rotation_move(t_select *select, FLAG move)
{
  t_3d		*focus;

  focus = NULL;
  if ((select->type == OSELECT && !select->oselect) ||
      (select->type == LSELECT && !select->lselect))
    return ;
  if (select->type == VSELECT)
    focus = &(select->d->eye->focus);
  if (select->type == OSELECT)
    (select->oselect->rotation(select->oselect, move));
  if (select->type == LSELECT)
    return ;
  if (!focus)
    return ;
  if (move & (MRup | MRdown))
    focus->y += RMOVE * (((move & MRup) != 0) - ((move & MRdown) != 0));
  if (move & (MRleft | MRright))
    focus->x += RMOVE * (((move & MRright) != 0) - ((move & MRleft) != 0));
  if (move & (MRfront | MRback))
    focus->z += RMOVE * (((move & MBmore) != 0) - ((move & MBless) != 0));
}
