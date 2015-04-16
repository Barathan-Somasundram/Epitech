/*
** event.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sun May  4 14:46:28 2014 potier_g
** Last update Sun May  4 21:07:41 2014 potier_g
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "struct.h"

int		pause()
{
  static int	p;
  SDL_Event	event;

  event.key.keysym.sym = 0;
  p = 1;
  while (p == 1)
    {
      if (event.key.keysym.sym == 112 && event.type == 2)
	p = 0;
      if (event.type == SDL_QUIT || (event.type == 2
				     && event.key.keysym.sym == 27))
	exit (0);
      SDL_PollEvent(&event);
    }
  return (0);
}

int		event2(int sign, t_param *param)
{
  if (sign == 112)
    pause();
  if (sign == 275)
    param->cam++;
  if (sign == 276)
    param->cam--;
  if (sign == 273)
    param->view--;
  if (sign == 274)
    param->view--;
  if (sign == 270)
    param->camy-=10;
  if (sign == 269)
    param->camy+=10;
  return (0);
}

int		event(t_param *param, t_move move)
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT
      || (event.type == 2 && event.key.keysym.sym == 27))
    exit (0);
  if (event.type == 2)
    event2(event.key.keysym.sym, param);
  if (param->cam > move.nbr_ant)
    param->cam = 0;
  else if (param->cam < 0)
    param->cam = move.nbr_ant;
  if (param->view > 1)
    param->view = 0;
  else if (param->view < 0)
    param->view = 1;
  return (0);
}
