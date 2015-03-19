/*
** recup_target.c for  in /home/somasu_b/rendu/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar  8 18:13:18 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 18:13:19 2015 SOMASUNDRAM Barathan
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "lemipc.h"

int		check_target(int x, int y, float *dist, int *target)
{
  float		tmp_dist;

  tmp_dist = calc_dist(g_pos, y * MAPY + x);
  if (tmp_dist < *dist)
    {
      *dist = tmp_dist;
      *target = y * MAPY + x;
    }
  return (1);
}

int		recup_zone(int pos)
{
  int		x;
  int		y;
  float		dist;
  int		target_pos;

  if (pos < 0 || pos > MAPX * MAPY)
    return (g_pos);
  dist = MAPX * MAPY;
  y = POSY(pos) - 1;
  while (y <= POSY(pos) + 1)
    {
      x = POSX(pos) - 1;
      while (x <= POSX(pos) + 1)
	{
	  if (x >= 0 && x < MAPX && y >= 0 && x < MAPY
	      && g_map[y * MAPY + x] == '.'
	      && x != POSX(pos) && y != POSY(pos))
	    check_target(x, y, &dist, &target_pos);
	  x++;
	}
      y++;
    }
  return (target_pos);
}
