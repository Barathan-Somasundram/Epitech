/*
** lexer.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri May 16 12:51:18 2014 somasu_b
** Last update Thu May 29 21:56:39 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sh.h"

static const t_type	g_tab[] =
  {
    {REDIR_RIGHT1, TYPE_RIGHT1},
    {REDIR_RIGHT2, TYPE_RIGHT2},
    {REDIR_LEFT1, TYPE_LEFT1},
    {REDIR_LEFT2, TYPE_LEFT2},
    {PIPE, TYPE_PIPE},
    {AND, TYPE_AND},
    {OR, TYPE_OR},
    {SEP, TYPE_SEP},
    {BG, TYPE_BG},
    {NULL, TYPE_ARG}
  };

static int	print_error(t_tok *token, t_tok *tmp)
{
  if (tmp->prev == token || tmp->prev->type != TYPE_ARG)
    {
      fprintf(stderr, "42sh: syntax error near unexpected token \'%s\'\n",
	      tmp->cmd);
      return (-1);
    }
  if (tmp->prev == token ||
      (tmp->type != TYPE_SEP && tmp->next->type != TYPE_ARG))
    {
      fprintf(stderr, "42sh: Invalid null command\n");
      return (-1);
    }
  return (0);
}

static int	missing(t_tok *token)
{
  t_tok		*tmp;

  tmp = token->next;
  while (tmp != token)
    {
      while (tmp != token && tmp->type != TYPE_RIGHT1
	     && tmp->type != TYPE_RIGHT2 && tmp->type != TYPE_LEFT1
	     && tmp->type != TYPE_LEFT2)
	tmp = tmp->next;
      if (tmp != token && (tmp->next == token || tmp->next->type != TYPE_ARG))
	{
	  fprintf(stderr, "42sh: missing name for redirect.\n");
	  return (-1);
	}
      if (tmp != token)
	tmp = tmp->next;
    }
  return (0);
}

static int	syntax(t_tok *token)
{
  t_tok		*tmp;

  tmp = token->next;
  while (tmp != token)
    {
      while (tmp != token
	     && (tmp->type != TYPE_SEP && tmp->type != TYPE_PIPE
		 && tmp->type != TYPE_AND && tmp->type != TYPE_OR))
      	tmp = tmp->next;
      if (tmp != token)
	if (print_error(token, tmp) == -1)
	  return (-1);
      if (tmp != token)
	tmp = tmp->next;
    }
  if (missing(token) == -1)
    return (-1);
  return (0);
}

int		lexer(t_tok *cmd_list)
{
  t_tok		*tmp;
  int		i;

  tmp = cmd_list->next;
  while (tmp != cmd_list)
    {
      i = 0;
      while (g_tab[i].sep != NULL
	     && strcmp(tmp->cmd, g_tab[i].sep) != 0)
	++i;
      tmp->type = g_tab[i].type;
      tmp = tmp->next;
    }
  if (syntax(cmd_list) == -1)
    return (-1);
  return (0);
}
