/*
** cmd_path.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 21:35:59 2014 somasu_b
** Last update Mon Mar  3 18:01:12 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

static char	*strcat_cmd(char *path, char *cmd)
{
  char		*fullpath;
  char		*tmp;

  if ((fullpath = my_strcat(path, "/")) == NULL)
    return (NULL);
  if ((tmp = my_strcat(fullpath, cmd)) == NULL)
    return (NULL);
  free(fullpath);
  if ((fullpath = my_strdup(tmp)) == NULL)
    return (NULL);
  free(tmp);
  return (fullpath);
}

char	*cmd_full_path(char **cmd)
{
  char	*fullpath;
  char	**path;
  int	i;

  i = 1;
  if ((path = my_get_path()) == NULL)
    return (NULL);
  if (path && path[0])
    {
      fullpath = strcat_cmd(path[0], cmd[0]);
      while ((access(fullpath, F_OK)) == -1)
	{
	  if (fullpath != NULL)
      	free(fullpath);
	  if (path[i] == NULL)
	    return ((fullpath = my_strdup(cmd[0])));
	  fullpath = strcat_cmd(path[i++], cmd[0]);
	}
    }
  my_free_tab(&path);
  return (fullpath);
}
