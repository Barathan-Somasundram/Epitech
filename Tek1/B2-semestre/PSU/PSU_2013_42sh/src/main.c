/*
** main.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed May 14 20:25:04 2014 somasu_b
** Last update Sun Jun  1 23:39:47 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "sh.h"

static int    	sh_args(int ac, char **av)
{
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  if (ac != 1)
    {
      fprintf(stderr, "sh: error: %s: No such file or directory\n", av[1]);
      return (-1);
    }
  return (0);
}

static int	ls_grep_color(t_42 *sh)
{
  char		*grep1;
  char		*grep2;
  char		*ls;

  if ((ls = strdup("alias ls 'ls --color'")) == NULL
      || (grep1 = strdup("setenv GREP_OPTIONS '--color=auto'")) == NULL
      || (grep2 = strdup("setenv GREP_COLOR '1;36'")) == NULL)
    return (-1);
  if (command_center(sh, ls) == -1)
    return (-1);
  free(ls);
  if (command_center(sh, grep1) == -1)
    return (-1);
  free(grep1);
  if (command_center(sh, grep2) == -1)
    return (-1);
  free(grep2);
  return (0);
}

static int	sh42(t_42 *sh)
{
  char		*command;

  sh->exit = 1;
  if (ls_grep_color(sh) == -1)
    return (-1);
  while ((command = my_get_cmd(sh)) != NULL)
    {
      if (command[0] != '\0')
      	{
      	  sh->counter += 1;
      	  if ((command = alias_in(command, sh->alias)) == NULL)
      	    return (-1);
      	  if (command_center(sh, command) == -1)
      	    return (sh->quit);
      	}
      free(command);
      sh->exit = 1;
    }
  return (sh->quit);
}

int		main(int ac, char **av, char **env)
{
  t_42		sh;

  if (sh_args(ac, av) == -1)
    return (1);
  if (sh_init(env, &sh) == -1)
    return (1);
  if (sh42(&sh) == -1)
    return (1);
  return (sh.quit);
}
