/*
** plan.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 14:57:19 2013 vincent colliot
** Last update Sun Jun  9 16:25:02 2013 vincent colliot
*/

#ifndef M_PLAN_H_
# define M_PLAN_H_

	/* scan */
void	plan_pos(void*,t_token*);
void	plan_color(void*,t_token*);
void	plan_focus(void*,t_token*);
void	plan_high(void*,t_token*);

	/* collide */
t_3d	collide_plan(void *, t_3d, t_3d, t_collide *);
t_3d	normal_plan(void *, t_3d, t_collide*);

void	*copy_plan(void *);

#endif
