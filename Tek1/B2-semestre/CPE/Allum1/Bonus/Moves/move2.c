/*
** move2.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Feb  6 15:31:43 2014 somasu_b
** Last update Sun Feb 16 21:28:23 2014 somasu_b
*/

#include "../../includes/bonus.h"

int	select_it(t_alum **alum)
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
  if (tmp_li->select == FALSE)
    tmp_li->select = TRUE;
  else
    tmp_li->select = FALSE;
  if (tmp_li->next == tmp_al->line)
    tmp_al->line->next->cursor = TRUE;
  else
    tmp_li->next->cursor = TRUE;
  return (0);
}

int	reset_cursors(t_alum **alum)
{
  if ((*alum)->next != *alum)
    {
      (*alum)->next->cursor = TRUE;
      (*alum)->next->line->next->cursor = TRUE;
    }
  else
    {
      my_clear_full_screen();
      return (1);
    }
  return (0);
}

static void	cursor_select_out(t_line **tmp_li, t_line *line, int *size)
{
  if ((*tmp_li)->cursor == TRUE)
    {
      (*tmp_li)->cursor = FALSE;
      if ((*tmp_li) != line)
	(*tmp_li)->next->cursor = TRUE;
      else
	line->next->cursor = TRUE;
    }
  if ((*tmp_li)->select == TRUE)
    {
      *size = *size + 1;
      (*tmp_li)->prev->next = (*tmp_li)->next;
      (*tmp_li)->next->prev = (*tmp_li)->prev;
      if ((*tmp_li) != line)
	free((*tmp_li));
    }
}

static int	delete_it(t_alum **tmp_al)
{
  t_line	*tmp_li;
  int		size;

  tmp_li = (*tmp_al)->line->next;
  size = 0;
  while (tmp_li != (*tmp_al)->line)
    {
      cursor_select_out(&tmp_li, (*tmp_al)->line, &size);
      tmp_li = tmp_li->next;
    }
  if (tmp_li->next == (*tmp_al)->line)
    {
      (*tmp_al)->prev->next = (*tmp_al)->next;
      (*tmp_al)->next->prev = (*tmp_al)->prev;
      free((*tmp_al)->line);
      free((*tmp_al));
      size = 0;
    }
  return (size);
}

int	valide_it(t_alum **alum)
{
  t_alum	*tmp_al;
  int		size;

  size = 0;
  tmp_al = (*alum)->next;
  while (tmp_al->cursor != TRUE)
    tmp_al = tmp_al->next;
  size = delete_it(&tmp_al);
  if (size != 0)
    tmp_al->size = tmp_al->size - size;
  if (reset_cursors(alum) == 1)
    return (2);
  return (1);
}
