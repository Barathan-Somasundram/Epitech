/*
** cmd_pipe.c for minishell2 in /home/somasu_b/rendu/work/mysh2/Sources/Command
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Mar  9 17:47:50 2014 somasu_b
** Last update Sun Mar  9 21:41:50 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

static my_son2(int pipes, int fds[2], char **env, char **cmd)
{
  char	*abs_path;

  abs_path = cmd_full_path(cmd);
  if (pipes == 1)
    {
      close(fds[0]);
      dup2(fds[1], 1);
      close(fds[1]);
    }
  if (pipes == 2)
    {
      close(fds[1]);
      dup2(fds[0], 0);
      close(fds[0]);
    }
  if (execve(abs_path, cmd, env) == -1)
    exit(EXIT_SUCCESS);
  else
    return (0);
}

static int	my_son(char **env, char **cmd, int fds[2], int pipes)
{
  int	status;
  pid_t	pid;

  if ((pid = fork()) == -1)
    return (cmd_perror(NULL, 1));
  if (pid == 0)
    return (my_son2(pipes, fds, env, cmd));
  else
    {
      if (pipes == 2)
	{
	  close(fds[0]);
	  close(fds[1]);
	}
      waitpid(pid, &status, 0);
    }
  status_analysis(status);
  return (0);
}

int	exec_pipe(char **cmd)
{
  char	**cmds;
  char	**env;
  int	fds[2];

  if (pipe(fds) != 0)
    {
      my_putstr("pipe error\n");
      return (-1);
    }
  if (my_env_tab(&env) == -1)
    env = NULL;
  cmds = my_str_to_wordtab(cmd[0], " ");
  if (!cmd || !cmd[0])
    return (-1);
  my_son(env, cmds, fds, 1);
  cmds = my_str_to_wordtab(cmd[1], " ");
  if (!cmd || !cmd[0])
    return (-1);
  my_son(env, cmds, fds, 2);
  close(fds[0]);
  close(fds[1]);
  my_free_tab(&env);
  return (0);
}
