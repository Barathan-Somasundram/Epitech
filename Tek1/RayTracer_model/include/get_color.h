/*
** get_color.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 15:39:16 2013 vincent colliot
** Last update Wed Jun  5 22:45:00 2013 vincent colliot
*/

#ifndef GET_COLOR_H_
# define GET_COLOR_H_

# define INDICE_1 1.004
# define INDICE_2 0.80

t_color	get_color(struct s_display *, void *, t_collide, t_3d[2]);
t_color	mod_color(struct s_display *, void *, t_collide, t_3d[2]);
t_color	add_color(t_color, t_color, double, t_color*);

#endif
