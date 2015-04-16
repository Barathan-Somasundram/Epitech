/*
** free.c for 42sh in /home/somasu_b/Music/PSU_2013_42sh/somasu_b
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri May 30 20:32:05 2014 somasu_b
** Last update Sun Jun  1 16:53:43 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

void		free_token(t_tok *token)
{
  t_tok		*tmp;

  tmp = token->next;
  while (tmp != token)
    {
      tmp = tmp->next;
      free(tmp->prev->cmd);
      free(tmp->prev);
    }
  free(token);
}

void		free_tree(t_tree *tree)
{
  t_cmd		*tmp_cmd;

  tmp_cmd = tree->cmd->next;
  while (tmp_cmd != tree->cmd)
    {
      if (tmp_cmd->tree != NULL)
	free_tree(tmp_cmd->tree);
      else
	free_token(tmp_cmd->token);
      tmp_cmd = tmp_cmd->next;
      free(tmp_cmd->prev);
    }
  free(tmp_cmd);
  free(tree);
}
