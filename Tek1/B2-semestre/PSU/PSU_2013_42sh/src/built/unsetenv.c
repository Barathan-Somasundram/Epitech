/*
** unsetenv.c for 42sh in /home/somasu_b/rendu/42sh/src/built/o
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 09:34:40 2014 somasu_b
** Last update Thu May 29 21:54:06 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

static int	rm_var_env(t_42 *sh, char *var)
{
  t_env		*tmp;

  tmp = sh->env->next;
  while (tmp != sh->env)
    {
      if (strcmp(tmp->var, var) == 0)
	{
	  tmp->prev->next = tmp->next;
	  tmp->next->prev = tmp->prev;
	  free(tmp->var);
	  if (tmp->contents)
	    free(tmp->contents);
	  free(tmp);
	  return (1);
	}
      tmp = tmp->next;
    }
  fprintf(stderr, "42sh: unsetenv: error: does not exist\n");
  return (0);
}

int		sh_unsetenv(t_42 *sh, t_tok *token)
{
  t_tok		*tmp;

  tmp = token->next->next;
  if (tmp == token)
    {
      fprintf(stderr, "42sh: unsetenv: error: arguments\n");
      return (0);
    }
  while (tmp != token)
    {
      if (rm_var_env(sh, tmp->cmd) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (1);
}
