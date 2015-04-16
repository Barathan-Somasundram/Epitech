/*
** filtre.h for  in /home/lecorr_b//projets/RT/Ray-Tracer/Rt
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue Jun  4 15:54:22 2013 thomas lecorre
** Last update Sun Jun  9 22:18:43 2013 quentin cloarec
*/

#ifndef	FILTRE_H__
#define	FILTRE_H__

#include "u_color.h"

t_color	filtre(t_color, int);
void    grey(t_color *pix);
void    sepia(t_color *pix);
void    red(t_color *pix);

#endif
