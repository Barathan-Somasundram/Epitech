/*
** echo.c for 42sh in /home/somasu_b/rendu/mysh/src/built
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat May 24 16:47:54 2014 somasu_b
** Last update Thu May 29 21:53:14 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <glob.h>
#include "sh.h"

static void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}

static int	globing_echo(char *cmd)
{
  glob_t	globuf;
  int		i;

  globuf.gl_offs = 0;
  if (glob(cmd, GLOB_DOOFFS, NULL, &globuf))
    return (-1);
  i = -1;
  while (globuf.gl_pathv[++i])
    {
      my_putstr(globuf.gl_pathv[i]);
      my_putstr(" ");
    }
  globfree(&globuf);
  return (0);
}

int		sh_echo(t_42 *sh, t_tok *token)
{
  t_tok		*tmp;
  int		opt;

  tmp = token->next->next;
  opt = 1;
  while (tmp != token && sh != NULL)
    {
      if (tmp == token->next->next && strcmp(tmp->cmd, "-n") == 0)
	{
	  opt = 0;
	  tmp = tmp->next;
	}
      if (tmp != token)
	{
	  if (tmp->cmd[0] == '*')
	    globing_echo(tmp->cmd);
	  else
	    my_putstr(tmp->cmd);
	  my_putstr(" ");
	  tmp = tmp->next;
	}
    }
  if (opt == 1)
    my_putstr("\n");
  return (1);
}
