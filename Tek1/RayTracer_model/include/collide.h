/*
** collide.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Jun  1 22:59:52 2013 vincent colliot
** Last update Wed Jun  5 20:07:53 2013 vincent colliot
*/

#ifndef COLLIDE_H_
# define COLLIDE_H_

# include <stdlib.h>
#include "u_color.h"
#include "dim.h"
#include "flag.h"

# define MAX_DEGREE_LVL	2
# define K_COL		0.1

/*
 *alpha == reverb sur 0 - 1
 *gamma == transpa sur 0 -1
 *
 */
typedef struct s_shadow{
  int		n;
  double	scale;
}		t_shadow;

typedef struct s_collide{
  /* collide part */
  size_t	defined;
  size_t	up_to;
  double	k[MAX_DEGREE_LVL];
  t_3d		collide;
  t_3d		normal;
  FLAG		n_spec;
  /* light part */
  double	ct_init;
  t_shadow	shading;
  t_3d		light;
  t_3d		r_light;
  void		*ld;
  /* color part */
  t_color	color;
  double	shining;
  double	alpha;
  double	gamma;
}		t_collide;

t_3d	collide_arrange(t_collide *, t_3d, t_3d);

# endif
