/*
** init.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed May 14 20:31:40 2014 somasu_b
** Last update Sun Jun  1 17:07:46 2014 somasu_b
*/

#include <ncurses/curses.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "sh.h"

int		inittermcaps(t_42 *sh)
{
  sh->clrscreen = tgetstr("cl", NULL);
  sh->rvmod = tgetstr("mr", NULL);
  sh->disabl = tgetstr("me", NULL);
  sh->clrline = tgetstr("cb", NULL);
  sh->save = tgetstr("sc", NULL);
  sh->restore = tgetstr("rc", NULL);
  sh->stlcrs = tgetstr("vi", NULL);
  sh->alocrs = tgetstr("ve", NULL);
  sh->fd_tty = open("/dev/tty", O_WRONLY);
  if (!sh->clrscreen || !sh->rvmod || !sh->disabl || !sh->clrline || !sh->save
      || !sh->restore || sh->fd_tty == -1)
    return (-1);
  return (0);
}

int		sh_termcaps(char **env, t_42 *sh)
{
  int		i;

  i = 0;
  while (env && env[i] && strncmp(env[i], "TERM=", 5) != 0)
    ++i;
  if (env == NULL || env[i] == NULL)
    return (-1);
  if (tgetent(NULL, env[i] + 5) != 1)
    return (-1);
  if (tcgetattr(1, &(sh->backup)) == -1)
    return (-1);
  if (inittermcaps(sh) == -1)
    return (-1);
  sh->sh_term = sh->backup;
  sh->sh_term.c_lflag &= ~(ICANON | ECHO);
  sh->is_term = 1;
  return (0);
}

static int	sh_history(t_42 *sh)
{
  if ((sh->history = malloc(sizeof(t_env))) == NULL)
    return (-1);
  sh->history->next = sh->history;
  sh->history->prev = sh->history;
  sh->history->position = 1;
  sh->history->number = 0;
  return (0);
}

static int	sh_variable(t_42 *sh)
{
  if ((sh->vars = malloc(sizeof(t_env))) == NULL)
    return (-1);
  sh->vars->next = sh->vars;
  sh->vars->prev = sh->vars;
  return (0);
}

int		sh_init(char **env, t_42 *sh)
{
  sh->counter = 1;
  sh->is_term = 0;
  sh->quit = 0;
  sh->exit = 1;
  if (sh_termcaps(env, sh) == -1)
    fprintf(stderr, "sh: warning: TERM variable is not set\n");
  if (sh_env(env, sh) == -1)
    return (-1);
  if (sh_history(sh) == -1)
    return (-1);
  if (sh_variable(sh) == -1)
    return (-1);
  sh->alias = NULL;
  return (0);
}
