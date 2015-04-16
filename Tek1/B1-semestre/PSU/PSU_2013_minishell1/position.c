/*
** position.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Dec 28 20:00:56 2013 a
** Last update Sat Dec 28 20:01:47 2013 a
*/

#include "mysh.h"

int	path_pos(char **env)
{
  int	pos;

  pos = 0;
  while (env[pos] != NULL)
    {
      if (env[pos][0] == 'P' && env[pos][1] == 'A' &&
	  env[pos][2] == 'T' && env[pos][3] == 'H')
	return (pos);
      pos = pos + 1;
    }
  return (-1);
}

int	my_home(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "HOME=", 4) == 0)
	return (i);
      i = i + 1;
    }
  return (-1);
}

int	my_oldpwd(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "OLDPWD=", 7) == 0)
	return (i);
      i = i + 1;
    }
  return (-1);
}
