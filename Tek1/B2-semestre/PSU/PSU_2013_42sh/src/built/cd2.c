/*
** cd-2.c for  in /home/sam_t/Workstation/PSU_2013_42sh/sam_t
**
** Made by sam_t
** Login   <sam_t@epitech.net>
**
** Started on  Sun May 25 16:58:39 2014 sam_t
** Last update Fri May 30 15:51:36 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

char	*my_getpwd(void)
{
  char	*curdirname;

  if ((curdirname = malloc(sizeof(char) * (PATH_LENGTH + 1))) == NULL)
    return (NULL);
  if (getcwd(curdirname, (PATH_LENGTH + 1)) == NULL)
    return (NULL);
  return (curdirname);
}

char	*my_getvar(t_42 *sh, char *var)
{
  t_env	*tmp_env;

  tmp_env = sh->env->next;
  while (tmp_env != sh->env)
    {
      if (strcmp(var, tmp_env->var) == 0)
	return (tmp_env->contents);
      tmp_env = tmp_env->next;
    }
  fprintf(stderr, "Error : environment variable "
	  "\"%s\" not found\n", var);
  return (NULL);
}

int	change_env(t_42 *sh, char *contents, char *var)
{
  t_env *tmp_env;
  t_env	*elem;

  tmp_env = sh->env->next;
  while (tmp_env != sh->env && strcmp(var, tmp_env->var) != 0)
    tmp_env = tmp_env->next;
  if (tmp_env != sh->env)
    {
      tmp_env->contents = contents;
      return (1);
    }
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((elem->var = strdup(var)) == NULL)
    return (-1);
  elem->contents = NULL;
  if (contents != NULL)
    elem->contents = contents;
  elem->prev = sh->env->prev;
  elem->next = sh->env;
  sh->env->prev->next = elem;
  sh->env->prev = elem;
  return (1);
}
