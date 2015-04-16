/*
** blocdata.c for lemin in /home/song_k/rendu/lemin-2016-song_k/workgit/Lem-in/prog_elem/song_k/src
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Wed Apr 23 14:26:36 2014 song_k
** Last update Sat May  3 18:51:47 2014 song_k
*/

#include <stdlib.h>
#include "lemin.h"

static void	countblock(char **data, int *max)
{
  int		ct;
  int		i;

  ct = 0;
  *max = 0;
  while (data[++ct] && data[ct])
    {
      if (data[ct][0] != '#')
	{
	  i = -1;
	  while (data[ct][++i] && data[ct][i] != ' ' && data[ct][i] != '\t');
	  if (i > -1 && data[ct][i] == ' ')
	    ++(*max);
	}
    }
}

static char	*fillname(char *str, int *i)
{
  char		*new;

  *i = -1;
  while (str[++(*i)] && str[*i] != ' ' && str[*i] != '\t');
  if ((new = malloc(sizeof(char) * (*i + 1))) == NULL)
    return (NULL);
  if (*i == 0)
    {
      my_putstr(BAD_NAME, 2);
      my_putstr(str, 2);
      my_putstr("\n", 2);
      return (NULL);
    }
  *i = -1;
  while (str[++(*i)] && str[*i] != ' ' && str[*i] != '\t')
    new[*i] = str[*i];
  new[*i] = '\0';
  return (new);
}

static int	linedata(char *str, t_data *way, int mode)
{
  static int	pos = 0;
  int		ct;
  int		i;

  ct = (mode ? (mode == 1 ? 0 : way->nb_bloc - 1) : ++pos);
  if ((way->data[ct].name = fillname(str, &i)) == NULL)
    return (-1);
  while (str[++i] && (str[i] == ' ' || str[i] == '\t'));
  way->data[ct].posx = my_getnbr(str + i);
  while (str[++i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'));
  if (str[i] != ' ' && str[i] != '\t')
    return (-1);
  while (str[++i] && (str[i] == ' ' || str[i] == '\t'));
  if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
    return (-1);
  way->data[ct].posy = my_getnbr(str + i);
  way->data[ct].links = NULL;
  way->data[ct].here = 0;
  return (0);
}

static int	fillstruct(t_data *way, int *ct)
{
  int		ct_block;
  int		ret;

  ct_block = 0;
  while (way->maze_data[++*ct] && ct_block < way->nb_bloc)
    {
       if (my_strncmp(way->maze_data[*ct], START_TAG,
		     my_strlen(way->maze_data[*ct])) == 0)
	ret = linedata(way->maze_data[++(*ct)], way, 1);
      else if (my_strncmp(way->maze_data[*ct], END_TAG,
			  my_strlen(way->maze_data[*ct])) == 0)
	ret = linedata(way->maze_data[++(*ct)], way, 2);
      else if (way->maze_data[*ct][0] != '#')
	ret = linedata(way->maze_data[*ct], way, 0);
      if (ret == -1)
	{
	  my_putstr(PARS_ERR, 2);
	  my_putstr(way->maze_data[*ct], 2);
	  my_putstr("\n", 2);
	  return (-1);
	}
      if (way->maze_data[*ct][0] != '#')
	++ct_block;
    }
  return (0);
}

int	fillbloc(t_data *way)
{
  int	ct;

  ct = 0;
  countblock(way->maze_data, &way->nb_bloc);
  if (way->nb_bloc < 2)
    {
      my_putstr(BLOC_FAIL, 2);
      return (-1);
    }
  if ((way->data = malloc(sizeof(*way->data) * way->nb_bloc)) == NULL)
    return (-1);
  if (fillstruct(way, &ct) == -1)
    return (-1);
  if (way->maze_data[ct] == NULL)
    {
      my_putstr(NO_LINKS, 2);
      return (-1);
    }
  if (filllink(way, &ct) == -1)
    return (-1);
  return (0);
}
