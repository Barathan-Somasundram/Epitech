/*
** execute.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Dec 28 19:54:14 2013 a
** Last update Mon Jan  6 18:57:31 2014 a
*/

#include "mysh.h"

char		*find_path(char **env_path, char **command)
{
  DIR		*dirp;
  struct dirent	*dir_list;
  int		i;
  int		pos;

  i = 0;
  pos = 0;
  if (env_path == NULL)
    return (NULL);
  while (env_path[i] != NULL)
    {
      if (access(env_path[i], F_OK) == 0)
	{
	  if ((dirp = opendir(env_path[i])) == NULL)
	    return (NULL);
	  while ((dir_list = readdir(dirp)) != NULL)
	    if (my_strcmp(dir_list->d_name, command[0]) == 0)
	      return (env_path[i]);
	  if ((closedir(dirp)) == -1)
	    return (NULL);
	}
      i = i + 1;
    }
  return (NULL);
}

int	status_analyse(int status)
{
  if (status == 11)
    my_putstr("Segmentation fault\n");
  return (0);
}

int	my_son(pid_t pid, char **command, char **env, char **env_path)
{
  char	*path;

  if ((path = find_path(env_path, command)) == NULL)
    {
      if ((execve(command[0], command, env)) == -1)
	{
	  my_putstr("If '");
	  my_putstr(command[0]);
	  my_putstr("' is not a typo you can use command-not-found to lookup");
	  my_putstr("the package that contains it, like this:\n    cnf ");
	  my_putstr(command[0]);
	  my_putstr("\n");
	  exit(EXIT_SUCCESS);
	}
      else
	return (0);
    }
  path = my_strcat(path, "/");
  path = my_strcat(path, command[0]);
  if ((execve(path, command, env)) == -1)
    return (-1);
  return (0);
}

int	execute_cmd(char **command, char **env, char **env_path)
{
  pid_t	pid;
  int	status;

  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    return (my_son(pid, command, env, env_path));
  else
    waitpid(pid, &status, 0);
  status_analyse(status);
  return (0);
}
