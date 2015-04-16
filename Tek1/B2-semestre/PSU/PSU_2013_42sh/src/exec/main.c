/*
** main.c for 42sh in /home/somasu_b/rendu/mysh/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu May 22 00:53:15 2014 somasu_b
** Last update Sun Jun  1 18:28:21 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

static int	rm_tok(t_tok *tmp)
{
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  free(tmp->cmd);
  free(tmp);
  return (0);
}

static int	rm_redir_tokens(t_tok *token)
{
  t_tok		*tmp;

  tmp = token->next;
  while (tmp != token)
    {
      if (tmp->type == TYPE_RIGHT1 || tmp->type == TYPE_RIGHT2
	  || tmp->type == TYPE_LEFT1 || tmp->type == TYPE_LEFT2)
	{
	  tmp = tmp->next->next;
	  rm_tok(tmp->prev);
	  rm_tok(tmp->prev);
	}
      else
	tmp = tmp->next;
    }
  return (0);
}

static int	is_redir_else_exec(t_42 *sh, t_tok *token)
{
  t_tok		*tmp;
  int		ret;

  tmp = token->next;
  while (tmp != token)
    {
      while (tmp != token && tmp->type != TYPE_RIGHT1
	     && tmp->type != TYPE_RIGHT2 && tmp->type != TYPE_LEFT1
	     && tmp->type != TYPE_LEFT2)
	tmp = tmp->next;
      if (tmp != token)
	{
	  if ((ret = redirection(sh, tmp)) == -1 || ret == -2)
	    return (ret);
	  tmp = tmp->next->next;
	}
    }
  rm_redir_tokens(token);
  return (cmd_execution(sh, token));
}

int		main_execution(t_42 *sh, t_tree *tree)
{
  t_cmd		*tmp;
  int		ret;

  sh->end_pipe = 0;
  tmp = tree->cmd->next;
  while (tmp != tree->cmd)
    {
      sh->fds[0] = dup(0);
      sh->fds[1] = dup(1);
      ret = and_or_pipe(sh, tree, tmp);
      if (ret == -1 || ret == 0)
      	return (ret);
      if (tmp->tree != NULL && main_execution(sh, tmp->tree) == -1)
      	return (-1);
      if (tmp->tree == NULL)
      	if (is_redir_else_exec(sh, tmp->token) == -1)
      	  return (-1);
      dup2(sh->fds[0], 0);
      dup2(sh->fds[1], 1);
      tmp = tmp->next;
    }
  return (0);
}
