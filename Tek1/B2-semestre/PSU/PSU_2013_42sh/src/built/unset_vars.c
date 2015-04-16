/*
** unset_vars.c for 42sh in /home/somasu_b/rendu/42sh/src/built/o
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 19:31:32 2014 somasu_b
** Last update Thu May 29 21:54:11 2014 somasu_b
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "sh.h"

static t_vars	*is_var_here_unset(t_vars *vars, t_tok *tmp)
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

static int	rm_vars(t_vars *vars)
{
  if (vars->contents != NULL)
    free(vars->contents);
  if (vars->var != NULL)
    free(vars->var);
  vars->prev->next = vars->next;
  vars->next->prev = vars->prev;
  free(vars);
  return (0);
}

int		sh_unset_vars(t_42 *sh, t_tok *token)
{
  t_tok		*tmp;
  t_vars	*vars;

  (void)sh;
  tmp = token->next->next;
  while (tmp != token)
    {
      if ((vars = is_var_here_unset(vars, tmp)) != NULL)
	rm_vars(vars);
      tmp = tmp->next;
    }
  return (1);
}
