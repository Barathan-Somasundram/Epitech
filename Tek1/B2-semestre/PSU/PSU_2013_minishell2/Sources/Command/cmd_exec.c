/*
** cmd_exec.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 16:30:11 2014 somasu_b
** Last update Sun Mar  9 15:17:09 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

int	cmd_perror(char **cmd, int mod)
{
  if (mod == 0)
    {
      my_putstr(B_YELLOW "If '" B_GREEN);
      my_putstr(cmd[0]);
      my_putstr(B_YELLOW "' is not a typo you can use command-not-found"
		" to lookup the package that contains it, like this:"
		"\n    cnf " B_GREEN);
      my_putstr(cmd[0]);
      my_putstr("\n" NORMAL);
    }
  if (mod == 1)
    my_putstr("A fork error has happend\n");
  return (-1);
}

int status_analysis(int status)
{
  if (status == SIGSEGV)
    my_putstr("Segmentation fault\n");
  else if (status == SIGFPE)
    my_putstr("Floating Point Exeption\n");
  else if (status == SIGKILL)
    my_putstr("'\'Killed\n");
  else if (status == SIGPIPE)
    my_putstr("Broken Pipe\n");
  else if (status == SIGQUIT)
    my_putstr("'\'Quit\n");
  return (0);
}

static int	my_son(char **env, char **cmd, char *abs_path)
{
  int	status;
  pid_t	pid;

  if ((pid = fork()) == -1)
    return (cmd_perror(NULL, 1));
  if (pid == 0)
    {
      if (execve(abs_path, cmd, env) == -1)
	exit(EXIT_SUCCESS);
      else
	return (0);
    }
  else
    waitpid(pid, &status, 0);
  status_analysis(status);
  return (0);
}

int	my_exec_cmd(char **cmd, int mod)
{
  char	*abs_path;
  char	**env;

  env = NULL;
  if (mod == 0)
    if ((my_env_tab(&env)) == -1)
      env = NULL;
  abs_path = cmd_full_path(cmd);
  if (abs_path == NULL || (access(abs_path, F_OK)) == -1)
    return (cmd_perror(cmd, 0));
  my_son(env, cmd, abs_path);
  if (abs_path != NULL)
    free(abs_path);
  my_free_tab(&env);
  return (0);
}
