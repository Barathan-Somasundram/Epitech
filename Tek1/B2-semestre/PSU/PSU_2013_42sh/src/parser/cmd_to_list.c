/*
** cmd_to_list.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri May 16 01:46:48 2014 somasu_b
** Last update Thu May 29 21:56:20 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

static int	add_token(t_tok **cmd, char *buffer, int type)
{
  t_tok		*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->cmd = buffer;
  elem->type = type;
  elem->next = (*cmd);
  elem->prev = (*cmd)->prev;
  (*cmd)->prev->next = elem;
  (*cmd)->prev = elem;
  return (0);
}

static int	word_to_list(t_tok **cmd, char *buffer, int i)
{
  (void)cmd;
  buffer[i++] = '\0';
  while (buffer[i] && (buffer[i] == ' ' ||  buffer[i] == '\t'))
    ++i;
  return (i);
}

static int	quote_to_list(t_tok **cmd, char *buffer, int i, int type)
{
  buffer[i++] = '\0';
  if (add_token(cmd, buffer + i, 0) == -1)
    return (-1);
  while (buffer[i] && buffer[i] != type)
    ++i;
  if (buffer[i] != type)
    {
      fprintf(stderr, "sh: error: Missing closing quotes\n");
      return (-1);
    }
  if (buffer[i] == '\0')
    return (i);
  buffer[i++] = '\0';
  return (i);
}

static int	move_index(t_tok **cmd, char *buffer, int i)
{
  if (add_token(cmd, buffer + i, 0) == -1)
    return (-1);
  while (buffer[i] && buffer[i] != ' ' && buffer[i] != '\t'
	 && buffer[i] != '"' && buffer[i] != '\'')
    ++i;
  return (i);
}

t_tok		*cmd_to_list(char *buffer)
{
  t_tok		*cmd_list;
  int		i;

  i = 0;
  if ((cmd_list = malloc(sizeof(*cmd_list))) == NULL)
    return (NULL);
  cmd_list->prev = cmd_list;
  cmd_list->next = cmd_list;
  while (buffer[i])
    {
      if (buffer[i] == ' ' || buffer[i] == '\t')
	i = word_to_list(&cmd_list, buffer, i);
      else if (buffer[i] == '"' || buffer[i] == '\'')
	{
	  if ((i = quote_to_list(&cmd_list, buffer, i, buffer[i])) == -1)
	    return (NULL);
	}
      else if (buffer[i] != ' ' && buffer[i] != '\t'
	       && buffer[i] != '"' && buffer[i] != '\'')
	if ((i = move_index(&cmd_list, buffer, i)) == -1)
	  return (NULL);
    }
  return (cmd_list);
}
