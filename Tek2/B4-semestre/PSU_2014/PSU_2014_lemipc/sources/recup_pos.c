/*
** recup_pos.c for  in /home/somasu_b/rendu/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar  8 18:13:09 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 18:24:24 2015 SOMASUNDRAM Barathan
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "lemipc.h"

int		pop_player(int team)
{
  int		if_player;

  if_player = 0;
  srand(time(NULL));
  while (if_player == 0)
    {
      g_pos = rand() % (MAPX * MAPY);
      if (g_map[g_pos] == '.')
	{
	  g_map[g_pos] = team + '0';
	  if_player = 1;
	}
    }
  return (g_pos);
}

float		calc_dist(int pos1, int pos2)
{
  float		result;

  result = sqrt(pow(POSX(pos2) - POSX(pos1), 2)
		+ pow(POSY(pos2) - POSY(pos1), 2));
  return (result);
}

int		recup_target_player(int pos, int team)
{
  int		my_target;
  float		my_dist;
  float		tmp_dist;
  int		i;

  i = 0;
  my_dist = MAPX * MAPY;
  while (i <  MAPX * MAPY)
    {
      if (g_map[i] != '.' && g_map[i] != team + '0')
	{
	  tmp_dist = calc_dist(pos, i);
	  if (tmp_dist < my_dist)
	    {
	      my_dist = tmp_dist;
	      my_target = i;
	    }
	}
      i++;
    }
  return (my_target);
}

int		recup_my_target(int team)
{
  int		my_target;
  float		my_dist;
  int		tmp_target;
  float		tmp_dist;
  int		i;

  i = 0;
  my_target = recup_target_player(g_pos, team);
  my_dist = calc_dist(g_pos, my_target);
  while (i < MAPX * MAPY)
    {
      if (g_map[i] == team + '0')
	{
	  tmp_target = recup_target_player(i, team);
	  tmp_dist = calc_dist(i, tmp_target);
	  if (tmp_dist < my_dist)
	    {
	      my_dist = tmp_dist;
	      my_target = tmp_target;
	    }
	}
      i++;
    }
  return (recup_zone(my_target));
}
