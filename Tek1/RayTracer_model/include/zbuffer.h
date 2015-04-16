/*
** zbuffer.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 15:55:51 2013 vincent colliot
** Last update Wed Jun  5 03:22:12 2013 vincent colliot
*/

#ifndef ZBUFFER_H_
# define ZBUFFER_H_

t_color	zbuffering(CLASS_DISPLAY *, CLASS_OBJECT *, t_3d[2], double);
t_color	spot_add(t_collide, t_color, double, CLASS_OBJECT *);

#endif
