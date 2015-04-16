/*
** alias_in.c for in alias in /home/bellil_b/rendu/PSU_2013_42sh/bellil_b/PSU_2013_42sh
**
** Made by bellil_b
** Login   <bellil_b@epitech.net>
**
** Started on  Sun Jun  1 16:37:47 2014 bellil_b
** Last update Sun Jun  1 17:01:00 2014 somasu_b
*/

#include <stdlib.h>
#include <string.h>
#include "sh.h"

static char		*strcatdup(char *str1, char *str2, int a)
{
  int			i;
  int			c;
  char			*dest;

  i = 0;
  c = 0;
  if (str1 != NULL)
    {
      if ((dest = malloc(sizeof(*dest)
			  * (strlen(str1) + strlen(str2) + 2))) == NULL)
	return (NULL);
      while (str1[i] != '\0')
	dest[c++] = str1[i++];
      if (a == 0)
	dest[c++] = ' ';
      free(str1);
    }
  else
    if ((dest = malloc(sizeof(*dest) * (strlen(str2) + 1))) == NULL)
	return (NULL);
  i = 0;
  while (str2[i] != '\0')
    dest[c++] = str2[i++];
  dest[c] = '\0';
  return (dest);
}

static char		*verif_remp(char *dest, char *str, t_alias *alias)
{
  t_alias		*tmp;

  tmp = alias;
  while (tmp != NULL)
    {
      if (strcmp(tmp->var, str) == 0)
      	{
      	  if (tmp->contents != NULL)
	    if ((dest = strcatdup(dest, tmp->contents, 0)) == NULL)
	      return (NULL);
      	  return (dest);
      	}
      tmp = tmp->next;
    }
  if ((dest = strcatdup(dest, str, 0)) == NULL)
    return (NULL);
  return (dest);
}

static void		free_tabcmd(char **str, char *str2)
{
  int			i;

  i = 0;
  if (str2 != NULL)
    free(str2);
  if (str != NULL)
    while (str[i] != NULL)
      free(str[i++]);
  if (str != NULL)
    free(str);
}

char			*alias_in(char *cmd, t_alias *alias)
{
  int			i;
  char			**dcp;
  char			*dest;

  i = 0;
  dest = NULL;
  if ((dcp = my_str_to_wordtab(cmd, ' ')) == NULL)
    return (NULL);
  while (dcp[i] != NULL)
    {
      if (i == 0)
	dest = verif_remp(dest, dcp[i], alias);
      else if ((dcp[i - 1][0] == '|' || dcp[i - 1][0] == '&'
		|| dcp[i - 1][0] == '>' || dcp[i - 1][0] == '>'
		|| dcp[i - 1][0] == ';'))
	dest = verif_remp(dest, dcp[i], alias);
      else
	dest = strcatdup(dest, dcp[i], 0);
      if (dest == NULL)
	return (NULL);
      i = i + 1;
    }
  free_tabcmd(dcp, cmd);
  return (dest);
}
