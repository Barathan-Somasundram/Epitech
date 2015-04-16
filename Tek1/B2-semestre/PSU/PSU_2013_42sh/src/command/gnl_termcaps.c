/*
** gnl_termcaps.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed May 14 22:47:59 2014 somasu_b
** Last update Sun Jun  1 18:04:21 2014 somasu_b
*/

#include <ncurses/curses.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static const t_keys	g_func[11] =
  {
    {DOWN, &gere_history},
    {UP, &gere_history},
    {BK_SPACE, &gere_backspace},
    {DEL, &gere_del},
    {CLEAR, &gere_clear},
    {CTRL_K, &gere_cleanaftercursor},
    {CTRL_U, &gere_clearline},
    {CTRL_A, &gere_movecursor},
    {BEGIN, &gere_movecursor},
    {END, &gere_movecursor},
    {CTRL_W, &gere_killword},
  };

int		strcat_chr(t_line *line, char keycode)
{
  char		*new;
  int		i;

  if (line->cmd == NULL)
    return (-1);
  if ((new = malloc(sizeof(char) * (line->len++ + 2))) == NULL)
    return (-1);
  i = -1;
  while (++i < line->pos)
    new[i] = line->cmd[i];
  new[i] = keycode;
  while (++i < line->len)
    new[i] = line->cmd[i - 1];
  new[i] = '\0';
  ++line->pos;
  free(line->cmd);
  line->cmd = new;
  return (0);
}

int		gere_keycode(int keycode, t_line *line, t_42 *sh)
{
  int		ct;

  ct = 0;
  while (ct < 11 && g_func[ct].keycode != keycode)
    ++ct;
  if (ct != 11)
    {
      if (g_func[ct].fct(sh, line, keycode) == -1)
	return (-1);
      return (0);
    }
  if (keycode == LEFT || keycode == CTRL_B)
    line->pos = line->pos ? line->pos - 1 : line->pos;
  else if (keycode == RIGHT)
    line->pos = line->pos < line->len ? line->pos + 1 : line->pos;
  else if (keycode != CTRL_D && keycode >= ' ' && keycode <= '~')
    if (strcat_chr(line, keycode) == -1)
      return (-1);
  return (0);
}

static int	gnl_loop(t_42 *sh, t_line *line, int *keycode)
{
  int		ret;

  *keycode = 0;
  while ((ret = read(STDIN_FILENO, keycode, 4)) > 0 && *keycode != '\n')
    {
      if (*keycode == CTRL_D && line->len == 0)
	return (-1);
      if (gere_keycode(*keycode, line, sh) == -1)
	return (-1);
      my_aff_stringcursor(sh, line);
      *keycode = 0;
    }
  if (ret == -1)
    return (-1);
  return (0);
}

char		*gnl_termcaps(t_42 *sh)
{
  t_line	line;
  int		keycode;

  if ((line.cmd = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  line.cmd[0] = '\0';
  line.len = 0;
  line.pos = 0;
  write(1, "\r", 1);
  tputs(sh->stlcrs, 1, tputswrite);
  tputs(sh->save, 1, tputswrite);
  my_aff_stringcursor(sh, &line);
  if (gnl_loop(sh, &line, &keycode) == -1)
    return (NULL);
  tputs(sh->clrline, sh->fd_tty, tputswrite);
  printf("\r%s → %s%s\n", B_MAGENTA, NORMAL, line.cmd);
  return (line.cmd);
}
