/*
** detect_end.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Tue Apr 29 17:13:06 2014 potier_g
** Last update Sun May  4 22:52:01 2014 potier_g
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "struct.h"

int	detect_end(t_coor start, t_coor end, int size)
{
  int	a;

  a = 0;
  while (a < size)
    {
      if (start.x[a] != end.x[a] || start.y[a] != end.y[a])
	return (0);
      a++;
    }
  return (1);
}

int	draw_ant(t_param *param, t_move move, int pos)
{
  GLUquadric    *quadrique;
  int		x;
  int		y;

  x = move.pos_act.x[pos];
  y = move.pos_act.y[pos];
  glPushMatrix();
  glTranslated(x, 0, y);
  glBegin(GL_QUADS);
  quadrique=gluNewQuadric();
  gluQuadricDrawStyle(quadrique, GLU_LINE);
  glColor3f(0, 1, 0);
  gluSphere(quadrique, 1.5, 20, 20);
  gluDeleteQuadric(quadrique);
  glEnd();
  glPopMatrix();
  return (0);
}
