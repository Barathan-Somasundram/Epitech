/*
** display.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 16 22:01:55 2013 vincent colliot
** Last update Fri Jun  7 00:23:46 2013 vincent colliot
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

/* class */
# include "eye.h"
# include "light.h"
# include "object.h"
/* type mod */
# include "bool.h"
# include "fd.h"
/* fonctions */
#include "xml_scan.h"

typedef struct s_display{
  /* public */
  CLASS_EYE	*eye;
  CLASS_LIGHT	*lights;
  CLASS_OBJECT	*objects;
  /* private */
  t_scan	*scan;
  t_token_scan	*objects_def;
}		t_display;

# define CLASS_DISPLAY	t_display
	/* move_to 'etape' */
# define END_PARSING	1
# define END_CALC	2

	/* init */
void	display_init(CLASS_DISPLAY*);
void	xml_scan(CLASS_DISPLAY *, int, char **);
t_3d	ray_adapt(t_3d, t_2d);

#endif
