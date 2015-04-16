/*
** clic.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri Jun  7 21:36:43 2013 vincent colliot
** Last update Fri Jun  7 22:34:12 2013 vincent colliot
*/

#include "flag.h"
#include "eye.h"

void	translation_view(CLASS_EYE *v, int forward, int left)
{
  v->position.x -= (double)forward * v->focus.x + left * v->focus.z;
  v->position.y -= (double)forward * v->focus.y + 0;
  v->position.z -= (double)forward * v->focus.z - left * v->focus.z;
}
