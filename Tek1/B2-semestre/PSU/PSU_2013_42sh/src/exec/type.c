/*
** type.c for 42sh in /home/somasu_b/Music/42/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu May 29 13:52:24 2014 somasu_b
** Last update Sun Jun  1 17:29:30 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static int	and_or_execution(t_42 *sh, int mode)
{
  int		ret;

  ret = 0;
  if (mode == TYPE_AND)
    {
      if (sh->exit == 0)
	ret = 0;
      else
	ret = 1;
    }
  else if (mode == TYPE_OR)
    {
      if (sh->exit == 0)
	ret = 1;
      else
	ret = 0;
    }
  return (ret);
}

static void	rm_bg(t_tok *tmp)
{
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  free(tmp);
}

int		background(t_42 *sh, t_tok *token)
{
  pid_t		son;

  if (strcmp(token->prev->cmd, "&") == 0)
    {
      if ((son = fork()) == -1)
	return (-1);
      if (son == 0)
	{
	  if (setpgid(getpid(), getpid()) != 0)
	    return (-1);
	  rm_bg(token->prev);
	  if (cmd_execution(sh, token) == -1)
	    return (-1);
	  exit(EXIT_SUCCESS);
	}
      else
	return (1);
    }
  return (0);
}

int		and_or_pipe(t_42 *sh, t_tree *tree, t_cmd *cmd)
{
  if ((cmd == tree->cmd->next && tree->type != TYPE_PIPE)
      || tree->type == TYPE_SEP)
    return (1);
  if (tree->type == TYPE_AND || tree->type == TYPE_OR)
    return (and_or_execution(sh, tree->type));
  else if (tree->type == TYPE_PIPE)
    return (sh_pipe(tree, cmd, sh));
  return (0);
}
