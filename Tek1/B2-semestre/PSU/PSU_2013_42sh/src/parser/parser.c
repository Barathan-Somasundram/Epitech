/*
** parser.c for 42sh in /home/somasu_b/rendu/mysh/src/parser
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri May 16 22:40:40 2014 somasu_b
** Last update Fri May 30 19:35:31 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

static const int	g_tab[] =
  {
    TYPE_SEP,
    TYPE_OR,
    TYPE_AND,
    TYPE_PIPE,
    0
  };

static int	under_tree(t_tok **token, t_cmd *cmd, int type)
{
  if (init_tree(&(cmd->tree), type) == -1)
    return (-1);
  if (parse_token(&cmd->tree, cmd->token, type) == -1)
    return (-1);
  *token = cmd->token->prev;
  return (0);
}

static int	is_under_tree(t_cmd *cmd, int nb)
{
  t_cmd		*tmp_cmd;
  t_tok		*tmp_tok;
  int		i;

  tmp_cmd = cmd->next;
  while (tmp_cmd != cmd)
    {
      i = nb - 1;
      while (g_tab[++i] != 0)
	{
	  tmp_tok = tmp_cmd->token->next;
	  while (tmp_tok != tmp_cmd->token)
	    {
	      if (tmp_tok->type == g_tab[i])
		{
		  if (under_tree(&tmp_tok, tmp_cmd, g_tab[i]) == -1)
		    return (-1);
		  i = 5;
		}
	      tmp_tok = tmp_tok->next;
	    }
	}
      tmp_cmd = tmp_cmd->next;
    }
  return (0);
}

int		parse_token(t_tree **tree, t_tok *token, int type)
{
  t_tok		*tmp1;
  t_tok		*tmp2;
  int		i;

  tmp1 = token->next;
  while (tmp1 != token)
    {
      tmp2 = tmp1;
      while (tmp2 != token && tmp2->type != type)
	tmp2 = tmp2->next;
      if (add_elem(tree, tmp1) == -1)
	return (-1);
      if (tmp2 == token)
	tmp1 = tmp2;
      else
	tmp1 = tmp2->next;
    }
  i = 0;
  while (g_tab[i] != type)
    ++i;
  if (epur_token((*tree)->cmd, token, g_tab[i]) == -1)
    return (-1);
  if (is_under_tree((*tree)->cmd, i) == -1)
    return (-1);
  return (0);
}

t_tree		*parser(t_tok *cmd_list)
{
  t_tree	*tree;

  if (init_tree(&tree, TYPE_SEP) == -1)
    return (NULL);
  if (parse_token(&tree, cmd_list, TYPE_SEP) == -1)
    return (NULL);
  epur_tree(tree);
  return (tree);
}
