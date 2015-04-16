/*
** algo.c for lemin in /home/song_k/rendu/lemin-2016-song_k/workgit/Lem-in/prog_elem/song_k/src
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Sun May  4 19:39:14 2014 song_k
** Last update Sun May  4 23:36:49 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

static int	startline(t_data *way, int link)
{
  int		which;
  t_list	*tmp;

  tmp = way->data[link].links;
  while (tmp != NULL && tmp->remains == -1 && way->data[tmp->bloc].here == 1)
    tmp = tmp->next;
  if (tmp == NULL)
    return (-1);
  which = tmp->remains;
  while (tmp != NULL)
    {
      if (which >= tmp->remains && way->data[tmp->bloc].here == 0)
	return (tmp->bloc);
      tmp = tmp->next;
    }
  return (-1);
}

static int	moveant(t_data *way, t_list **ant_pos)
{
  t_list	*tmp;
  int		pos;

  tmp = *ant_pos;
  pos = 1;
  if (ant_pos == NULL)
    return (1);
  while (tmp != NULL && pos != -1)
    {
      way->data[tmp->bloc].here = 0;
      if ((pos = startline(way, tmp->bloc)) == -1)
	return (-1);
      tmp->bloc = pos;
      tmp->name = way->data[tmp->bloc].name;
      affant(tmp->my_id, tmp->name);
      way->data[tmp->bloc].here = 1;
      tmp = tmp->next;
      if (tmp == NULL)
	my_putstr("\n", 1);
    }
  return (0);
}

static int	placenewant(t_data *way, t_list **ant_pos, int *ids)
{
  t_list	*elem;
  int		pos;

  while ((pos = startline(way, 0)) != -1 && *ids < way->nb_ant)
    {
      way->data[pos].here = 1;
      if ((elem = malloc(sizeof(*elem))) == NULL)
	return (-1);
      elem->bloc = pos;
      elem->my_id = ++(*ids);
      elem->name = way->data[pos].name;
      elem->next = *ant_pos;
      *ant_pos = elem;
      affant(elem->my_id, elem->name);
    }
  my_putstr("\n", 1);
  return (0);
}

int	free_elem(t_list *ant_pos, t_data *way)
{
  t_list	*tmp1;
  t_list	*tmp2;
  static int	passed = 1;

  tmp1 = ant_pos;
  while (tmp1 != NULL && tmp1->bloc != way->nb_bloc - 1)
    tmp1 = tmp1->next;
  if (tmp1 != NULL)
    {
      ++passed;
      tmp2 = tmp1;
      tmp1 = ant_pos;
      while (tmp1 != NULL && tmp1->next != tmp2)
	tmp1 = tmp1->next;
      way->data[tmp2->bloc].here = 0;
      tmp1 = tmp2->next;
    }
  if (passed == way->nb_ant)
    return (-1);
  return (0);
}

int		main_algo(t_data *way)
{
  int		nb_ant;
  int		chk;
  t_list	*ant_pos;

  nb_ant = 0;
  ant_pos = NULL;
  chk = 0;
  while (chk != -1 && nb_ant < way->nb_ant)
    {
      moveant(way, &ant_pos);
      if (nb_ant < way->nb_ant && placenewant(way, &ant_pos, &nb_ant) == -1)
	return (EXIT_FAILURE);
      if (ant_pos != NULL)
	chk = free_elem(ant_pos, way);
      way->data[way->nb_bloc - 1].here = 0;
    }
  return (EXIT_SUCCESS);
}
