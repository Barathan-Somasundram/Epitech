/*
** my_signal.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Dec 28 17:42:49 2013 a
** Last update Mon Jan  6 18:46:38 2014 a
*/

#include "mysh.h"

void	ign(int sig)
{
  my_putstr("\n$> ");
}

void	my_signal(void)
{
  signal(SIGINT, ign);
  signal(SIGQUIT, ign);
  signal(SIGTSTP, ign);
}
