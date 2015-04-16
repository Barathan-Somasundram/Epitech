/*
** bonus.c for lem-in in /home/potier_g/Lem-in/Bonus
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Tue Apr 22 20:00:00 2014 potier_g
** Last update Sun May  4 22:35:30 2014 potier_g
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "struct.h"

int		aff_map(t_param *param, t_move move)
{
  int		act;

  act = -1;
  cam_sdl(param, move);
  while (++act < param->size_base)
    sphere_fdf(param->base[act].x, param->base[act].y);
  act = 0;
  while (act < param->size_tube)
    aff_cylinder(param, act++);
  return (0);
}

int		detect_char_null(char c)
{
  if (c > 0 && c < 32)
    return (1);
  if (c > 127)
    return (1);
  return (0);
}

int		main(int argc, char **argv)
{
  t_param	*my_param;

  if ((my_param = malloc(sizeof(t_param))) == NULL)
    return (-1);
  if ((my_param = init_file(my_param)) == NULL)
    return (0);
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("Lem-in", NULL);
  SDL_SetVideoMode(1600, 900, 32, SDL_OPENGL);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(70, (double)1600/900, 1, 1000);
  my_start(my_param);
  glFlush();
  SDL_GL_SwapBuffers();
  return (0);
}
