/*
** list.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 15:29:38 2014 somasu_b
** Last update Mon Mar  3 18:06:27 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../Includes/my_string.h"
#include "../Includes/mysh.h"

int		my_put_in_list(t_list **my_env, char *vars)
{
  t_list	*elem;
  t_list	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((elem->var = my_strdup(vars)) == NULL)
    return (-1);
  elem->next = NULL;
  if (*my_env == NULL)
    *my_env = elem;
  else
    {
      tmp = *my_env;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  return (0);
}
