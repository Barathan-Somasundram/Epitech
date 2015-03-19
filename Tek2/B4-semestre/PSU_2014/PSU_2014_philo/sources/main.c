/*
** main.c for  in /home/somasu_b/rendu/PSU_2014_philo
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Feb 23 17:52:46 2015 SOMASUNDRAM Barathan
** Last update Mon Feb 23 17:54:02 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

void			*action_philo(void *param)
{
  t_philo		*philo;

  philo = (t_philo *)param;
  while (1)
    if (philo->rice > 0)
      {
	pthread_mutex_lock (&my_mutex);
	if (philo->state == 2)
	  philo_sleep(philo);
	else if ((philo->stick > 0 && philo->next->stick > 0 && philo->state != 2
		  && philo->prev->state != 1 && philo->next->state != 1)
		 || philo->state == 1)
	  philo_eat(philo);
	else if (philo->prev->state != 1 && philo->next->state == 0
		 && philo->stick > 0)
	  philo_think(philo, 1);
	else if (philo->prev->state == 0 && philo->next->state != 1
		 && philo->stick > 0)
	  philo_think(philo, -1);
	else
	  philo_sleep(philo);
      }
    else
      philo->state = -1;
  return (NULL);
}

void			aff_state(t_philo *philo)
{
  if (philo->stick == 0)
    printf("   ");
  else
    printf(" | ");
  if (philo->state == 0)
    printf("[Dors ]");
  else if (philo->state == 1)
    printf("[Pense]");
  else if (philo->state == 2)
    printf("[Mange]");
  else
    printf("[DEAD ]");
  return ;
}

void			*aff_philo(void *param)
{
  t_philo		*philo;
  t_philo		*tmp;
  int			nb_philo;

  philo = (t_philo *)param;
  while (1)
    {
      nb_philo = 0;
      tmp = philo;
      while (nb_philo++ < N_PHILO)
	{
	  aff_state(tmp);
	  tmp = tmp->next;
	}
      printf("\n");
      sleep(1);
    }
  return (NULL);
}

int			verif_exit(t_philo *philo)
{
  t_philo		*tmp;
  int			flag_life;
  int			nb_philo;

  tmp = philo;
  flag_life = 0;
  nb_philo = 0;
  while (nb_philo++ < N_PHILO)
    {
      if (tmp->state != -1)
	flag_life = 1;
      tmp = tmp->next;
    }
  if (flag_life == 0)
    return (0);
  return (1);
}

int			main()
{
  t_philo		*philo;
  t_philo		*tmp;
  int			nb_philo;
  pthread_t		thr[N_PHILO + 1];

  nb_philo = 0;
  if ((philo = init_philo()) == NULL)
    return (-1);
  tmp = philo;
  pthread_mutex_init(&my_mutex, NULL);
  while (nb_philo < N_PHILO)
    {
      if (pthread_create(&thr[0], NULL, action_philo, (void *)tmp) < 0)
	  return (-1);
      nb_philo++;
      tmp = tmp->next;
    }
  sleep(0.2);
  if (pthread_create(&thr[0], NULL, aff_philo, (void *)philo) < 0)
    return (-1);
  while (verif_exit(philo) == 1);
  return (1);
}
