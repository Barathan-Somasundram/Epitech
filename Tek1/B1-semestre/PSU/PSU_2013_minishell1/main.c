/*
** main.c for minishell1 in /home/somasu_b/rendu/PSU_2013_minishell1/new
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Dec 24 20:33:45 2013 a
** Last update Fri Dec 27 11:18:09 2013 a
*/

#include "mysh.h"

int	main(int ac, char **av, char **env_sys)
{
  char	**env;

  if ((env = malloc(sizeof(char*) * (my_strlen_tab(env_sys) + 1))) == NULL)
    return (-1);
  env = my_strcpy_env(env, env_sys, my_strlen_tab(env_sys));
  minishell1(env);
  return (0);
}
