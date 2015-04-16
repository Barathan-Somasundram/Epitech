/*
** history.c for 42sh in /home/somasu_b/rendu/42sh/src/built/o
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 09:08:39 2014 somasu_b
** Last update Thu May 29 21:53:33 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

static int	history_erase(t_42 *sh)
{
  t_hist	*tmp;

  tmp = sh->history->next;
  while (tmp != sh->history)
    {
      tmp = tmp->next;
      free(tmp->prev->command);
      free(tmp->prev);
    }
  tmp->position = 1;
  tmp->next = tmp;
  tmp->prev = tmp;
  return (0);
}

int		my_history(t_42 *sh, t_tok *token)
{
  t_hist	*tmp;

  if (token->next->next != token && strcmp(token->next->next->cmd, "-c"))
    history_erase(sh);
  else
    {
      tmp = sh->history->next;
      while (tmp != sh->history)
	{
	  printf("%d\t%s\n", tmp->number, tmp->command);
	  tmp = tmp->next;
	}
    }
  return (1);
}
