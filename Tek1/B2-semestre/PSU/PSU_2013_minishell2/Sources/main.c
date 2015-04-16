/*
** main.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 14:31:24 2014 somasu_b
** Last update Mon Mar  3 18:07:04 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../Includes/my_string.h"
#include "../Includes/mysh.h"

int	my_perror_mysh(int ac, char **av)
{
  if (ac > 1)
    {
      my_puterror(B_RED "mysh: " B_GREEN);
      my_puterror("Can't open input file: " B_YELLOW);
      my_puterror(av[1]);
      my_puterror("\n" NORMAL);
      return (-1);
    }
  return (0);
}

int	init_env(char **env)
{
  int	i;

  i = -1;
  g_mysh.my_env = NULL;
  while (env[++i] != NULL)
    if (my_put_in_list(&(g_mysh.my_env), env[i]) == -1)
      return (-1);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  g_mysh.counter = 0;
  if (my_perror_mysh(ac, av) == -1)
    return (-1);
  if (init_env(env) == -1)
    return (-1);
  if (minishell() == -1)
    return (-1);
  return (0);
}
