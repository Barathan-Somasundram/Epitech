/*
** my_setenv.c for built_in in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 23:05:38 2014 somasu_b
** Last update Sun Mar  9 18:20:45 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

static int		mod_env(char **cmd, char **vars)
{
  t_list		*tmp;
  int			length;

  if (*vars == NULL)
    return (-1);
  tmp = g_mysh.my_env;
  length = my_strlen(cmd[1]) - 2;
  while (tmp != NULL && (my_strncmp(tmp->var, cmd[1], length)) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (0);
  else
    {
      free(tmp->var);
      if ((tmp->var = my_strdup(*vars)) == NULL)
	return (-1);
      return (1);
    }
  return (0);
}

int	my_setenv(char **cmd)
{
  char	*vars;
  char	*tmp;
  int	ret;

  if (cmd[1] == NULL || cmd[2] == NULL)
    {
      my_putstr("Usage: setenv [variable] [contents]\n");
      return (-1);
    }
  vars = my_strcat(cmd[1], "=");
  tmp = my_strcat(vars, cmd[2]);
  if (vars != NULL)
    free(vars);
  vars = my_strdup(tmp);
  if (tmp != NULL)
    free(tmp);
  if ((ret = mod_env(cmd, &vars)) == -1)
    return (-1);
  if (ret != 1)
  my_put_in_list(&(g_mysh.my_env), vars);
  if (vars != NULL)
    free(vars);
  return (0);
}
