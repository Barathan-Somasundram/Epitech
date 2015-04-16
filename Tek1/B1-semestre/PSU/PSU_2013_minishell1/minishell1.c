/*
** minishell1.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 24 20:33:01 2013 a
** Last update Mon Jan  6 18:32:12 2014 a
*/

#include "mysh.h"

void	garbage(char **command, char **path, char *buffer)
{
  if (command != NULL)
    free(command[0]);
  if (path != NULL)
    free(path[0]);
  if (command != NULL)
    free(command);
  if (path != NULL)
    free(path);
  free(buffer);
}

void	free_env(char **env)
{
  int	i;

  i = 0;
  if (env != NULL)
    {
      while (env[i] != NULL)
	free(env[i++]);
      free(env);
    }
}

int	my_built_ins(char **command, char ***env, char **path, char *buffer)
{
  if (command == NULL)
    return (-1);
  else if ((my_strncmp(command[0], "cd", 2)) == 0)
    return (my_cd(command, *env));
  else if ((my_strncmp(command[0], "env", 3)) == 0)
    return (my_env(*env));
  else if ((my_strncmp(command[0], "exit", 4)) == 0)
    return (my_exit(command, *env, path, buffer));
  else if ((my_strncmp(command[0], "setenv", 6)) == 0)
    return (my_setenv(command, env));
  else if ((my_strncmp(command[0], "unsetenv", 8)) == 0)
    return (my_unsetenv(command, env));
  else
    return (execute_cmd(command, *env, path));
  return (-1);
}

int	read_cmd(char **command, char **path, char ***env)
{
  char	*buffer;
  int	ret;

  if ((buffer = malloc(sizeof(char) * (BUF_LEN + 1))) == NULL)
    return (-1);
  if ((ret = read(0, buffer, BUF_LEN)) > 0)
    {
      if (buffer[0] == '\0')
	{
	  garbage(command, path, buffer);
	  return (-2);
	}
      buffer[ret - 1] = '\0';
      if (buffer[0] != 0)
      	{
	  command = my_str_to_wordtab(buffer, ' ');
	  if (env != NULL && path_pos(*env) != -1)
	    path = my_str_to_wordtab(&((*env)[path_pos(*env)][5]), ':');
	  my_built_ins(command, env, path, buffer);
	  garbage(command, path, buffer);
	}
      return (1);
    }
  return (0);
}

int	minishell1(char **env)
{
  char	**path;
  char	**command;
  int	ret;

  my_putstr("\r$> ");
  path = NULL;
  command = NULL;
  my_signal();
  ret = read_cmd(command, path, &env);
  if (ret <= 0)
    {
      if (ret == 0 || ret == -2)
	my_putchar('\n');
      free_env(env);
      return (0);
    }
  minishell1(env);
  return (0);
}
