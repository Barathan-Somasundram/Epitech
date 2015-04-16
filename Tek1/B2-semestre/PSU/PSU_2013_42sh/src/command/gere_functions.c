/*
** gere_functions.c for 42sh in /home/song_k/rendu/travail_42sh/PSU_2013_42sh/song_k/src/command
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Fri May 30 20:17:47 2014 song_k
** Last update Fri May 30 20:22:00 2014 song_k
*/

#include <string.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include <stdlib.h>
#include "sh.h"

int		gere_backspace(t_42 *sh, t_line *line, int keycode)
{
  char		*new;
  int		i;
  int		ct;

  (void)sh;
  (void)keycode;
  if (line->pos < 1)
    return (0);
  --line->len;
  if ((new = malloc(sizeof(char) * (line->len + 1))) == NULL)
    return (-1);
  i = 0;
  ct = 0;
  while (i < line->pos - 1)
    new[ct++] = line->cmd[i++];
  while (++i < line->len + 1)
    new[ct++] = line->cmd[i];
  --line->pos;
  free(line->cmd);
  new[ct] = '\0';
  line->cmd = new;
  return (0);
}

int		gere_del(t_42 *sh, t_line *line, int keycode)
{
  char		*new;
  int		i;

  (void)sh;
  (void)keycode;
  if (line->pos >= line->len)
    return (0);
  --line->len;
  if ((new = malloc(sizeof(char) * (line->len + 1))) == NULL)
    return (-1);
  i = -1;
  while (++i < line->pos)
    new[i] = line->cmd[i];
  while (++i < line->len + 1)
    new[i - 1] = line->cmd[i];
  free(line->cmd);
  new[i - 1] = '\0';
  line->cmd = new;
  return (0);
}

int		gere_clear(t_42 *sh, t_line *line, int keycode)
{
  (void)keycode;
  (void)line;
  tputs(sh->clrscreen, 1, tputswrite);
  sh_prompt(sh);
  write(1, "\r", 1);
  tputs(sh->save, 1, tputswrite);
  return (0);
}

static int	h_newstring(t_line *line)
{
  line->len = 0;
  line->pos = 0;
  if ((line->cmd = malloc(sizeof(char))) == NULL)
    return (-1);
  line->cmd[0] = '\0';
  return (0);
}

int		gere_history(t_42 *sh, t_line *line, int keycode)
{
  t_hist	*tmp;

  tmp = sh->history->next;
  while (tmp != sh->history && tmp->position == 0)
    tmp = tmp->next;
  tmp->position = 0;
  if (keycode == UP)
    tmp = tmp->prev;
  else
    tmp = tmp->next;
  if (tmp != sh->history && tmp->command != NULL)
    {
      tmp->position = 1;
      line->len = strlen(tmp->command);
      line->pos = line->len;
      free(line->cmd);
      if ((line->cmd = strdup(tmp->command)) == NULL)
	return (-1);
    }
  else
    if (h_newstring(line) == -1)
      return (-1);
  return (0);
}
