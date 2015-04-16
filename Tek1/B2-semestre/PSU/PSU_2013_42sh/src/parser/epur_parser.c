/*
** epur_parser.c for 42sh in /home/somasu_b/rendu/mysh/src/parser
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu May 22 02:42:11 2014 somasu_b
** Last update Thu May 29 23:20:13 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static int	add_token(t_tok **epur, char *cmd, int type)
{
  t_tok		*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((elem->cmd = strdup(cmd)) == NULL)
    return (-1);
  elem->type = type;
  elem->next = *epur;
  elem->prev = (*epur)->prev;
  (*epur)->prev->next = elem;
  (*epur)->prev = elem;
  return (0);
}

int		epur_token(t_cmd *cmd, t_tok *token, int type)
{
  t_cmd		*tmp_cmd;
  t_tok		*tmp_tok;
  t_tok		*epur_tok;

  tmp_cmd = cmd->next;
  while (tmp_cmd != cmd)
    {
      if ((epur_tok = malloc(sizeof(*epur_tok))) == NULL)
	return (-1);
      epur_tok->prev = epur_tok;
      epur_tok->next = epur_tok;
      tmp_tok = tmp_cmd->token;
      while (tmp_tok != token && tmp_tok->type != type)
	{
	  if (add_token(&epur_tok, tmp_tok->cmd, tmp_tok->type) == -1)
	    return (-1);
	  tmp_tok = tmp_tok->next;
	}
      tmp_cmd->token = epur_tok;
      tmp_cmd = tmp_cmd->next;
    }
  return (0);
}

int		epur_tree(t_tree *tree)
{
  t_cmd		*tmp;

  tmp = tree->cmd->next;
  while (tmp != tree->cmd)
    {
      if (tmp->tree != NULL)
	{
	  epur_tree(tmp->tree);
	  free(tmp->token);
	  tmp->token = NULL;
	}
      tmp = tmp->next;
    }
  return (0);
}
