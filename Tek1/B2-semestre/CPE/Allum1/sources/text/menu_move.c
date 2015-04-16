/*
** menu_move.c for alum-1 in /home/somasu_b/TEST/alum-1/sources/text
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri Feb  7 17:41:00 2014 somasu_b
** Last update Fri Feb  7 17:41:56 2014 somasu_b
*/

#include "game.h"

int	up(t_menu **menu)
{
  t_menu	*tmp;

  tmp = (*menu)->next;
  while (tmp->cursor != TRUE)
    tmp = tmp->next;
  tmp->cursor = FALSE;
  if (tmp->prev == *menu)
    (*menu)->prev->cursor = TRUE;
  else
    tmp->prev->cursor = TRUE;
  return (0);
}

int	down(t_menu **menu)
{
  t_menu	*tmp;

  tmp = (*menu)->next;
  while (tmp->cursor != TRUE)
    tmp = tmp->next;
  tmp->cursor = FALSE;
  if (tmp->next == *menu)
    (*menu)->next->cursor = TRUE;
  else
    tmp->next->cursor = TRUE;
  return (0);
}

int	left(t_menu **menu)
{
  t_menu	*tmp;

  tmp = (*menu)->next;
  while (tmp->cursor != TRUE)
    tmp = tmp->next;
  if ((strcmp(tmp->submenu, "  Player 2") == 0)
      || (strcmp(tmp->submenu, "   Music") == 0))
    {
      if (tmp->mode == TRUE)
	tmp->mode = FALSE;
      else
	tmp->mode = TRUE;
    }
  else if (strcmp(tmp->submenu, "How many line ? ") == 0)
    if (tmp->nb_alum > 4)
      tmp->nb_alum = tmp->nb_alum - 1;
  return (0);
}

int	right(t_menu **menu)
{
  t_menu	*tmp;

  tmp = (*menu)->next;
  while (tmp->cursor != TRUE)
    tmp = tmp->next;
  if ((strcmp(tmp->submenu, "  Player 2") == 0)
      || (strcmp(tmp->submenu, "   Music") == 0))
    {
      if (tmp->mode == TRUE)
	tmp->mode = FALSE;
      else
	tmp->mode = TRUE;
    }
  else if (strcmp(tmp->submenu, "How many line ? ") == 0)
    if (tmp->nb_alum < 26)
      tmp->nb_alum = tmp->nb_alum + 1;
  return (0);
}
