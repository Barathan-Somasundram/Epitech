/*
** pipe.c for 42sh in /home/somasu_b/rendu/42sh/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 09:43:24 2014 somasu_b
** Last update Sun Jun  1 18:27:21 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

static int	ending(int pipe_fds[2][2], int *j)
{
  if (*j == 1)
    {
      if (dup2(pipe_fds[0][0], 0) == -1)
	return (-1);
      close(pipe_fds[0][1]);
      if (pipe_fds[1][0] != -1)
	close(pipe_fds[1][0]);
    }
  else
    {
      if (dup2(pipe_fds[1][0], 0) == -1)
	return (-1);
      close(pipe_fds[1][1]);
      close(pipe_fds[0][0]);
    }
  *j *= -1;
  return (1);
}

static int	midone(int pipe_fds[2][2], int *j)
{
  if (*j == 1)
    {
      if (pipe_fds[1][0] != -1)
	close(pipe_fds[1][0]);
      if (pipe(pipe_fds[1]) == -1
	  || dup2(pipe_fds[1][1], 1) == -1
	  || dup2(pipe_fds[0][0], 0) == -1)
	return (-1);
      close(pipe_fds[0][1]);
    }
  else
    {
      close(pipe_fds[0][0]);
      if (pipe(pipe_fds[0]) == -1
	  || dup2(pipe_fds[0][1], 1) == -1
	  || dup2(pipe_fds[1][0], 0) == -1)
	return (-1);
      close(pipe_fds[1][1]);
    }
  *j *= -1;
  return (1);
}

static int	starting(int pipe_fds[2][2], int *j)
{
  *j = 1;
  if (pipe(pipe_fds[0]) == -1
      || dup2(pipe_fds[0][1], 1) == -1)
    return (-1);
  return (1);
}

int		sh_pipe(t_tree *tree, t_cmd *cmd, t_42 *sh)
{
  static int	i = 0;
  static int	j = 1;
  static int	pipe_fds[2][2];

  sh->end_pipe = 1;
  if (cmd == tree->cmd->next)
    {
      if (i == 0)
	i++;
      else
	{
	  if (j == -1)
	    close(pipe_fds[0][0]);
	  else if (pipe_fds[1][0] != -1)
	    close(pipe_fds[1][0]);
	}
      pipe_fds[1][0] = -1;
      return (starting(pipe_fds, &j));
    }
  if (cmd == tree->cmd->prev)
    {
      sh->end_pipe = 0;
      return (ending(pipe_fds, &j));
    }
  return (midone(pipe_fds, &j));
}
