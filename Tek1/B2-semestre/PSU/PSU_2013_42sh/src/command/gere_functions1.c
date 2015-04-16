/*
** gere_functions1.c for 42sh in /home/song_k/rendu/travail_42sh/PSU_2013_42sh/PSU_2013_42sh/src/command
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Sat May 31 15:38:51 2014 song_k
** Last update Sat May 31 15:42:38 2014 song_k
*/

#include <stdlib.h>
#include <string.h>
#include "sh.h"

int		gere_cleanaftercursor(t_42 *sh, t_line *line, int keycode)
{
  char		*new;
  int		ct;

  (void)sh;
  (void)keycode;
  line->len = line->pos;
  if ((new = malloc(sizeof(char) * (line->len + 1))) == NULL)
    return (-1);
  ct = -1;
  while (++ct < line->len)
    new[ct] = line->cmd[ct];
  new[ct] = '\0';
  free(line->cmd);
  line->cmd = new;
  return (0);
}

int		gere_clearline(t_42 *sh, t_line *line, int keycode)
{
  char	*new;

  (void)sh;
  (void)keycode;
  line->len = 0;
  line->pos = 0;
  if ((new = malloc(sizeof(char))) == NULL)
    return (-1);
  new[0] = '\0';
  free(line->cmd);
  line->cmd = new;
  return (0);
}

int		gere_movecursor(t_42 *sh, t_line *line, int keycode)
{
  (void)sh;
  if (keycode == END)
    line->pos = line->len;
  else
    line->pos = 0;
  return (0);
}

static void	my_derementor(t_line *line, int *ct)
{
  if (line->pos == line->len)
    --(*ct);
  while (*ct > 0 && (line->cmd[*ct] == ' ' || line->cmd[*ct] == '\t'))
    --(*ct);
  while (*ct > 0 && line->cmd[*ct] != ' ' && line->cmd[*ct] != '\t')
    --(*ct);
}

int		gere_killword(t_42 *sh, t_line *line, int keycode)
{
  char		*new;
  int		count;
  int		ct;

  (void)sh;
  (void)keycode;
  if (line->len == 0 || line->pos == 0)
    return (0);
  ct = line->pos;
  my_derementor(line, &ct);
  if ((new = malloc(sizeof(char) * line->len + line->pos - ct + 1)) == NULL)
    return (-1);
  count = -1;
  while (++count < ct)
    new[count] = line->cmd[count];
  ct = line->pos;
  line->pos = count;
  while (line->cmd[ct])
    new[count++] = line->cmd[ct++];
  new[count] = '\0';
  free(line->cmd);
  line->len = strlen(new);
  line->cmd = new;
  return (0);
}
