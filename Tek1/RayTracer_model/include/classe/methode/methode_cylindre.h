/*
** methode_cylindre.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:04:37 2013 vincent colliot
** Last update Sun Jun  9 16:24:47 2013 vincent colliot
*/

#ifndef M_CYLINDRE_H_
# define M_CYLINDRE_H_

	/* scan */
void	cylindre_pos(void*,t_token*);
void	cylindre_color(void*,t_token*);
void	cylindre_rayon(void*,t_token*);
void	cylindre_focus(void*,t_token*);

	/* collide */
t_3d	collide_cylindre(void *, t_3d, t_3d, t_collide *);
t_3d	normal_cylindre(void *, t_3d, t_collide*);

void	*copy_cylindre(void *);

#endif
