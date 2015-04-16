/*
** tmp.c for tmp in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 21:16:28 2014 somasu_b
** Last update Sun Mar  9 18:54:11 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/my_string.h"
#include "../../Includes/mysh.h"

static void		my_free_env(void)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = g_mysh.my_env;
  while (tmp != NULL)
    {
      tmp2 = tmp->next;
      free(tmp->var);
      free(tmp);
      tmp = tmp2;
    }
}

static int	char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

static int	my_get_nbr(char *str)
{
  int	i;
  int	res;
  int	sign;

  i = 0;
  res = 0;
  sign = 1;
  while (char_is_num(str[i]) == 0)
    i = i + 1;
  if (str[i - 1] == '-')
    sign = -1;
  while (char_is_num(str[i]) == 1)
    {
      res = res * 10 + (str[i] - '0');
      i = i + 1;
    }
  res = res * sign;
  return (res);
}

int	my_exit(char **cmd, char **multi_cmd)
{
  int	status;

  my_free_env();
  if (cmd[1] == NULL)
    {
      my_free_tab(&cmd);
      my_free_tab(&multi_cmd);
      exit(0);
    }
  status = my_get_nbr(cmd[1]);
  my_free_tab(&cmd);
  my_free_tab(&multi_cmd);
  exit(status);
  return (0);
}
