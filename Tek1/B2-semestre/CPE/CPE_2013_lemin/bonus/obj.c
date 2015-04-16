/*
** obj.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Wed Apr 23 12:08:48 2014 potier_g
** Last update Sun May  4 22:12:31 2014 potier_g
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "struct.h"

int             cylinder_fdf(int *pos, double angle, int size)
{
  GLUquadric    *quadrique;

  glPushMatrix();
  glTranslated(pos[0] * 10, 0, pos[1] * 10);
  glRotated(90 - angle, 0, 1, 0);
  glBegin(GL_QUADS);
  quadrique=gluNewQuadric();
  gluQuadricDrawStyle(quadrique, GLU_LINE);
  glColor3f(1, 0, 0);
  gluCylinder(quadrique, 2, 2, size, 10, 10);
  gluDeleteQuadric(quadrique);
  glEnd();
  glPopMatrix();
  return (0);
}

double		recup_angle(int *loc)
{
  double	V1[2];
  double	V2[2] = {1, 0};
  double	scal1;
  double	scal2;
  double	croix;
  double	C;

  V1[0] = loc[2] * 10 - loc[0] * 10;
  V1[1] = loc[3] * 10 - loc[1] * 10;
  croix = (V1[0] * V2[0]) + (V1[1] * V2[1]);
  scal1 = sqrt(pow(V1[0], 2) + pow(V1[1], 2));
  scal2 = sqrt(pow(V2[0], 2) + pow(V2[1], 2));
  C = croix / (scal1 * scal2);
  C = (180 * acos(C) / M_PI);
  if (loc[3] < loc[1])
    return (((180 - C) * 2) + C);
  return (C);
}

int		aff_cylinder(t_param *param, int act)
{
  double	angle;
  int		size;
  int		pos;
  int		loc[4];

  pos = 0;
  while (pos < param->size_base)
    {
      if (my_strcmp(param->base[pos].name, param->tube[act].name1) == 1)
      	{
      	  loc[0] = param->base[pos].x;
      	  loc[1] = param->base[pos].y;
      	}
      if (my_strcmp(param->base[pos].name, param->tube[act].name2) == 1)
      	{
          loc[2] = param->base[pos].x;
          loc[3] = param->base[pos].y;
        }
      pos++;
    }
  size = sqrt(pow(((loc[2] * 10) - (loc[0] * 10)), 2)
	      + pow(((loc[3] * 10) - (loc[1] * 10)), 2));
  angle = recup_angle(loc);
  cylinder_fdf(loc, angle, size);
  return (0);
}

int             sphere_fdf(int x, int y)
{
  GLUquadric    *quadrique;

  glPushMatrix();
  glTranslated(x * 10, 0, y * 10);
  glBegin(GL_QUADS);
  quadrique=gluNewQuadric();
  gluQuadricDrawStyle(quadrique, GLU_LINE);
  glColor3f(0, 1, 1);
  gluSphere(quadrique, 5, 20, 20);
  gluSphere(quadrique, 2, 20, 20);
  gluDeleteQuadric(quadrique);
  glEnd();
  glPopMatrix();
  return (0);
}
