/*
** setenv.c for 42sh in /home/somasu_b/rendu/42sh/src/built/o
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 09:16:45 2014 somasu_b
** Last update Sun Jun  1 23:25:34 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

static int	arg_counter(t_tok *token)
{
  t_tok		*tmp;
  int		i;

  i = 0;
  tmp = token->next;
  while (tmp != token)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}

static int	check_env(t_42 *sh, char *var)
{
  t_env		*tmp;

  tmp = sh->env->next;
  while (tmp != sh->env)
    {
      if (strcmp(tmp->var, var) == 0)
	{
	  fprintf(stderr, "42sh: setenv: already exist\n");
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

static int	add_to_env(t_42 *sh, t_tok *token)
{
  t_env		*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->var = strdup(token->next->next->cmd);
  elem->contents = NULL;
  if (token->next->next->next != token)
    if ((elem->contents = strdup(token->next->next->next->cmd))
	== NULL)
      return (-1);
  if (elem->var == NULL)
    return (-1);
  elem->prev = sh->env->prev;
  elem->next = sh->env;
  sh->env->prev->next = elem;
  sh->env->prev = elem;
  return (0);
}

int		sh_setenv(t_42 *sh, t_tok *token)
{
  t_tok		*tmp;
  int		ac;

  (void)tmp;
  ac = arg_counter(token);
  if (ac > 3 || ac == 1)
    {
      fprintf(stderr, "42sh: setenv: error: arguments\n");
      return (0);
    }
  if (check_env(sh, token->next->next->cmd) != -1
      && add_to_env(sh, token) == -1)
    return (-1);
  return (1);
}
