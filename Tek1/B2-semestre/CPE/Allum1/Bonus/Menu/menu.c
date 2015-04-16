/*
** menu.c for alum-1 in /home/somasu_b/TEST/alum-1/sources/text
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri Feb  7 17:42:32 2014 somasu_b
** Last update Sun Feb 16 21:26:51 2014 somasu_b
*/

#include "../../includes/bonus.h"

static int	my_put_menu(t_menu **menu, char *submenu, int nb_alum, bool mode)
{
  t_menu	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->submenu = submenu;
  elem->cursor = FALSE;
  elem->mode = mode;
  elem->nb_alum = nb_alum;
  elem->prev = (*menu)->prev;
  elem->next = *menu;
  (*menu)->prev->next = elem;
  (*menu)->prev = elem;
  return (0);
}

static int	create_menu_root(t_menu **menu)
{
  if ((*menu = malloc(sizeof(**menu))) == NULL)
    return (-1);
  (*menu)->next = *menu;
  (*menu)->prev = *menu;
  return (0);
}

int	init_menu(t_menu **menu)
{
  if (create_menu_root(menu) == -1)
    return (-1);
  if ((my_put_menu(menu, "  Player 1", -1, FALSE)) == -1)
    return (-1);
  if ((my_put_menu(menu, "  Player 2", -1, FALSE)) == -1)
    return (-1);
  if ((my_put_menu(menu, "How many line ? ", 4, FALSE)) == -1)
    return (-1);
  if ((my_put_menu(menu, "   Music", -1, FALSE)) == -1)
    return (-1);
  (*menu)->next->cursor = TRUE;
  return (0);
}

int	game_menu(t_menu **menu)
{
  int	ret;

  ret = 0;
  if (opening() == -1)
    return (-1);
  if ((ret = cmd_center(menu)) == -1)
    return (ret);
  if (ret == 2)
    return (2);
  return (0);
}
