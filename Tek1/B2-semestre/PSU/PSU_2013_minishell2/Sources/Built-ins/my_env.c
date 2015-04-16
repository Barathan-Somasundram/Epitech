/*
** my_env.c for built-in in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 22:22:25 2014 somasu_b
** Last update Sun Mar  9 18:22:52 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/built_in.h"

static void	fill_options(char **opt, char **cmd)
{
  if ((my_strcmp(cmd[1], "--ignore-environment")) == 0
      || (my_strcmp(cmd[1], "-i")) == 0)
    (*opt)[0] = '1';
  else if ((my_strncmp(cmd[1], "--null", 8)) == 0
	   || (my_strcmp(cmd[1], "-0")) == 0)
    (*opt)[1] = '1';
  else if ((my_strncmp(cmd[1], "--unset=", 8)) == 0
	   || (my_strcmp(cmd[1], "-u")) == 0)
    (*opt)[2] = '1';
  else if ((my_strcmp(cmd[1], "--help")) == 0)
    (*opt)[3] = '1';
  else if ((my_strcmp(cmd[1], "--version")) == 0)
    (*opt)[4] = '1';
  else if (cmd[1] != NULL)
    (*opt)[5] = '1';
  (*opt)[6] = '\0';
}

static char	*option(char **cmd)
{
  char		*opt;
  int		i;

  i = 0;
  if (cmd == NULL || cmd[1] == NULL)
    return (NULL);
  if ((opt = malloc(sizeof(char) * 6)) == NULL)
    return (NULL);
  while (i < 5)
    opt[i++] = '0';
  fill_options(&opt, cmd);
  return (opt);
}

static int	my_print_env(int mod)
{
  t_list	*tmp;

  tmp = g_mysh.my_env;
  while (tmp != NULL)
    {
      my_putstr(tmp->var);
      if (mod == 0)
	my_putstr("\n");
      else
	my_putchar('\0', STDOUT_FILENO);
      tmp = tmp->next;
    }
  return (0);
}

static int	help_or_ver(int mod)
{
  if (mod == 1)
    my_putstr("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]\n"
	      "Set each NAME to VALUE in the environment and run COMMAND.\n\n"

	      "  -i, --ignore-environment  start with an empty environment\n"
	      "  -u, --unset=NAME     remove variable from the environment\n"
	      "      --help     display this help and exit\n"
	      "      --version  output version information and exit\n"
	      "A mere - implies -i.  If no COMMAND, "
	      "print the resulting environment.\n\n"
	      "Report env bugs to bug-coreutils@gnu.org\n"
	      "GNU coreutils home page: <http://www.gnu.org/software/coreutils/>\n"
	      "General help using GNU software: <http://www.gnu.org/gethelp/>\n"
	      "For complete documentation, run: "
	      "info coreutils 'env invocation'\n");
  if (mod == 2)
    my_putstr("env (GNU coreutils) 8.17\n"
	     "Copyright (C) 2012 Free Software Foundation, Inc.\n"
	     "License GPLv3+: GNU GPL version 3 or "
	     "later <http://gnu.org/licenses/gpl.html>.\n"
	     "This is free software: you are free to change and redistribute it.\n"
	     "There is NO WARRANTY, to the extent permitted by law.\n\n"
	     "Written by Barathan SOMASUNDRAM.\n");
  return (0);
}

int	my_env(char **cmd)
{
  char	*opt;

  opt = option(cmd);
  if (opt != NULL)
    {
      if (opt[0] == '1')
  	return (my_exec_cmd(&cmd[2], 1));
      else if (opt[1] == '1')
  	return (my_print_env(1));
      else if (opt[3] == '1')
  	return (help_or_ver(1));
      else if (opt[4] == '1')
  	return (help_or_ver(2));
      free(opt);
    }
  my_print_env(0);
  return (0);
}
