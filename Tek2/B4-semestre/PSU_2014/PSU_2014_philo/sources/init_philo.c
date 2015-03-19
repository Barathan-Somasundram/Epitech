/*
** init_philo.c for  in /home/somasu_b/rendu/PSU_2014_philo
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Feb 23 17:53:13 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  1 19:19:01 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

t_philo			*create_philo(int id, t_philo *prev)
{
  t_philo		*philo;

  if ((philo = malloc(sizeof(t_philo))) == NULL)
    return (NULL);
  philo->id = id;
  philo->state = 0;
  philo->rice = RICE;
  philo->stick = 1;
  philo->time = 0;
  philo->prev = prev;
  philo->next = NULL;
  printf("Le philosophe %d est assis a la table\n", id);
  return (philo);
}

t_philo			*init_philo()
{
  int			nb_philo;
  t_philo		*philo;
  t_philo		*start;

  nb_philo = 2;
  printf("Les Philosophes arrivent\n");
  if ((start = create_philo(1, NULL)) == NULL)
    return (NULL);
  philo = start;
  while (nb_philo <= N_PHILO)
    {
      if ((philo->next = create_philo(nb_philo, philo)) == NULL)
	return (NULL);
      nb_philo++;
      philo = philo->next;
    }
  philo->next = start;
  start->prev = philo;
  return (start);
}
