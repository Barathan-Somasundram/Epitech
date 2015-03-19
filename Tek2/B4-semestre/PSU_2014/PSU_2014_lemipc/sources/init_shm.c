/*
** init_shm.c for  in /home/somasu_b/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Mar  6 10:59:39 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 18:50:29 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "lemipc.h"

int		create_get_shm(int *flag_create)
{
  int		id;
  key_t		key;
  char*		pwd;

  pwd = NULL;
  if ((pwd = getcwd(pwd, PWD_SIZE)) == NULL)
    return (-1);
  key = ftok(pwd, SHM_KEY_ID);
  id = shmget(key, SHM_SIZE, SHM_RIGHTS);
  if (id == -1)
    {
      id = shmget(key, SHM_SIZE, SHM_RIGHTS | IPC_CREAT | IPC_EXCL);
      *flag_create = 1;
    }
  if (id == -1)
    return (my_perror("shmget"));
  return (id);
}

int		*recup_mem(int id, int flag)
{
  int		i;

  if ((g_map = (int *)shmat(id, NULL, 0)) == (void*) -1)
    return (my_perror("shmat") == -1 ? NULL : NULL);
  if (flag == 1)
    {
      i = 0;
      while (i < MAPY * MAPX)
	g_map[i++] = '.';
      g_map[PLAYERS] = -1;
      g_map[PLAYERS_MAX] = -1;
    }
  g_nb_player = &(g_map[PLAYERS]);
  return (g_map);
}

void		delete_shm(int shm_id)
{
  int		is_empty;

  is_empty = 1;
  g_map[g_pos] = '.';
  g_pos = 0;
  while (g_pos < MAPX * MAPY)
    {
      if (g_map[g_pos++] != '.')
	is_empty = 0;
    }
  shmdt(g_map);
  if (is_empty == 1)
    {
      shmctl(shm_id, IPC_RMID, NULL);
      semctl(g_sem_id, 0, IPC_RMID, 0);
    }
}
