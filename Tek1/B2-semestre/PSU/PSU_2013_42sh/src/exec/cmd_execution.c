/*
** cmd_execution.c for 42sh in /home/somasu_b/rendu/42sh/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 15:24:52 2014 somasu_b
** Last update Sun Jun  1 23:30:10 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

static const t_built	g_builtin[] =
  {
    {"history", my_history},
    {"set", sh_set_vars},
    {"unset", sh_unset_vars},
    {"alias", sh_alias},
    {"unalias", sh_unalias},
    {"env", my_env},
    {"setenv", sh_setenv},
    {"unsetenv", sh_unsetenv},
    {"echo", sh_echo},
    {"cd", sh_cd},
    {"exit", sh_exit},
    {NULL, NULL},
  };

static int	is_builtin(t_tok *token, t_42 *sh)
{
  int		i;

  i = -1;
  while (g_builtin[++i].command != NULL)
    if (strcmp(g_builtin[i].command, token->next->cmd) == 0)
      {
	sh->exit = g_builtin[i].fct(sh, token);
	return (sh->exit);
      }
  return (2);
}

static int	killing_stop(t_42 *sh, t_tok *token, int len, int i)
{
  t_tok		*tmp;
  char		*str;
  int		sig;

  tmp = token->next;
  if (i == 1 && len == 2)
    if (strcmp(tmp->next->cmd, "0") == 0)
      {
	fprintf(stderr, "42sh : Terminated\n");
	return (1);
      }
  if (len != 3)
    return (0);
  if (i == 1 && strcmp(token->prev->cmd, "0") == 0)
    {
      if ((sig = my_getnbr(token->prev->prev->cmd)) < 0 && sig >= -33)
      	if ((str = strsignal(-sig)) == NULL)
      	  return (-1);
      if (sig >= 0)
      	return (0);
      fprintf(stderr, "%s\n", str);
      sh->exit = 1;
      return (1);
    }
  return (0);
}

static int	check_kill(t_42 *sh, t_tok *token)
{
  t_tok		*tmp;
  int		ret;
  int		len;
  int		i;

  i = 0;
  len = 0;
  tmp = token->next;
  while (tmp != token)
    {
      tmp = tmp->next;
      len++;
    }
  tmp = token->next;
  if (strcmp(tmp->cmd, "kill") == 0 || strcmp(tmp->cmd, "/bin/kill") == 0
      || strcmp(tmp->cmd, "/usr/bin/kill") == 0)
    i = 1;
  if ((ret = killing_stop(sh, token, len, i)) == 1 || ret == -1)
    return (ret);
  return (0);
}

int		cmd_execution(t_42 *sh, t_tok *token)
{
  int		ret;

  if (token->next == token)
    return (0);
  if ((ret = background(sh, token)) == -1)
    return (-1);
  if (ret == 0)
    {
      if ((ret = is_builtin(token, sh)) != 2)
	return (ret);
      if ((ret = check_kill(sh, token)) == 1 || ret == -1)
	return (ret);
      return (execve_main(token, sh));
    }
  return (1);
}
