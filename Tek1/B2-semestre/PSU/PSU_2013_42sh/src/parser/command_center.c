/*
** command_center.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri May 16 01:40:44 2014 somasu_b
** Last update Sun Jun  1 19:50:04 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static int	isprintable(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    if (str[i] < ' ' || str[i++] > '~')
      return (-1);
  return (1);
}

static int	replace_tild(t_tok *cmd, t_env *env)
{
  char		*str;
  t_env		*tmp;

  tmp = env->next;
  while (tmp != env && strcmp("HOME", tmp->var) != 0)
    tmp = tmp->next;
  if (tmp == env)
    return (0);
  if ((str = malloc(sizeof(*str) * (strlen(cmd->cmd)
				    + strlen(tmp->contents) + 1))) == NULL)
    return (-1);
  str[0] = '\0';
  str = strcat(str, tmp->contents);
  str = strcat(str, (cmd->cmd) + 1);
  cmd->cmd = str;
  return (0);
}

static int	replace_doll(t_tok *tmp, t_42 *sh)
{
  t_env		*save;
  t_vars	*tmp2;

  save = sh->env->next;
  tmp2 = sh->vars->next;
  while (save != sh->env && strstr(tmp->cmd, save->var) == NULL)
    save = save->next;
  if (save == sh->env)
    {
      while ( tmp2 != sh->vars && strstr(tmp->cmd, tmp2->var) == NULL)
	tmp2 = tmp2->next;
      if (tmp2 != sh->vars)
	tmp->cmd = strdup(tmp2->contents);
    }
  else
    tmp->cmd = strdup(save->contents);
  return (0);
}

static int	replacing(t_42 *sh, t_tok *cmd)
{
  t_tok		*tmp;

  tmp = cmd->next;
  while (tmp != cmd)
    {
      if (tmp->cmd[0] == '~')
	if (replace_tild(tmp, sh->env) == -1)
	  return (-1);
      if (tmp->cmd[0] == '$')
	replace_doll(tmp, sh);
      tmp = tmp->next;
    }
  return (0);
}

int		command_center(t_42 *sh, char *command)
{
  t_tok		*cmd_list;
  t_tree	*cmd_tree;

  if (isprintable(command) == -1)
    return (1);
  if ((cmd_list = cmd_to_list(command)) == NULL)
    return (1);
  if (lexer(cmd_list) == -1)
    return (1);
  if (replacing(sh, cmd_list) == -1)
    return (1);
  if ((cmd_tree = parser(cmd_list)) == NULL)
    return (1);
  if (main_execution(sh, cmd_tree) == -1)
    return (-1);
  free_tree(cmd_tree);
  return (0);
}
