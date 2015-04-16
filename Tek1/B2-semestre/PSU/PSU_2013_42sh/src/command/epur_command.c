/*
** epur_command.c for 42sh in /home/somasu_b/rendu/42sh/src/command
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat May 24 19:19:05 2014 somasu_b
** Last update Sun Jun  1 16:30:28 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static const t_type	g_tab[] =
  {
    {REDIR_RIGHT1, TYPE_RIGHT1},
    {REDIR_RIGHT2, TYPE_RIGHT2},
    {REDIR_LEFT1, TYPE_LEFT1},
    {REDIR_LEFT2, TYPE_LEFT2},
    {PIPE, TYPE_PIPE},
    {OR, TYPE_OR},
    {BG, TYPE_BG},
    {AND, TYPE_AND},
    {SEP, TYPE_SEP},
    {NULL, TYPE_ARG},
  };

static int	my_strtype(char *command, int i)
{
  if (command[i] == '>')
    return (0);
  else if (command[i] == '>' && command[i + 1] == '>')
    return (1);
  else if (command[i] == '<')
    return (2);
  else if (command[i] == '<' && command[i + 1] == '<')
    return (3);
  else if (command[i] == '|')
    return (4);
  else if (command[i] == '|' && command[i + 1] == '|')
    return (5);
  else if (command[i] == '&')
    return (6);
  else if (command[i] == '&' && command[i + 1] == '&')
    return (7);
  else if (command[i] == ';')
    return (8);
  return (9);
}

static int	type_sep_counter(char *command)
{
  int		count;
  int		i;
  int		j;

  count = 0;
  i = 0;
  while (command[i])
    {
      j = 0;
      j = my_strtype(command, i);
      if (g_tab[j].sep != NULL)
	{
	  i += strlen(g_tab[j].sep);
	  ++count;
	}
      else
	++i;
    }
  return (count);
}

static void	add_space_checkquote(char command, int *quote)
{
  if (command == '\'' || command == '\"')
    *quote = (*quote == 0 ? 1 : 0);
}

static int	add_space(char **new, char *command, int i, int j)
{
  int		x;
  int		quote;

  quote = 0;
  while (command[i])
    {
      x = my_strtype(command, i);
      add_space_checkquote(command[i], &quote);
      if (g_tab[x].sep != NULL)
	{
	  if (quote == 0)
	    (*new)[j++] = ' ';
	  (*new)[j++] = command[i++];
	  if (command[i] == '>' || command[i] == '<'
	      || command[i] == '|' || command[i] == '&')
	    (*new)[j++] = command[i++];
	  if (quote == 0)
	    (*new)[j++] = ' ';
	}
      else
	while (command[i] && command[i] != '<' && command[i] != '>'
	       && command[i] != '&' && command[i] != '|' && command[i] != ';')
	  (*new)[j++] = command[i++];
    }
  return (j);
}

char		*epur_command(char *command)
{
  char		*new;
  int		sep;

  sep = 2 * type_sep_counter(command);
  if (sep == 0)
    return (command);
  sep += strlen(command) + 1;
  if ((new = malloc(sizeof(char*) * sep)) == NULL)
    return (NULL);
  new[0] = '\0';
  new[add_space(&new, command, 0, 0)] = '\0';
  free(command);
  return (new);
}
