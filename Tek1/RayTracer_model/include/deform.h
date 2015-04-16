/*
** defrom.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu Jun  6 17:55:16 2013 vincent colliot
** Last update Thu Jun  6 18:50:44 2013 vincent colliot
*/

#ifndef DEFORM_H_
# define DEFORM_H_

# define dX 0
# define dY 1
# define dZ 2

typedef struct s_deform{
  double space;
  double scale;
}		t_deform;

# define dsX 0b001
# define dsY 0b010
# define dsZ 0b100

#endif
