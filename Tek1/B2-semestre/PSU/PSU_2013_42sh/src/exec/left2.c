/*
** left2.c for 42sh in /home/somasu_b/rendu/42sh/src/exec
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May 25 10:37:09 2014 somasu_b
** Last update Sun Jun  1 16:20:33 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static int	write_in_pipe_left2(char *buffer)
{
  int		i;
  pid_t		pid;
  int		pipe_fd[2];

  i = 0;
  if (pipe(pipe_fd) == -1
      || (pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      while (buffer[i])
	{
	  write(pipe_fd[1], buffer + i, 1);
	  i++;
	}
      return (-1);
    }
  else
    {
      close(pipe_fd[1]);
      if (dup2(pipe_fd[0], 0) == -1)
	return (-1);
      return (0);
    }
  return (0);
}

static char	*my_strcat_buffer(char *buffer, char *str)
{
  char		*new;

  if (!(new = malloc(sizeof(*new) * (strlen(buffer) + strlen(str) + 2))))
    return (NULL);
  new[0] = '\0';
  if (strcat(new, buffer) == NULL)
    return (NULL);
  if (strcat(new, str) == NULL)
    return (NULL);
  if (strcat(new, "\n") == NULL)
    return (NULL);
  free(buffer);
  return (new);
}

int		sh_left2(t_42 *sh, char *file)
{
  char		*buffer;
  char		*str;

  if ((buffer = malloc(sizeof(*buffer) * 1)) == NULL)
    return (-1);
  buffer[0] = '\0';
  write(sh->fds[1], "> ", 2);
  while ((str = get_next_line(0)) != NULL && strcmp(str, file) != 0)
    {
      if ((buffer = my_strcat_buffer(buffer, str)) == NULL)
      	return (-1);
      free(str);
      write(sh->fds[1], "> ", 2);
    }
  return (write_in_pipe_left2(buffer));
}
