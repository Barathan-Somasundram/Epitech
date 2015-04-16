/*
** cmd_center.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 16:09:19 2014 somasu_b
** Last update Sun Mar  9 18:08:52 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

static int	my_built_ins(char **cmd, char **multi_cmd)
{
  if (my_strcmp(cmd[0], "cd") == 0)
    return (my_cd(cmd));
  else if (my_strcmp(cmd[0], "env") == 0)
    return (my_env(cmd));
  else if (my_strcmp(cmd[0], "exit") == 0)
    return (my_exit(cmd, multi_cmd));
  else if (my_strcmp(cmd[0], "setenv") == 0)
    return (my_setenv(cmd));
  else if (my_strcmp(cmd[0], "unsetenv") == 0)
    return (my_unsetenv(cmd));
  else
    return (my_exec_cmd(cmd, 0));
  return (0);
}

static bis(char **multi_cmd, int i)
{
  char	**cmd;
  int	ret;

  ret = chk_pipe(multi_cmd[i]);
  if (ret > 1)
    {
      my_putstr("mysh can not handle multiple pipe,"
		" multiple redirection ...\n");
    }
  else if (ret == 0)
    {
      cmd = my_str_to_wordtab(multi_cmd[i] , " ");
      if (cmd != NULL && cmd[0])
	my_built_ins(cmd, multi_cmd);
      my_free_tab(&cmd);
    }
  else if (ret == 1)
    want_pipe_or_redir(multi_cmd[i]);
  return (0);
}

static int	exec_multi_cmd(char **multi_cmd)
{
  char	**cmd;
  char	**cmd_pipe;
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  g_mysh.counter++;
  while (multi_cmd[i] != NULL)
    {
      bis(multi_cmd, i);
      i++;
    }
  return (0);
}

int	cmd_center(void)
{
  char	*buffer;
  char	**cmd;
  int	i;

  i = 0;
  if ((buffer = get_next_line(0)) == NULL)
    return (-1);
  if (buffer[0] == '\0')
    {
      free(buffer);
      return (0);
    }
  cmd = my_str_to_wordtab(buffer, ";");
  free(buffer);
  if (cmd && cmd[0])
    exec_multi_cmd(cmd);
  my_free_tab(&cmd);
  return (0);
}
