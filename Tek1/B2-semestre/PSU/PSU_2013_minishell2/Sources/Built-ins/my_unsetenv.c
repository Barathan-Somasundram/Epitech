/*
** my_unsetenv.c for built_in in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Mon Feb 24 11:10:42 2014 somasu_b
** Last update Sun Mar  9 18:17:08 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

static int	bis(t_list *tmp, t_list *buf, char *cmd, int mod)
{
  if (mod == 0)
    if (cmd == NULL)
      {
	my_putstr("Usage: unsetenv [variable]\n");
	return (-1);
      }
  if (mod == 1)
    {
      if (tmp->next == NULL)
	{
	  buf->next = NULL;
	  free(tmp);
	}
      else
	{
	  buf->next = tmp->next;
	  free(tmp);
	}
    }
  return (0);
}

int		my_unsetenv(char **cmd)
{
  t_list	*tmp;
  t_list	*buf;
  int		length;

  tmp = g_mysh.my_env;
  buf = g_mysh.my_env;
  length = my_strlen(cmd[1]) - 2;
  if (bis(tmp, buf, cmd[1], 0) == -1)
    return (-1);
  while (tmp != NULL && (my_strncmp(tmp->var, cmd[1], length) != 0))
    {
      buf = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return (-1);
  else
    bis(tmp, buf, cmd[1], 1);
  return (0);
}
