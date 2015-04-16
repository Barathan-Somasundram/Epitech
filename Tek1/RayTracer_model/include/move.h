/*
** move.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri Jun  7 17:29:21 2013 vincent colliot
** Last update Fri Jun  7 22:16:18 2013 vincent colliot
*/

#ifndef MOVE_H_
# define MOVE_H_

#include "flag.h"

#ifdef SELECT_H_
/* call */
void	rgb_move(t_select *, FLAG);
void	translation_move(t_select *, FLAG);
void	rotation_move(t_select *, FLAG);
#endif
/* methodes */
void	translation_cone(void *, FLAG);
void	rotation_cone(void *, FLAG);
void	translation_sphere(void *, FLAG);
void	rotation_sphere(void *, FLAG);
void	translation_cylindre(void *, FLAG);
void	rotation_cylindre(void *, FLAG);
void	translation_plan(void *, FLAG);
void	rotation_plan(void *, FLAG);
void	translation_view(void*, int, int);

#endif
