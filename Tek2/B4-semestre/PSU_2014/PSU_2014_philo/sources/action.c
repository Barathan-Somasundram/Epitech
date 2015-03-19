/*
** action.c for  in /home/somasu_b/rendu/PSU_2014_philo
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

void			philo_eat(t_philo *philo)
{
  philo->state = 2;
  philo->stick -= 1;
  philo->rice -= 1;
  philo->next->stick -= 1;
  pthread_mutex_unlock (&my_mutex);
  while (philo->time < TIME_EAT)
    {
      philo->time++;
      sleep(1);
    }
  philo->time = 0;
  philo->stick += 1;
  philo->next->stick += 1;
  return ;
}

void			philo_sleep(t_philo *philo)
{
  philo->state = 0;
  pthread_mutex_unlock (&my_mutex);
  sleep(1);
  return ;
}

void			philo_think(t_philo *philo, int stick)
{
  if (stick == -1)
    philo->stick -= 1;
  else
    philo->next->stick -= 1;
  philo->state = 1;
  pthread_mutex_unlock (&my_mutex);
  while (philo->time < TIME_THINK)
    {
      philo->time++;
      sleep(1);
    }
  philo->time = 0;
  if (stick == -1)
    philo->stick += 1;
  else
    philo->next->stick += 1;
  return ;
}
