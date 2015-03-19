/*
** game.c for  in /home/somasu_b/rendu/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar  8 16:46:08 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 16:50:13 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <SDL/SDL.h>
#include "lemipc.h"

int		if_map_finish(void)
{
  int		i;
  int		team;

  i = 0;
  team = -1;
  while (i < MAPX * MAPY)
    {
      if (team == -1 && g_map[i] != '.')
	team = g_map[i];
      else if (g_map[i] != '.')
	{
	  if (team != g_map[i])
	    return (0);
	}
      i++;
    }
  return (1);
}

int		create_game(int team, int me)
{
  SDL_Surface	*screen;
  int		nb_enemy;
  pthread_t	thr;

  screen = init_screen();
  g_pos = pop_player(team);
  nb_enemy = 1;
  if (pthread_create(&thr, NULL, print_map, (void *)screen) < 0)
    return (-1);
  while (*g_nb_player < 3);
  while (nb_enemy_stick(team, g_pos) < 2 && nb_enemy > 0)
    {
      if ((g_pos = move_player(team, me)) == -1)
        return (1);
      nb_enemy = nb_enemy_map(team);
    }
  if (nb_enemy == 0)
    printf("TEAM %d WIN\n", team);
  g_map[g_pos] = '.';
  *g_nb_player -= 1;
  while (if_map_finish() == 0);
  delete_shm(g_shm_id);
  return (1);
}

int		join_game(int team, int me)
{
  int		nb_enemy;
  int		finish;

  finish = 0;
  nb_enemy = 1;
  g_pos = pop_player(team);
  while (*g_nb_player < 3);
  sleep(0.5);
  while (nb_enemy_stick(team, g_pos) < 2 && finish == 0
	 && nb_enemy > 0)
    {
      if ((g_pos = move_player(team, me)) == -1)
        return (1);
      finish = if_map_finish();
      nb_enemy = nb_enemy_map(team);
    }
  if (nb_enemy == 0)
    printf("TEAM %d WIN\n", team);
  g_map[g_pos] = '.';
  *g_nb_player -= 1;
  delete_shm(g_shm_id);
  return (1);
}
