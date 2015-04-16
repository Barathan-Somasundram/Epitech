/*
** list.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Feb  4 12:22:33 2014 somasu_b
** Last update Sun Feb 16 21:27:54 2014 somasu_b
*/

#include "../../includes/bonus.h"

static int	create_alum_root(t_alum **alum)
{
  if ((*alum = malloc(sizeof(**alum))) == NULL)
    return (-1);
  (*alum)->prev = *alum;
  (*alum)->next = *alum;
  return (0);
}

static int	create_line_root(t_line **line)
{
  if ((*line = malloc(sizeof(**line))) == NULL)
    return (-1);
  (*line)->prev = *line;
  (*line)->next = *line;
  return (0);
}

static int		my_put_line(t_line **line)
{
  t_line	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->match = "║";
  elem->cursor = FALSE;
  elem->select = FALSE;
  elem->prev = (*line)->prev;
  elem->next = *line;
  (*line)->prev->next = elem;
  (*line)->prev = elem;
  return (0);
}

static int	my_put_alum(t_alum **alum, int size)
{
  t_alum	*elem;
  int		i;

  i = 1;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((create_line_root(&(elem->line))) == -1)
    return (-1);
  while (i <= size)
    {
      if ((my_put_line(&(elem->line))) == -1)
	return (-1);
      i = i + 1;
    }
  elem->size = size;
  elem->cursor = FALSE;
  elem->prev = (*alum)->prev;
  elem->next = *alum;
  (*alum)->prev->next = elem;
  (*alum)->prev = elem;
  return (0);
}

int	init_alum(t_alum **alum, int line)
{
  int	nb_alum;
  int	i;

  nb_alum = 0;
  i = 1;
  if ((create_alum_root(alum)) == -1)
    return (-1);
  while (i <= line)
    {
      if (i == 1)
	nb_alum = 1;
      else
	nb_alum = nb_alum + 2;
      if ((my_put_alum(alum, nb_alum)) == -1)
	return (-1);
      i = i + 1;
    }
  (*alum)->next->line->next->cursor = TRUE;
  (*alum)->next->cursor = TRUE;
  return (0);
}
