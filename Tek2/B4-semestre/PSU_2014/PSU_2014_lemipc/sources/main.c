/*
** main.c for  in /home/somasu_b/rendu/PSU_2014_lemipc/sources
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Mar  2 15:47:46 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 21:16:24 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "lemipc.h"

int		*g_map;
int		g_pos;
int		g_shm_id;
int		g_sem_id;
int		*g_nb_player;

int		my_perror(char *error)
{
  perror(error);
  return (-1);
}

int		lemipc(int team, int mod)
{
  int		flag_create;
  int		me;

  signal_manager();
  flag_create = 0;
  if ((g_shm_id = create_get_shm(&flag_create)) == -1)
    return (-1);
  if ((g_sem_id = init_semaphore(&flag_create)) == -1)
    return (-1);
  if ((g_map = recup_mem(g_shm_id, flag_create)) == NULL)
    return (-1);
  (*g_nb_player)++;
  g_map[PLAYERS_MAX]++;
  if (mod == 0)
    team = (*g_nb_player) % 2 + 1;
  me = *g_nb_player;
  if (flag_create == 1)
    create_game(team, me);
  else
    join_game(team, me);
  return (0);
}

int		check_param(char *team)
{
  int		i;

  i = -1;
  if (strlen(team) != 1)
    {
      fprintf(stderr, "Error: affectation to a"
	      " team is only by number [1-2]\n");
      return (-1);
    }
  while (team[++i] != '\0')
    if (team[i] != '1' && team[i] != '2')
      {
	fprintf(stderr, "Error: affectation to a"
		" team is only by number [1-2]\n");
	return (-1);
      }
  return (0);
}

int		main(int ac, char **av)
{
  if (ac > 1)
    {
      if (check_param(av[1]) == -1)
	return (EXIT_FAILURE);
      if (lemipc(atoi(av[1]), 1) == -1)
	return (EXIT_FAILURE);
    }
  else
    lemipc(1, 0);
  return (EXIT_SUCCESS);
}
