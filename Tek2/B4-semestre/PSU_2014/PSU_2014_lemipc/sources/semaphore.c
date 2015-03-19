/*
** semaphore.c for  in /home/somasu_b/PSU_2014_lemipc
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Mar  7 18:35:02 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 18:19:17 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "lemipc.h"

int		init_semaphore(int *flag)
{
  int		id;
  key_t		key;
  char*		pwd;

  pwd = NULL;
  if ((pwd = getcwd(pwd, PWD_SIZE)) == NULL)
    return (-1);
  key = ftok(pwd, SEM_KEY_ID);
  if ((id = semget(key, SEM_NB, SEM_RIGHTS)) == -1)
    {
      if ((id = semget(key, SEM_NB, IPC_CREAT | IPC_EXCL | SEM_RIGHTS)) == -1)
	return (my_perror("semget"));
      *flag = 1;
    }
  if (semctl(id, 0, SETVAL, 1) == -1)
    return (my_perror("semctl"));
  return (id);
}

int		semaphore_delete(void)
{
  if (semctl(g_sem_id, 0, IPC_RMID, 0) == -1)
    return (my_perror("semctl"));
  return (0);
}
