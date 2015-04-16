/*
** move.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Feb  5 16:52:15 2014 somasu_b
** Last update Sun Feb 16 21:28:30 2014 somasu_b
*/

#include "../../includes/bonus.h"

int	move_up(t_alum **alum)
{
  t_alum	*tmp_al;
  t_line	*tmp_li;

  tmp_al = (*alum)->next;
  while (tmp_al->cursor != TRUE)
    tmp_al = tmp_al->next;
  tmp_li = tmp_al->line->next;
  while (tmp_li->cursor != TRUE)
    tmp_li = tmp_li->next;
  if (tmp_li == tmp_al->line)
    tmp_al->line->next->cursor = FALSE;
  else
    tmp_li->cursor = FALSE;
  tmp_al->cursor = FALSE;
  if (tmp_al->prev == *alum)
    {
      (*alum)->prev->cursor = TRUE;
      (*alum)->prev->line->next->cursor = TRUE;
    }
  else
    {
      tmp_al->prev->cursor = TRUE;
      tmp_al->prev->line->next->cursor = TRUE;
    }
  return (0);
}

int	move_down(t_alum **alum)
{
  t_alum	*tmp_al;
  t_line	*tmp_li;

  tmp_al = (*alum)->next;
  while (tmp_al->cursor != TRUE)
    tmp_al = tmp_al->next;
  tmp_li = tmp_al->line->next;
  while (tmp_li->cursor != TRUE)
    tmp_li = tmp_li->next;
  if (tmp_li == tmp_al->line)
    tmp_al->line->next->cursor = FALSE;
  else
    tmp_li->cursor = FALSE;
  tmp_al->cursor = FALSE;
  if (tmp_al->next == *alum)
    {
      (*alum)->next->cursor = TRUE;
      (*alum)->next->line->next->cursor = TRUE;
    }
  else
    {
      tmp_al->next->cursor = TRUE;
      tmp_al->next->line->next->cursor = TRUE;
    }
  return (0);
}

int	move_left(t_alum **alum)
{
  t_alum	*tmp_al;
  t_line	*tmp_li;

  tmp_al = (*alum)->next;
  while (tmp_al->cursor != TRUE)
    tmp_al = tmp_al->next;
  tmp_li = tmp_al->line->next;
  while (tmp_li->cursor != TRUE)
    tmp_li = tmp_li->next;
  tmp_li->cursor = FALSE;
  if (tmp_li->prev == tmp_al->line)
    tmp_al->line->prev->cursor = TRUE;
  else
    tmp_li->prev->cursor = TRUE;
  return (0);
}

int	move_right(t_alum **alum)
{
  t_alum	*tmp_al;
  t_line	*tmp_li;

  tmp_al = (*alum)->next;
  while (tmp_al->cursor != TRUE)
    tmp_al = tmp_al->next;
  tmp_li = tmp_al->line->next;
  while (tmp_li->cursor != TRUE)
    tmp_li = tmp_li->next;
  tmp_li->cursor = FALSE;
  if (tmp_li->next == tmp_al->line)
    tmp_al->line->next->cursor = TRUE;
  else
    tmp_li->next->cursor = TRUE;
  return (0);
}

int	select_out(t_alum **alum)
{
  t_alum	*tmp_al;
  t_line	*tmp_li;

  tmp_al = (*alum)->next;
  while (tmp_al->cursor != TRUE)
    tmp_al = tmp_al->next;
  tmp_li = tmp_al->line->next;
  while (tmp_li != tmp_al->line)
    {
      if (tmp_li->select == TRUE)
  	tmp_li->select = FALSE;
      tmp_li = tmp_li->next;
    }
  return (0);
}
