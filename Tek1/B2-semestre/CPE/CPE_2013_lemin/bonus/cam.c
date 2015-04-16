/*
** cam.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sun May  4 15:39:57 2014 potier_g
** Last update Sun May  4 21:13:48 2014 potier_g
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "struct.h"

int	cam_sdl(t_param *param, t_move move)
{
  if (param->cam == 0)
    cam_global(param->base, param->size_base, param->camy);
  else
    if (param->view == 0)
      cam_3perso(param->cam - 1, move);
    else
      cam_1perso(param->cam - 1, move);
  return (0);
}

int	cam_3perso(int pos, t_move move)
{
  int	x;
  int	viewx;
  int	z;
  int	viewz;

  viewx = move.pos_act.x[pos];
  viewz = move.pos_act.y[pos];
  x = viewx - (move.vect.x[pos] / 10);
  z = viewz - (move.vect.y[pos] / 10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, 5, z, viewx, 0, viewz, 0, 0, 1);
  return (0);
}

int	cam_1perso(int pos, t_move move)
{
  int	x;
  int	viewx;
  int	z;
  int	viewz;

  x = move.pos_act.x[pos] + (move.vect.x[pos] / 10) * 2;
  z = move.pos_act.y[pos] + (move.vect.y[pos] / 10) * 2;
  viewx = x + (move.vect.x[pos] / 10) * 10;
  viewz = z + (move.vect.y[pos] / 10) * 10;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, 0, z, viewx, 0, viewz, 0, 0, 1);
  return (0);
}

int	cam_global(t_base *base, int len, int y)
{
  int	x;
  int	z;

  x = (limit_x(base, len, -1) + ((limit_x(base, len, 1)
				  - limit_x(base, len, -1)) / 2)) * 10;
  z = (limit_y(base, len, -1) + ((limit_y(base, len, 1)
				  - limit_y(base, len, -1)) / 2)) * 10;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, x, 0, z, 0, 0, 1);
  return (0);
}
