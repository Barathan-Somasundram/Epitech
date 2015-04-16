/*
** alias.c for 42sh in /home/somasu_b/rendu/mysh/src/built
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat May 24 15:52:09 2014 somasu_b
** Last update Thu May 29 21:52:54 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

static int	args_counter(t_tok *token)
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

static int	check_alias(t_alias *alias, t_tok *token)
{
  t_alias	*tmp;
  int		rett;
  char		*ret;

  rett = 1;
  tmp = alias;
  while (tmp != NULL)
    {
      if (strcmp(tmp->var, token->cmd) == 0)
	rett = 0;
      tmp = tmp->next;
    }
  tmp = alias;
  while (tmp != NULL)
    {
      if ((ret = strstr(tmp->contents, token->cmd)) != NULL)
	if (*(ret - 1) == ' ' && (ret[strlen(tmp->contents)] == '\0'
				  || ret[strlen(tmp->contents)] == ' '))
	  rett = 0;
      tmp = tmp->next;
    }
  if (rett == 0)
    fprintf(stderr, "42sh: alias: error: can loop or already exist\n");
  return (rett);
}

static int	put_in_alias(t_alias **alias, t_tok *token)
{
  t_alias	*elem;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((elem->var = strdup(token->cmd)) == NULL)
    return (-1);
  if ((elem->contents = strdup(token->next->cmd)) == NULL)
    return (-1);
  elem->next = *alias;
  (*alias) = elem;
  return (0);
}

int		sh_alias(t_42 *sh, t_tok *token)
{
  t_alias	*tmp;
  int		ac;

  tmp = sh->alias;
  ac = args_counter(token);
  if (ac == 1)
    {
      while (tmp != NULL)
	{
	  printf("%s\t%s\n", tmp->var, tmp->contents);
	  tmp = tmp->next;
	}
      return (1);
    }
  else if (ac != 3)
    {
      fprintf(stderr, "42sh: alias: error only 2 arguments\n");
      return (0);
    }
  if (check_alias(sh->alias, token->next->next) == 0)
    return (0);
  if (put_in_alias(&sh->alias, token->next->next) == -1)
    return (-1);
  return (1);
}
