/*
** cmd_parse.c for minishell2 in /home/somasu_b/rendu/work/mysh2/Sources/Command
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Mar  9 13:31:00 2014 somasu_b
** Last update Sun Mar  9 18:05:43 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

int	chk_pipe(char *cmd)
{
  int	is_pipe;
  int	i;

  is_pipe = 0;
  i = 0;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '|')
	++is_pipe;
      ++i;
    }
  return (is_pipe);
}

int	chk_one_w(char *cmd)
{
  int	one_w;
  int	i;

  one_w = 0;
  i = 0;
  while (cmd[i] != '\0')
    {
      if (cmd[i] != '\0' && cmd[i] == '>' && cmd[i + 1] != '>'
	  && cmd[i + 1] != '<')
	++one_w;
      ++i;
    }
  return (one_w);
}

int	chk_two_w(char *cmd)
{
  int	two_w;
  int	i;

  two_w = 0;
  i = 0;
  while (cmd[i] != '\0')
    {
      if (cmd[i] != '\0' && cmd[i] == '>' && cmd[i + 1] == '>'
	  && cmd[i + 1] != '<')
      ++i;
    }
  return (two_w);
}

int	want_pipe_or_redir(char *cmd)
{
  char	**cmds;

  if (chk_pipe(cmd) == 1)
    {
      cmds = my_str_to_wordtab(cmd, "|");
      return (exec_pipe(cmds));
    }
  return (0);
}
