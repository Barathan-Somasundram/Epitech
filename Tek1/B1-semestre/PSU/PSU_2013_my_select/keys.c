/*
** keys.c for my_select.c in /home/somasu_b/TEST/select
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 13:46:47 2014 a
** Last update Sun Jan 19 21:16:22 2014 somasu_b
*/

#include "my_select.h"

int		my_cursor_down()
{
  t_list	*tmp;

  tmp = g_list->next;
  while (tmp->cursor != TRUE)
    tmp = tmp->next;
  tmp->cursor = FALSE;
  if (tmp->next == g_list)
    {
      tmp = g_list->next;
      tmp->cursor = TRUE;
    }
  else
    {
      tmp = tmp->next;
      tmp->cursor = TRUE;
    }
  return (0);
}

int		my_cursor_up()
{
  t_list	*tmp;

  tmp = g_list->next;
  if (tmp->cursor != TRUE)
    {
      while (tmp->next->cursor != TRUE)
  	tmp = tmp->next;
      tmp->cursor = TRUE;
      tmp = tmp->next;
      tmp->cursor = FALSE;
    }
  else
    {
      tmp->cursor = FALSE;
      while (tmp->next != g_list)
  	tmp = tmp->next;
      tmp->cursor = TRUE;
    }
  return (0);
}

void		select_item()
{
  t_list	*tmp;

  tmp = g_list->next;
  while (tmp->cursor != TRUE)
    tmp = tmp->next;
  if (tmp->inverse == FALSE)
    {
      tmp->inverse = TRUE;
      my_cursor_down();
    }
  else
    tmp->inverse = FALSE;
}

void		key_delete()
{
  t_list	*tmp;

  tmp = g_list->next;
  while (tmp->cursor != TRUE)
    tmp = tmp->next;
  tmp->previous->next = tmp->next;
  tmp->next->previous = tmp->previous;
  if (tmp->next != g_list)
    tmp->next->cursor = TRUE;
  else
    g_list->next->cursor = TRUE;
  free(tmp);
}

int		key_validate()
{
  t_list	*tmp;
  int		i;

  i = 0;
  my_clear_full_screen();
  tmp = g_list->next;
  while (tmp != g_list)
    {
      i = i + 1;
      if (tmp->inverse == TRUE)
	{
	  if (i != 1)
	    my_fd_putchar(' ', 1);
	  my_putstr(tmp->item);
	}
      tmp = tmp->next;
    }
  return (1);
}
