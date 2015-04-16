/*
** dim.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 18:24:15 2013 vincent colliot
** Last update Mon Jun  3 16:25:11 2013 vincent colliot
*/

#ifndef DIM_H_
# define DIM_H_

#include <math.h>
	/* calculs */
typedef struct s_3e{
  double a;
  double b;
  double c;
}		t_3e;

	/* coord */
typedef struct s_3d{
  double	x;
  double	y;
  double	z;
}		t_3d;

typedef struct s_2d{
  double	x;
  double	y;
}		t_2d;

typedef struct s_3i{
  int	x;
  int	y;
  int	z;
}		t_3i;

typedef struct s_2i{
  int	x;
  int	y;
}		t_2i;

	/* calc */
# define C(r) ((r) * (r))
	/* convert */
t_3d	convert_focus(t_3d);
t_3d	dist_convert(t_3d, t_3d, double);
t_3d	convert_norm(t_3d);
t_3d	convert_ray(t_3d, t_3d);
double	convert_scal(t_3d, t_3d);
double	convert_cos(t_3d, t_3d);

#endif
