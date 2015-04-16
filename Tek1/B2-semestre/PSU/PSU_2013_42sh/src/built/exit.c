/*
** exit.c for 42sh in /home/somasu_b/rendu/42sh/src/built/o
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 09:04:56 2014 somasu_b
** Last update Sun Jun  1 22:21:18 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

static int	my_isnum(char *str)
{
  int		i;

  i = -1;
  while (str && str[++i])
    if (str[i] >= '0' && str[i] <= '9')
      return (i);
  return (-1);
}

int		my_getnbr(char *str)
{
  int		i;
  int		neg;
  int		nb;

  if ((i = my_isnum(str)) == -1)
    return (0);
  neg = 1;
  while (i > 0 && str[--i] == '-')
    neg *= -1;
  while (str[i] == '-')
    ++i;
  nb = 0;
  while (str[i])
    nb = nb * 10 + (str[i++] - '0');
  nb *= neg;
  return (nb);
}

int		sh_exit(t_42 *sh, t_tok *token)
{
  if (token->next->next != token)
    sh->quit = my_getnbr(token->next->next->cmd);
  else
    sh->quit = 0;
  printf("%d\n", sh->quit);
  return (-1);
}
