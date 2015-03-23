/*
** main.c for  in /home/somasu_b/rendu/PSU_2014_myftp/sources/client
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 22 12:33:44 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 22 20:26:57 2015 SOMASUNDRAM Barathan
*/

#include "client.h"

char*			parse_cmd(char* buffer, int* cmd, t_client* client)
{
  char*			tok;
  char*			tmp;
  char*			arg;

  if (!(tmp = strdup(buffer)))
    {
      fprintf(stderr, "Error: Strdup failed\n");
      return (NULL);
    }
  tok = strtok(tmp, " \t");
  if ((*cmd = my_get_cmd(tok)) == -1)
    return (NULL);
  arg = strtok(NULL, " \t");
  if (tok != NULL)
    memcpy(arg, tok, strlen(tok));
  free(tmp);
  return (0);
}

/*
**
*/
int			start(t_client *client)
{
  t_proto*		pe;

  client->s_in_size = sizeof(client->s_in);
  client->s_in.sin_famliy = AF_INET;
  client->s_in.sin_port = htons(client->port);
  client->s_in.sin_addr.s_addr = inet_addr(client->ip);
  if (!(pe = getprotobyname("TCP")))
    return (1);
  if ((client->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (1);
  if (connect(client->fd, (struct sockaddr*)&(client->s_in),
	      client->s_in_size) == -1)
    return (1);
  return (0);
}

int			quit(t_client* client)
{
  if (close(client->fd) == -1)
    return (1);
  return (0);
}
/*
**
*/
int			my_get_cmd(char *str)
{
  int			i;

  i = -1;
  if (!str)
    return (-1);
  if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
  while (++i < 7)
    if (strncmp(command[i].cmd, str, strlen(command[i].cmd) - 1) == 0)
      return (i);
  fprintf(stderr, "Error: bad command\n");
  return (-1);
}

void			signal_handle(int sig)
{
  (void)signum;
  exit(1);
}

int			command_center(t_client* client)
{
  int			ret;
  char			buffer[BUFFER_SIZE + 1];
  int			cmd;
  char*			arg;

  signal(SIGPIPE, &broken_pipe);
  if ((ret = read(client->fd, buffer, BUFFER_SIZE)) == -1)
    return (1);
  buffer[ret] = '\0';
  printf("%s\n", buffer);
  printf(PROMPT, "", "");
  while ((ret = read(client->fd, buffer, BUFFER_SIZE)) >= 0)
    {
      buffer[ret] = '\0';
      if ((arg = parse_cmd(buffer, &cmd, client)) == NULL)
	return (1);
      if (cmd == 1)
	return (0);
      /* if ((ret = command[cmd].function(client, buffer)) == 1) */
      /* 	return (1); */
    }
  return (0);
}
/*
**
*/
static int		check_port(char *port)
{
  int			i;
  int			is_there_nb;

  i = 0;
  is_there_nb = 0;
  while (str && str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	is_there_nb = 1;
      else
	{
	  fprintf(stderr, ERR_PORT);
	  return (1);
	}
      ++i;
    }
  if (is_there_nb != 1)
    {
      fprintf(stderr, ERR_PORT);
      return (1);
    }
  return (0);
}

int			main(int ac, char** av)
{
  t_client		client;

  if (ac != 3)
    return (1);
  client.ip = av[1];
  if (check_port(av[2]) == 1)
    return (1);
  client.port = atoi(av[2]);
  if (start(&client) < 0)
    return (1);
  command_center(&client);
  quit(&client);
  return (0);
}
