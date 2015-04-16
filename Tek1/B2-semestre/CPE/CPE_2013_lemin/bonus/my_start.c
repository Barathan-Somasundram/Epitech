/*
** my_start.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Mon Apr 28 18:22:34 2014 potier_g
** Last update Sun May  4 22:10:55 2014 potier_g
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

int	*init_posx(int size, t_move move, t_param *param, int s)
{
  int	pos;
  int	id;
  int	*posx;
  char	*base;
  int	a;

  pos = -1;
  id = 0;
  if ((posx = malloc(sizeof(int) * size)) == NULL)
    return (NULL);
  while (++pos < param->nbr_ant)
    {
      if (s == 1)
	base = move.prev_base[pos];
      else
	base = move.nxt_base[pos];
      if (my_strcmp(base, "#null\0") == 0)
	{
	  a = 0;
	  while (a < param->size_base && my_strcmp(base, param->base[a].name) != 1)
	    a++;
	  posx[id++] = param->base[a].x * 10;
	}
    }
  return (posx);
}

int     *init_posy(int size, t_move move, t_param *param, int s)
{
  int	id;
  int   pos;
  int   *posy;
  char  *base;
  int	a;

  pos = -1;
  id = 0;
  if ((posy = malloc(sizeof(int) * size)) == NULL)
    return (NULL);
  while (++pos < param->nbr_ant)
    {
      if (s == 1)
	base = my_strdup(move.prev_base[pos]);
	else
	  base = move.nxt_base[pos];
      if (my_strcmp(base, "#null\0") == 0)
	{
	  a = 0;
	  while (a < param->size_base && my_strcmp(base, param->base[a].name) != 1)
	    a++;
	  posy[id++] = param->base[a].y * 10;
	}
    }
  return (posy);
}

int		*calc_vect(t_coor start, t_coor end, int size, int s)
{
  int		*vect;
  int		pos;

  if ((vect = malloc(sizeof(int) * size)) == NULL)
    return (NULL);
  pos = 0;
  while (pos < size)
    {
      if (s == 1)
	vect[pos] = end.x[pos] - start.x[pos];
      else
	vect[pos] = end.y[pos] - start.y[pos];
      pos++;
    }
  return (vect);
}

int		move_ant(t_move move, t_param *param)
{
  int		ant;
  t_coor       	end;

  if (init_move_ant(&move, param, &end) == -1)
    return (-1);
  while (detect_end(move.pos_act, end, move.nbr_ant) == 0)
    {
      ant = 0;
      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      event(param, move);
      aff_map(param, move);
      while (ant < move.nbr_ant)
      	{
      	  move.pos_act.x[ant] = move.pos_act.x[ant]
	    + (move.vect.x[ant] / 10);
      	  move.pos_act.y[ant] = move.pos_act.y[ant]
	    + (move.vect.y[ant] / 10);
	  draw_ant(param, move, ant);
      	  ant++;
      	}
      glFlush();
      SDL_GL_SwapBuffers();
      usleep(100000);
    }
   return (0);
}

int	my_start(t_param *param)
{
  char	*base_start;
  int	pos;

  pos = 0;
  base_start = param->name_start;
  while (pos < param->size_move)
    if (move_ant(param->move[pos++], param) == -1)
      return (-1);
  return (0);
}
