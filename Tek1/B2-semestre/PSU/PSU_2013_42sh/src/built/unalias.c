/*
** unalias.c for 42sh in /home/somasu_b/rendu/mysh/src/built
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat May 24 16:37:49 2014 somasu_b
** Last update Sun Jun  1 18:51:28 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

static int	rm_alias(t_alias **alias, t_alias *to_rm)
{
  t_alias	*tmp;

  if (*alias == to_rm)
    (*alias) = (*alias)->next;
  else
    {
      tmp = *alias;
      while (tmp->next != to_rm)
	tmp = tmp->next;
      tmp->next = to_rm->next;
    }
  return (0);
}

int		sh_unalias(t_42 *sh, t_tok *token)
{
  t_alias	*tmp_ali;
  t_tok		*tmp_tok;

  tmp_tok = token->next->next;
  if (tmp_tok == token)
    {
      fprintf(stderr, "42sh: unalias: error: no parameter\n");
      return (0);
    }
  while (tmp_tok != token)
    {
      tmp_ali = sh->alias;
      while (tmp_ali != NULL)
	{
	  if (strcmp(tmp_ali->var, tmp_tok->cmd) == 0)
	    rm_alias(&sh->alias, tmp_ali);
	  tmp_ali = tmp_ali->next;
	}
      tmp_tok = tmp_tok->next;
    }
  return (1);
}
