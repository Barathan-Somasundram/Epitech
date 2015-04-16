/*
** set.c for 42sh in /home/somasu_b/rendu/42sh/src/built/o
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 18:56:41 2014 somasu_b
** Last update Thu May 29 21:53:53 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sh.h"

static int	check_variable_or_show(char *cmd, t_vars *vars)
{
  t_vars	*tmp;

  if (cmd != NULL)
    if ((cmd[0] >= 'A' && cmd[0] <= 'Z')
      || (cmd[0] >= 'a' && cmd[0] <= 'z'))
      return (1);
  if (vars != NULL)
    {
      tmp = vars->next;
      while (tmp != vars)
	{
	  printf("%s\t%s\n", tmp->var, tmp->contents);
	  tmp = tmp->next;
	}
    }
  return (0);
}

static t_vars	*is_var_here_set(t_vars *vars, t_tok *tmp)
{
  t_vars	*tmp_var;
  int		i;

  i = 0;
  while (tmp->cmd[i] && tmp->cmd[i] != '=')
    ++i;
  tmp_var = vars->next;
  while (tmp_var != vars)
    {
      if (strncmp(tmp->cmd, tmp_var->var, i) == 0)
	return (tmp_var);
      tmp_var = tmp_var->next;
      tmp = tmp->next;
    }
  return (NULL);
}

static int	up_to_date(t_tok *tmp, t_vars *elem)
{
  int		i;

  i = 0;
  while (tmp->cmd[i] && tmp->cmd[i] != '=')
    ++i;
  if (tmp->cmd[i] != '\0')
    ++i;
  free(elem->contents);
  if ((elem->contents = strdup(tmp->cmd + i)) == NULL)
    return (-1);
  return (0);
}

static int	add_new_var(t_vars *vars, t_tok *tmp)
{
  t_vars	*elem;
  int		i;

  i = 0;
  while (tmp->cmd[i] && tmp->cmd[i] != '=')
    ++i;
  if (tmp->cmd != NULL)
    {
      tmp->cmd[i] = '\0';
      ++i;
    }
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((elem->var = strdup(tmp->cmd)) == NULL
      || (elem->contents = strdup(tmp->cmd + i)) == NULL)
    return (-1);
  elem->prev = vars->prev;
  elem->next = vars;
  vars->prev->next = elem;
  vars->prev = elem;
  return (0);
}

int		sh_set_vars(t_42 *sh, t_tok *token)
{
  t_tok		*tmp;
  t_vars	*elem;

  tmp = token->next->next;
  while (tmp != token)
    {
      if (check_variable_or_show(tmp->cmd, NULL) == 0)
	{
	  if ((elem = is_var_here_set(sh->vars, tmp)) != NULL
	      && up_to_date(tmp, elem) == -1)
	    return (-1);
	  else if (elem == NULL)
	    if (add_new_var(sh->vars, tmp) == -1)
	      return (-1);
	}
      else
	{
	  fprintf(stderr, "42sh: variable: Should begin with a letter\n");
	  return (0);
	}
      tmp = tmp->next;
    }
  if (token->next->next == token)
    check_variable_or_show(NULL, sh->vars);
  return (1);
}
