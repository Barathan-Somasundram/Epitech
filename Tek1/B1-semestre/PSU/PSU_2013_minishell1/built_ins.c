/*
** built_ins.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 25 15:38:08 2013 a
** Last update Mon Jan  6 19:18:10 2014 a
*/

#include "mysh.h"

char	**my_strcpy_env(char **new_env, char **env, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      new_env[i] = my_strdup(env[i]);
      i = i + 1;
    }
  new_env[i] = NULL;
  return (new_env);
}

int	my_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      my_putstr(env[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}

int	my_exit(char **command, char **env, char **path, char *buffer)
{
  garbage(command, path, buffer);
  free_env(env);
  exit(EXIT_SUCCESS);
  return (0);
}

void	free_old_env(char ***env_sys, int i)
{
  while (i > 0)
    free((*env_sys)[i--]);
  free((*env_sys));
}

int	my_setenv(char **command, char ***env_sys)
{
  char  **env;
  char	*var;
  int	i;

  if (my_strlen_tab(command) < 2)
    {
      my_putstr_error("Usage : setenv variable\n");
      return (-1);
    }
  if ((env = malloc(sizeof(char*) * (my_strlen_tab((*env_sys)) + 2))) == NULL)
    return (-1);
  i = 0;
  while (i < my_strlen_tab((*env_sys)))
    env[i++] = my_strdup((*env_sys)[i]);
  env[i] = my_strdup(command[1]);
  env[i] = my_strcat(env[i], "=");
  if (command[2] != NULL)
    if (my_strlen(command[2]) < 18)
      env[i] = my_strcat(env[i], command[2]);
  my_putstr(env[i]);
  env[i + 1] = NULL;
  free_old_env(env_sys, i);
  (*env_sys) = env;
  return (0);
}
