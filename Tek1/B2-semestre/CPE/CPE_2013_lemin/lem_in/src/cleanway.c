/*
** cleanway.c for lemin in /home/song_k/rendu/lemin-2016-song_k/workgit/Lem-in/prog_elem/song_k/src
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Sat May  3 17:19:35 2014 song_k
** Last update Sun May  4 23:23:22 2014 somasu_b
*/

#include <stdlib.h>
#include "lemin.h"

static int	initlinks(t_data *way, int *remain, int from, int *check)
{
  t_list	*tmp;

  if ((tmp = way->data[from].links) == NULL)
    return (-1);
  if (from == way->nb_bloc - 1)
    return (0);
  way->data[from].here = 1;
  while (tmp != NULL)
    {
      if (way->data[tmp->bloc].here == 0)
	if (initlinks(way, remain, tmp->bloc, check) == 0)
	  {
	    if (tmp->bloc == way->nb_bloc - 1)
	      {
		*remain = 0;
		tmp->remains = *remain;
		*check = 1;
	      }
	    else if (tmp->remains == -1 || *remain < tmp->remains)
	      tmp->remains = ++(*remain);
	  }
      tmp = tmp->next;
    }
  way->data[from].here = 0;
  return (0);
}

int		cleanway(t_data *way)
{
  int		remain;
  int		check;

  if (way->data[0].links == NULL)
    return (-1);
  remain = 0;
  check = 0;
  if (initlinks(way, &remain, 0, &check) == -1)
    return (-1);
  if (check == 0)
    return (-1);
  return (0);
}
