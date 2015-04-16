/*
** env_tools.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 21:46:33 2014 somasu_b
** Last update Sun Mar  9 21:43:45 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../Includes/my_string.h"
#include "../Includes/mysh.h"

char		*my_get_env(char *elem)
{
  t_list	*tmp;
  char		*vars;
  int		length;

  length = my_strlen(elem) - 2;
  tmp = g_mysh.my_env;
  while (tmp != NULL && (my_strncmp(tmp->var, elem, length)) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (NULL);
  return (tmp->var);
}

char	**my_get_path(void)
{
  char	**path;
  char	*path_var;

  path_var = my_get_env("PATH=");
  if (path_var == NULL)
    return (NULL);
  else
    path = my_str_to_wordtab(&path_var[5], ":");
  return (path);
}

char	*my_get_hostname(void)
{
  char	*pc_name;

  pc_name = my_get_env("HOSTNAME=");
  if (pc_name == NULL)
    return (NULL);
  pc_name = my_strdup(&(pc_name[9]));
  if (pc_name == NULL)
    return (NULL);
  return (pc_name);
}

char	*my_get_name(void)
{
  char	*name;

  name = my_get_env("NAME=");
  if (name == NULL)
    return (NULL);
  name = my_strdup(&(name[5]));
  if (name == NULL)
    return (NULL);
  return (name);
}

char	*my_get_pwd(void)
{
  char	*pwd;

  pwd = my_get_env("PWD=");
  if (pwd == NULL)
    return (NULL);
  pwd = my_strdup(&(pwd[4]));
  if (pwd == NULL)
    return (NULL);
  return (pwd);
}
