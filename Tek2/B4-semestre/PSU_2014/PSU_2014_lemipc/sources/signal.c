/*
** signal.c for  in /home/somasu_b/rendu/PSU_2014_lemipc/sources
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar  8 16:42:22 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 16:43:09 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "lemipc.h"

void		rmv_player(int sig)
{
  (void)sig;
  g_map[g_pos] = '.';
  *g_nb_player -= 1;
  delete_shm(g_shm_id);
  exit(EXIT_SUCCESS);
}

void		signal_manager(void)
{
  signal(SIGINT, rmv_player);
  signal(SIGKILL, rmv_player);
}
