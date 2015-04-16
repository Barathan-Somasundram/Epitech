/*
** structs.c for 42sh in /home/somasu_b/rendu/mysh/src/parser
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu May 22 02:39:51 2014 somasu_b
** Last update Thu May 29 21:56:49 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

int		init_tree(t_tree **tree, int type)
{
  if ((*tree = malloc(sizeof(**tree))) == NULL)
    return (-1);
  if (((*tree)->cmd = malloc(sizeof(t_cmd))) == NULL)
    return (-1);
  (*tree)->type = type;
  (*tree)->cmd->prev = (*tree)->cmd;
  (*tree)->cmd->next = (*tree)->cmd;
  return (0);
}

int		add_elem(t_tree **tree, t_tok *token)
{
  t_cmd		*cmd;

  if ((cmd = malloc(sizeof(*cmd))) == NULL)
    return (-1);
  cmd->token = token;
  cmd->tree = NULL;
  cmd->next = (*tree)->cmd;
  cmd->prev = (*tree)->cmd->prev;
  (*tree)->cmd->prev->next = cmd;
  (*tree)->cmd->prev = cmd;
  return (0);
}
