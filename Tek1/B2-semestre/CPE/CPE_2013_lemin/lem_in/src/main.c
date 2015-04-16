/*
** main.c for lem-in in /home/song_k/rendu/lemin-2016-song_k/workgit/song_k/src
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Fri Apr 11 14:30:59 2014 song_k
** Last update Sun May  4 23:22:16 2014 somasu_b
*/

#include <stdlib.h>
#include "lemin.h"

static int	my_recupdata(t_data *way)
{
  char		*str;

  if ((str = my_fillinstr(0)) == NULL)
    return (-1);
  if ((way->maze_data = my_str_to_wordtab(str, '\n')) == NULL)
    return (-1);
  free(str);
  way->nb_ant = my_getnbr(way->maze_data[0]);
  if (way->nb_ant < 1)
    {
      my_putstr("There's no ants here please try again\n", 2);
      return (-1);
    }
  if (fillbloc(way) == -1)
    return (-1);
  return (0);
}

int		main(void)
{
  t_data	way;
  int		ct;

  if (my_recupdata(&way) == -1)
    return (EXIT_FAILURE);
  ct = -1;
  while (way.maze_data[++ct])
    {
      if (way.maze_data[ct][0] != '#'
      	  || (my_strcmp(way.maze_data[ct], START_TAG) == 0)
      	  || (my_strcmp(way.maze_data[ct], END_TAG) == 0))
      	{
      	  my_putstr(way.maze_data[ct], 1);
      	  my_putstr("\n", 1);
      	}
      free(way.maze_data[ct]);
    }
  free(way.maze_data);
  if (cleanway(&way) == -1)
    {
      my_putstr(NO_WAY, 2);
      return (EXIT_FAILURE);
    }
  return (main_algo(&way));
}
