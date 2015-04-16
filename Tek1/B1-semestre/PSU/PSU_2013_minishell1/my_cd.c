/*
** my_cd.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Dec 26 23:02:39 2013 a
** Last update Sat Dec 28 20:01:21 2013 a
*/

#include "mysh.h"

char	*my_directory(char **command, char **env, char *oldpwd, char *home)
{
  char	*directory;

  directory = NULL;
  if (command[1] == NULL)
    directory = my_strdup(home);
  else if ((my_strcmp(command[1], "~")) == 0)
    directory = my_strdup(home);
  else if ((my_strcmp(command[1], "-")) == 0)
    directory = my_strdup(oldpwd);
  else
    {
      if (command[1][0] != '/')
	{
	  directory = my_strdup("./");
	  directory = my_strcat(directory, command[1]);
	}
      else
	directory = my_strdup(command[1]);
    }
  return (directory);
}

int	my_cd(char **command, char **env)
{
  char	*directory;
  char	*oldpwd;
  char	*home;
  int	ret;

  oldpwd = NULL;
  home = NULL;
  if (my_home(env) != -1)
      home = my_strdup(&env[my_home(env)][5]);
  if (my_oldpwd(env) != -1)
    oldpwd = my_strdup(&env[my_oldpwd(env)][7]);
  directory = my_directory(command, env, oldpwd, home);
  ret = chdir(directory);
  if (ret == -1)
    {
      my_putstr("bash: cd: ");
      if (directory != NULL)
  	my_putstr(directory);
      my_putstr(": No such file or directory\n");
    }
  free(directory);
  return (ret);
}
