/*
** my_unsetenv.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Jan  6 19:17:46 2014 a
** Last update Mon Jan  6 19:21:49 2014 a
*/

#include "mysh.h"

int	my_unsetenv_init(char **command)
{
  if (my_strlen_tab(command) < 2)
    {
      my_putstr_error("Usage : unsetenv variable\n");
      return (-1);
    }
}

int	my_unsetenv(char **command, char ***env_sys)
{
  char	**env;
  char	*tmp;
  int	i;
  int	j;

  if (my_unsetenv_init(command) == -1)
    return (-1);
  if ((env = malloc(sizeof(char*) * (my_strlen_tab((*env_sys))))) == NULL)
    return (-1);
  i = 0;
  j = 0;
  while (i < my_strlen_tab((*env_sys)))
    {
      tmp = my_strdup(command[1]);
      tmp = my_strcat(tmp, "=");
      if ((my_strncmp((*env_sys)[i], tmp, my_strlen(command[1]))) != 0)
	env[j++] = my_strdup((*env_sys)[i]);
      i = i + 1;
    }
  env[j] = NULL;
  free(tmp);
  free_old_env(env_sys, i);
  (*env_sys) = env;
  return (0);
}
