/*
** limit.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  9 06:01:31 2013 vincent colliot
** Last update Sun Jun  9 06:59:03 2013 vincent colliot
*/

#ifndef LIMIT_H_
# define LIMIT_H_

# define XPLUS 0
# define XLESS 1
# define YPLUS 2
# define YLESS 3
# define ZPLUS 4
# define ZLESS 5

typedef struct s_limit{
  BOOL	valid;
  double	on;
}		t_limit;

BOOL	limitless(t_collide*, t_limit[6], t_3d, t_3d);

#endif
