/*
** to_tab.c for 42sh in /home/somasu_b/rendu/mysh/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat May 24 15:20:33 2014 somasu_b
** Last update Sun Jun  1 18:34:20 2014 song_k
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include "sh.h"

static int	env_length(t_env *env)
{
  t_env		*tmp;
  int		len;

  tmp = env->next;
  len = 0;
  while (tmp != env)
    {
      ++len;
      tmp = tmp->next;
    }
  return (len);
}

char		**env_to_tab(t_env *env)
{
  char		**envi;
  t_env		*tmp;
  int		l;
  int		len;

  if ((envi = malloc(sizeof(char*) * (env_length(env) + 1))) == NULL)
    return (NULL);
  l = 0;
  tmp = env;
  while ((tmp = tmp->next) != env)
    {
      len = strlen(tmp->var)
	+ ((tmp->contents == NULL) ? 0 : strlen(tmp->contents)) + 2;
      if ((envi[l] = malloc(sizeof(char*) * len)) == NULL)
	return (NULL);
      envi[l][0] = '\0';
      if ((envi[l] = strcat(envi[l], tmp->var)) == NULL
	  || (envi[l] = strcat(envi[l], "=")) == NULL
	  || (tmp->contents && !(envi[l] = strcat(envi[l], tmp->contents))))
      	return (NULL);
      ++l;
    }
  envi[l] = NULL;
  return (envi);
}

static char	**my_globing(char **cmd, char *pattern, int *len)
{
  glob_t	globbuf;
  char		**wt;
  int		ct;

  globbuf.gl_offs = 0;
  if (glob(pattern, GLOB_DOOFFS, NULL, &globbuf) || globbuf.gl_pathc == 0)
    return (cmd);
  if ((wt = malloc(sizeof(char *) * (globbuf.gl_pathc + *len + 1))) == NULL)
    return (NULL);
  ct = -1;
  while (++ct < *len)
    wt[ct] = cmd[ct];
  ct = 0;
  while (globbuf.gl_pathv[ct] != NULL)
    wt[(*len)++] = globbuf.gl_pathv[ct++];
  return (wt);
}

char		**tok_to_tab(t_tok *token)
{
  t_tok		*tmp;
  char		**cmd;
  int		len;

  len = 0;
  tmp = token;
  while ((tmp = tmp->next) != token)
    ++len;
  if ((cmd = malloc(sizeof(char*) * (len + 1))) == NULL)
    return (NULL);
  tmp = token;
  len = 0;
  while ((tmp = tmp->next) != token)
    {
      if (strstr(tmp->cmd, "*"))
	{
	  if ((cmd = my_globing(cmd, tmp->cmd, &len)) == NULL)
	    return (NULL);
	}
      else if ((cmd[len++] = strdup(tmp->cmd)) == NULL)
	return (NULL);
    }
  cmd[len] = NULL;
  return (cmd);
}
