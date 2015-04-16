/*
** aff_cursor.c for 42sh in /home/song_k/rendu/travail_42sh/42sh
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Sun May 25 20:27:12 2014 song_k
** Last update Fri May 30 19:46:32 2014 song_k
*/

#include <ncurses/curses.h>
#include <term.h>
#include <unistd.h>
#include <string.h>
#include "sh.h"

int	tputswrite(const int character)
{
  return (write(1, &character, 1));
}

void	my_aff_stringcursor(t_42 *sh, t_line *line)
{
  tputs(sh->clrline, sh->fd_tty, tputswrite);
  tputs(sh->restore, sh->fd_tty, tputswrite);
  write(1, B_MAGENTA " → " NORMAL, strlen(B_MAGENTA " → " NORMAL));
  write(1, line->cmd, line->pos);
  tputs(sh->rvmod, sh->fd_tty, tputswrite);
  if (line->pos == line->len)
    write(1, " ", 1);
  else
    write(1, line->cmd + line->pos, 1);
  tputs(sh->disabl, sh->fd_tty, tputswrite);
  if (line->pos != line->len)
    write(1, line->cmd + line->pos + 1, line->len - line->pos);
}
