/*
** my_select_print.c for my_select in /home/somasu_b/TEST/select
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 13:53:39 2014 somasu_b
** Last update Sun Jan 19 20:23:39 2014 a
*/

#include "my_select.h"

static void	print_case(t_list *tmp)
{
  if (tmp->inverse == TRUE)
    {
      if (tmp->cursor == TRUE)
	tputs(tgetstr("us", NULL), 1, tputchar);
      tputs(tgetstr("mr", NULL), 1, tputchar);
      my_tty_str(tmp->item);
      my_tty_str("\n");
      tputs(tgetstr("me", NULL), 1, tputchar);
    }
  else if (tmp->cursor == TRUE)
    {
      tputs(tgetstr("us", NULL), 1, tputchar);
      my_tty_str(tmp->item);
      my_tty_str("\n");
      tputs(tgetstr("ue", NULL), 1, tputchar);
    }
  else
    {
      my_tty_str(tmp->item);
      my_tty_str("\n");
    }
}

static int	cursor_pos_in_win(t_wins *winsize, int *line,
				  int *column, int length)
{
  *line = *line + 1;
  if (*line + 1 == winsize->ws_row)
    {
      *line = 0;
      *column = *column + length + 5;
      if (*column + length + 1 > winsize->ws_col)
	{
	  my_clear_full_screen();
	  my_tty_str("Please, resize your terminal window\n"
		     "if can't do it means that there are to many items\n"
		     "Press ENTER, please\n");
	  return (-1);
	}
    }
  return (0);
}

int		my_aff(t_wins *winsize, int length)
{
  t_list	*tmp;
  int		line;
  int		column;

  tmp = g_list->next;
  line = 0;
  column = 0;
  while (tmp != g_list)
    {
      tputs(tgoto(tgetstr("cm", NULL), column, line), 1, tputchar);
      print_case(tmp);
      tmp = tmp->next;
      if (cursor_pos_in_win(winsize, &line, &column, length) == -1)
	return (-1);
    }
  tputs(tgetstr("vi", NULL), 1, tputchar);
  return (0);
}
