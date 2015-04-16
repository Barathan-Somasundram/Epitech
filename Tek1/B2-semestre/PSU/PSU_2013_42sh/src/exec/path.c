/*
** path.c for 42sh in /home/somasu_b/Music/42/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu May 29 14:08:07 2014 somasu_b
** Last update Thu May 29 21:55:20 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sh.h"

static char	*strcat_path(char *bin, char *cmd)
{
  char		*path;
  int		len;

  len = strlen(bin) + strlen(cmd) + 1;
  if ((path = malloc(sizeof(char*) * len)) == NULL)
    return (NULL);
  path[0] = '\0';
  if ((path = strcat(path, bin)) == NULL)
    return (NULL);
  if ((path = strcat(path, "/")) == NULL)
    return (NULL);
  if ((path = strcat(path, cmd)) == NULL)
    return (NULL);
  return (path);
}

static char	*free_and_return(char **list, char *path)
{
  int		i;

  i = 0;
  if (list != NULL)
    {
      while (list[i])
	free(list[i++]);
      free(list);
    }
  return (path);
}

char		*sh_search_path(t_42 *sh, char *cmd)
{
  t_env		*tmp;
  char		*path;
  char		**list;
  int		i;

  tmp = sh->env->next;
  while (tmp != sh->env && strcmp(tmp->var, "PATH") != 0)
    tmp = tmp->next;
  if (tmp == sh->env)
    return (strdup(cmd));
  if ((list = my_str_to_wordtab(strdup(tmp->contents), ':')) == NULL)
    return (NULL);
  i = -1;
  while (list[++i])
    {
      if ((path = strcat_path(list[i], cmd)) == NULL)
      	return (NULL);
      if (access(path, X_OK) == 0 && access(path, F_OK) == 0)
      	return (free_and_return(list, path));
    }
  free_and_return(list, path);
  return (strdup(cmd));
}
