/*
** execve.c for 42sh in /home/somasu_b/Music/PSU_2013_42sh/PSU_2013_42sh/src/exec
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Jun  1 16:20:05 2014 a
** Last update Sun Jun  1 19:08:37 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "sh.h"

static void	sh_signal_son(void)
{
  signal(SIGINT, SIG_DFL);
  signal(SIGQUIT, SIG_DFL);
  signal(SIGTSTP, SIG_DFL);
}

static int	sh_wait_exit(pid_t son, t_42 *sh)
{
  char		*sigstr;
  int		status;

  if (sh->end_pipe == 0)
    {
      if (waitpid(son, &status, 0) == -1)
	return (-1);
      if (WIFEXITED(status) == 0)
	{
	  if ((sigstr = strsignal(status)) == NULL)
	    return (-1);
	  fprintf(stderr, "%s\n", sigstr);
	  sh->exit = 0;
	}
    }
  sh->exit = 1;
  return (0);
}

static int	sh_execve(char *path, char **cmd, char **env, t_42 *sh)
{
  pid_t		son;

  if (access(path, X_OK) == -1)
    {
      fprintf(stderr, "If \'%s\' is not a typo you can use command-not-found "
	      "to lookup the package that contains it, like this\n    cnf %s\n"
	      , cmd[0], cmd[0]);
      sh->exit = 0;
      return (0);
    }
  if ((son = fork()) == -1)
    return (-1);
  if (son == 0)
    {
      sh_signal_son();
      if (execve(path, cmd, env) == -1)
	return (-1);
    }
  else
    if (sh_wait_exit(son, sh) == -1)
      return (-1);
  return (0);
}

int		execve_main(t_tok *token, t_42 *sh)
{
  char		**env;
  char		**cmd;
  char		*path;
  int		i;

  if ((env = env_to_tab(sh->env)) == NULL)
    return (-1);
  if ((path = sh_search_path(sh, token->next->cmd)) == NULL)
    return (-1);
  if ((cmd = tok_to_tab(token)) == NULL)
    return (-1);
  if (cmd[0][strlen(cmd[0]) - 1] == '&')
    cmd[0][strlen(cmd[0]) - 1] = '\0';
  if (sh_execve(path, cmd, env, sh) == -1)
    return (-1);
  free(path);
  i = -1;
  while (cmd && cmd[++i])
    free(cmd[i]);
  i = -1;
  while (env && env[++i])
    free(env[i]);
  return (0);
}
