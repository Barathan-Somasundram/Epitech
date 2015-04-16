/*
** my_cd.c for minishell2 in /home/somasu_b/rendu/work/mysh2/Sources/Built-ins
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Mar  9 18:23:44 2014 somasu_b
** Last update Sun Mar  9 18:25:26 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

static int	my_directory(char *dir, char **directory)
{
  char		*tmp;

  if (dir == NULL || my_strcmp(dir, "~") == 0)
    if ((tmp = my_get_env("HOME=")) != NULL)
      *directory = my_strdup(&tmp[5]);
    else
      tmp = NULL;
  else if (my_strcmp(dir, "-") == 0)
    if ((tmp = my_get_env("OLDPWD=")) != NULL)
      *directory = my_strdup(&tmp[7]);
    else
      tmp = NULL;
  else
    {
      if (dir[0] != '/')
	{
	  tmp = my_strdup("./");
	  *directory = my_strcat(tmp, dir);
	  free(tmp);
	}
      else
	*directory = my_strdup(dir);
    }
  return (0);
}

int	my_cd(char **cmd)
{
  char	*directory;
  int	ret;

  directory = NULL;
  my_directory(cmd[1], &directory);
  if (directory == NULL)
    return (-1);
  if (chdir(directory) == -1)
    {
      my_putstr("mysh: cd: ");
      if (directory != NULL)
	my_putstr(directory);
      my_putstr(": No such file or directory\n");
    }
  free(directory);
  return (0);
}
