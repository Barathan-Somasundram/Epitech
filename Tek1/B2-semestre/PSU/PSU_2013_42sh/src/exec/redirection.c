/*
** redirection.c for 42sh in /home/somasu_b/rendu/mysh/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri May 23 13:16:12 2014 somasu_b
** Last update Sun Jun  1 16:21:38 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sh.h"

static int	sh_right(t_42 *sh, char *file, int type)
{
  static	int	fd = 0;

  (void)sh;
  if (fd != 0 && fd != -1)
    if (close(fd) == -1)
      return (-1);
  if (type == TYPE_RIGHT1)
    if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
      {
	fprintf(stderr, "%s: No such file or directory\n", file);
	return (-2);
      }
  if (type == TYPE_RIGHT2)
    {
      if ((fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
	{
	  fprintf(stderr, "%s: No such file or directory\n", file);
	  return (-2);
	}
    }
  if (dup2(fd, 1) == -1)
    return (-1);
  return (0);
}

static int	sh_left1(t_42 *sh, char *file)
{
  static	int	fd = 0;

  (void)sh;
  if (fd != 0 && fd != -1)
    if (close(fd) == -1)
      return (-1);
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      fprintf(stderr, "%s: No such file or directory\n", file);
      return (-2);
    }
  if (dup2(fd, 0) == -1)
    return (-1);
  return (0);
}

int		redirection(t_42 *sh, t_tok *token)
{
  if (token->type == TYPE_RIGHT1)
    return (sh_right(sh, token->next->cmd, TYPE_RIGHT1));
  else if (token->type == TYPE_RIGHT2)
    return (sh_right(sh, token->next->cmd, TYPE_RIGHT2));
  else if (token->type == TYPE_LEFT1)
    return (sh_left1(sh, token->next->cmd));
  else if (token->type == TYPE_LEFT2)
    return (sh_left2(sh, token->next->cmd));
  return (0);
}
