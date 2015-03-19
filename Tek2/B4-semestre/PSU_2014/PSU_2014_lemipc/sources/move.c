/*
** move.c for  in /home/somasu_b/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Mar  7 20:48:48 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 18:50:50 2015 SOMASUNDRAM Barathan
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "lemipc.h"

int		find_vector(int c1, int c2)
{
  if (c1 < c2)
    return (1);
  else if (c1 > c2)
    return (-1);
  return (0);
}

int		activ_move(int x_enemy, int y_enemy)
{
  int		vect_x;
  int		vect_y;
  int		new_pos;
  int		team;

  vect_x = find_vector(POSX(g_pos), x_enemy);
  vect_y = find_vector(POSY(g_pos), y_enemy);
  new_pos = (vect_y + POSY(g_pos)) * MAPY + vect_x + POSX(g_pos);
  if (POSX(new_pos) != x_enemy && POSY(new_pos) != y_enemy)
    {
      if (g_map[new_pos] != '.' || new_pos == (y_enemy * MAPY) + x_enemy)
	return (g_pos);
    }
  if (g_map[new_pos] != '.')
    return (g_pos);
  team = g_map[g_pos];
  g_map[g_pos] = '.';
  g_map[new_pos] = team;
  return (new_pos);
}

int		nb_enemy_map(int team)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (i < MAPX * MAPY)
    {
      if (g_map[i] != '.' && g_map[i] != team + '0')
	nb++;
      i++;
    }
  return (nb);
}

int		move_player(int team, int me)
{
  int		pos_target;
  int		ret;

  if (nb_enemy_map(team) == 0)
    return (g_pos);
  ret = semctl(g_sem_id, 0, GETVAL);
  if ((ret = semctl(g_sem_id, 0, GETVAL)) != me)
    {
      if (ret == -1)
	return (my_perror("semctl"));
    }
  else
    {
      pos_target = recup_my_target(team);
      g_pos = activ_move(POSX(pos_target), POSY(pos_target));
      sleep(1);
    }
  ret = (ret + 1) % (g_map[PLAYERS_MAX] + 1);
  if ((ret = semctl(g_sem_id, 0, SETVAL, ret)) == -1)
    return (my_perror("semctl"));
  return (g_pos);
}

int		nb_enemy_stick(int team, int pos)
{
  int		nb;
  int		x;
  int		y;

  y = POSY(pos) - 1;
  nb = 0;
  while (y <= POSY(pos) + 1)
    {
      x = POSX(g_pos) - 1;
      while (x <= POSX(g_pos) + 1)
	{
	  if (x >= 0 && x < MAPX && y >= 0 && y < MAPY)
	    {
	      if (g_map[y * MAPY + x] != '.'
		  && g_map[y *MAPY + x] != team + '0')
		nb++;
	    }
	  x++;
	}
      y++;
   }
  return (nb);
}
