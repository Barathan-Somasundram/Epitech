/*
** env.c for 42sh in /home/somasu_b/rendu/42sh/src/built/o
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 09:02:00 2014 somasu_b
** Last update Thu May 29 21:53:20 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

int		my_env(t_42 *sh, t_tok *token)
{
  t_env		*tmp;

  (void)token;
  tmp = sh->env->next;
  while (tmp != sh->env)
    {
      printf("%s=", tmp->var);
      if (tmp->contents)
	printf("%s\n", tmp->contents);
      else
	printf("\n");
      tmp = tmp->next;
    }
  return (1);
}
