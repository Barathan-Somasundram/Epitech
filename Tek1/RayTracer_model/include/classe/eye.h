/*
** eye.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 30 22:47:54 2013 vincent colliot
** Last update Sun Jun  9 05:37:35 2013 vincent colliot
*/

#ifndef EYE_H_
# define EYE_H_

#include "xml_scan.h"
#include "dim.h"
#include "collide.h"

typedef struct s_eye{
  /* public */
  t_3d	 position;
  t_3d	 focus;
  double scale;
  t_shadow render;
  FLAG	filter;
  /* methode d'init de vue a put ici +
   précision de l'oeil (oui j'ai oublié le nom réél)*/
  /* double angle ? */
  /* private */
  t_token_scan *scan;
}		t_eye;

# define CLASS_EYE t_eye

# define FOV	10

void	eye_init(void *, void *);

#endif
