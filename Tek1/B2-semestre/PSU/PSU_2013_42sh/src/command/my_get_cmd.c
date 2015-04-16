/*
** my_get_cmd.c for 42sh in /home/somasu_b/rendu/mysh/src
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Wed May 14 22:37:24 2014 somasu_b
** Last update Sun Jun  1 16:42:12 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/curses.h>
#include <term.h>
#include "sh.h"

static int	add_history(t_hist **history, char *command)
{
  t_hist	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((elem->command = strdup(command)) == NULL)
    return (-1);
  elem->number = (*history)->prev->number + 1;
  elem->position = -1;
  elem->prev = (*history)->prev;
  elem->next = (*history);
  (*history)->prev->next = elem;
  (*history)->prev = elem;
  return (0);
}

char		*my_get_cmd(t_42 *sh)
{
  char		*command;

  command = NULL;
  sh_prompt(sh);
  if (sh->is_term == 0)
    command = get_next_line(STDIN_FILENO);
  else
    {
      if (tcsetattr(0, 0, &(sh->sh_term)) == -1)
      	return (NULL);
      command = gnl_termcaps(sh);
      tputs(sh->alocrs, 1, tputswrite);
      if (tcsetattr(0, 0, &(sh->backup)) == -1)
      	return (NULL);
    }
  if (command == NULL)
    {
      printf("\n");
      return (NULL);
    }
  if ((command = epur_command(command)) == NULL)
    return (NULL);
  if (command[0] != '\0' && add_history(&(sh->history), command) == -1)
    return (NULL);
  return (command);
}
