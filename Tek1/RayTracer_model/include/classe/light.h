/*
** light.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 21:46:39 2013 vincent colliot
** Last update Fri Jun  7 06:40:38 2013 vincent colliot
*/

#ifndef LIGHT_H_
# define LIGHT_H_

#include "xml_scan.h"
#include "dim.h"
#include "u_color.h"
#include "collide.h"

typedef struct	s_light{
  /* public */
  struct s_light	*next;
  struct s_light	*prev;
  /*private */
  t_shadow	render;
  t_token_scan	*scan;
  t_color	color;
  t_3d		position;
}		t_light;

# define CLASS_LIGHT t_light

void	light_init(void *,void *);

#endif
