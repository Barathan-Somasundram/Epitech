/*
** links.c for lemin in /home/song_k/rendu/lemin-2016-song_k/workgit/Lem-in/prog_elem/song_k/src
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Sun Apr 27 16:33:05 2014 song_k
** Last update Sun May  4 23:03:49 2014 somasu_b
*/

#include <stdlib.h>
#include "lemin.h"

static int	goodsyntax(char *str)
{
  int		i;

  i = -1;
  if (str == NULL || str[0] == '\0')
    return (-1);
  if (str[0] == '#')
    return (0);
  while (str[++i] && str[i] != '-');
  if (str[i] != '-' || str[i + 1] == '\0')
    return (-1);
  while (str[++i] && str[i] != '-');
  if (str[i])
    return (-1);
  return (0);
}
static int	recuppos(t_data *way, char *str, int *ct)
{
  int		c;
  int		bloc_ct;

  c = *ct - 1;
  while (str[++c] && str[c] != '-');
  bloc_ct = -1;
  while (++bloc_ct < way->nb_bloc
	 && my_strncmp(way->data[bloc_ct].name, str + *ct, c - *ct));
  if (bloc_ct == way->nb_bloc)
    return (-1);
  while (str[*ct] && str[*ct] != '-')
    ++(*ct);
  *ct = (str[*ct] == '-') ? *ct + 1 : *ct;
  return (bloc_ct);
}

static int	setlink(t_bloc *bloc, char *name, int pos)
{
  t_list	*tmp;
  t_list	*new;

  tmp = bloc->links;
  while (tmp != NULL && tmp->bloc != pos)
    tmp = tmp->next;
  if (tmp && tmp->bloc == pos)
    return (0);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (-1);
  new->bloc = pos;
  new->name = name;
  new->remains = -1;
  new->next = bloc->links;
  bloc->links = new;
  return (0);
}

static int	makelink(t_data *way, char *str)
{
  int		ct;
  int		pos1;
  int		pos2;

  ct = 0;
  if ((pos1 = recuppos(way, str, &ct)) == -1)
    return (-1);
  if ((pos2 = recuppos(way, str, &ct)) == -1)
    return (-1);
  if (pos1 == pos2)
    return (0);
  if (setlink(&way->data[pos1], way->data[pos2].name, pos2) == -1)
    return (-1);
  if (setlink(&way->data[pos2], way->data[pos1].name, pos1) == -1)
    return (-1);
  return (0);
}

int		filllink(t_data *way, int *ct)
{
  --(*ct);
  while (way->maze_data[++(*ct)])
    {
      if (goodsyntax(way->maze_data[*ct]) == -1)
	{
	  my_putstr(LINKS_PARS, 2);
	  my_putstr(way->maze_data[*ct], 2);
	  my_putstr("\n", 2);
	  return (-1);
	}
      if (way->maze_data[*ct][0] != '#')
	if (makelink(way, way->maze_data[*ct]) == -1)
	  return (-1);
    }
  return (0);
}
