/*
** init_env.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed May 14 22:00:12 2014 somasu_b
** Last update Thu May 29 21:56:06 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static int	locate_sep(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i] && str[i] != '=')
      ++i;
  return (i);
}

static int	put_in_list(t_env **env, char *part)
{
  t_env		*elem;
  int		sep;

  sep = 0;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  sep = locate_sep(part);
  if ((elem->var = strndup(part, sep)) == NULL)
    return (-1);
  elem->contents = NULL;
  if (part[sep + 1] != '\0')
    if ((elem->contents = strdup(part + sep + 1)) == NULL)
      return (-1);
  elem->prev = (*env)->prev;
  elem->next = (*env);
  (*env)->prev->next = elem;
  (*env)->prev = elem;
  return (0);
}

int		sh_env(char **env, t_42 *sh)
{
  int		i;

  if ((sh->env = malloc(sizeof(t_env))) == NULL)
    return (-1);
  sh->env->prev = sh->env;
  sh->env->next = sh->env;
  if (env != NULL)
    {
      i = -1;
      while (env[++i])
	if (put_in_list(&(sh->env), env[i]) == -1)
	  return (-1);
    }
  return (0);
}
