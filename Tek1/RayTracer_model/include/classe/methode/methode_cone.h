/*
** methode_cone.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:09:00 2013 vincent colliot
** Last update Sun Jun  9 16:24:38 2013 vincent colliot
*/

#ifndef M_CONE_H_
# define M_CONE_H_

	/* scan */
void	cone_pos(void*,t_token*);
void	cone_color(void*,t_token*);
void	cone_angle(void*,t_token*);
void	cone_focus(void*,t_token*);

	/* collide */
t_3d	collide_cone(void *, t_3d, t_3d, t_collide *);
t_3d	normal_cone(void *, t_3d, t_collide*);

void	*copy_cone(void *);

#endif
