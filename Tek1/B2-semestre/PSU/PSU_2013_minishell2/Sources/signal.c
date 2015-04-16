/*
** signal.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 15:50:41 2014 somasu_b
** Last update Mon Mar  3 18:05:56 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../Includes/my_string.h"
#include "../Includes/mysh.h"

static void	do_nothing(int sig)
{
  if (sig == SIGTSTP)
    my_putstr("\b\b  \b\b");
  else
    {
      my_putstr("\n");
      my_prompt();
    }
}

void	my_signal(void)
{
  signal(SIGINT, do_nothing);
  signal(SIGQUIT, do_nothing);
  signal(SIGTSTP, do_nothing);
}
