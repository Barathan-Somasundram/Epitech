/*
** cmd_env.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 21:05:46 2014 somasu_b
** Last update Tue Mar  4 16:06:14 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

int	my_env_tab(char ***env)
{
  t_list	*tmp;
  int		length;

  length = 0;
  tmp = g_mysh.my_env;
  while (tmp != NULL)
    {
      ++length;
      tmp = tmp->next;
    }
  if (length == 0)
    return (-1);
  if (((*env) = malloc(sizeof(char*) * (length + 2))) == NULL)
    return (-1);
  tmp = g_mysh.my_env;
  length = 0;
  while (tmp != NULL)
    {
      if (((*env)[length++] = my_strdup(tmp->var)) == NULL)
	return (-1);
      tmp = tmp->next;
    }
  (*env)[length] = NULL;
  return (0);
}
