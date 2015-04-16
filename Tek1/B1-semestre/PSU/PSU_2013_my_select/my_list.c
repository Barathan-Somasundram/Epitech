/*
** my_list.c for my_select in /home/somasu_b/TEST/select
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 13:56:05 2014 somasu_b
** Last update Sun Jan 19 20:09:20 2014 somasu_b
*/

#include "my_select.h"

static int		my_put_in_list(t_list **list, char *item, bool cursor)
{
  t_list		*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->item = item;
  elem->cursor = cursor;
  elem->inverse = FALSE;
  elem->previous = (*list)->previous;
  elem->next = *list;
  (*list)->previous->next = elem;
  (*list)->previous = elem;
  return (0);
}

static int	create_root_list()
{
  if ((g_list = malloc(sizeof(*g_list))) == NULL)
    return (-1);
  g_list->previous = g_list;
  g_list->next = g_list;
  return (0);
}

int	init_list(int ac, char **av)
{
  int	i;

  i = 1;
  if (ac <= 1)
    return (-1);
  create_root_list();
  while (i < ac)
    {
      if (i == 1)
      	if (my_put_in_list(&g_list, av[i], TRUE) == -1)
      	  return (-1);
      if (i > 1)
	if (my_put_in_list(&g_list, av[i], FALSE) == -1)
	  return (-1);
      i = i + 1;
    }
  return (0);
}
