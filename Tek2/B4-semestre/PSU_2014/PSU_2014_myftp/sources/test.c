/*
** main.c for  in /home/somasu_b/rendu/PSU_2014_myftp/sources/server
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Mar 10 18:32:44 2015 SOMASUNDRAM Barathan
** Last update Tue Mar 10 22:59:47 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "my_ftp.h"

int			my_perror(const char* msg, int ret)
{
  write(2, msg, strlen(msg));
  return (ret);
}

int			handle_client(t_client* client)
{
  write(client->fd, MSG_WELCOME, strlen(MSG_WELCOME));
  write(client->fd, "Your ip address is ", strlen("Your ip address is "));
  write(client->fd, client->ip, strlen(client->ip));
  write(client->fd, "\n", 1);
  return (0);
}

int			init_protocol(t_proto* pe, t_socket* s_in, int* fd)
{
  if ((pe = getprotobyname("TCP")) == NULL)
    return (1);
  if ((*fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (1);
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
  if (bind(*fd, (const struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    {
      if (close(*fd) == -1)
	return (1);
      return (1);
    }
  return (0);
}

int			init_t_client(t_client* client)
{
  client->s_in_size = sizeof(client->s_in);
  if ((client->fd = accept(fd, (struct sockaddr*)&(client->s_in), &(client->s_in_size))) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  client->ip = inet_ntoa(client->s_in.sin_addr);
}

int			server(int port)
{
  t_proto		*pe;
  int			fd;
  t_socket		s_in;  
  t_client		client;

  if (init_protocol(pe, &s_in, &fd) == 1)
    return (1);

  if (listen(fd, 42) == -1) // TODO: 42 est le numero de client max
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }

  if (init_t_client(&client) == 1)
    return (1);

  write(1, client.ip, strlen(client.ip));
  write(1, "\n", 1);

  handle_client(&client);

  if (close(fd) == -1)
    return (1);
  if (close(client.fd) == -1)
    return (1);
  return (0);
}

int			check_port(char* port)
{
  int			i;

  i = -1;
  while (port[++i])
    if (port[i] < '0' || port[i] > '9')
      {
	write(2, ERR_PORT, strlen(ERR_PORT));
	return (1);
      }
  return (0);
}

int			main(int ac, char** av)
{
  if (ac != 2)
    return (my_perror("Usage: ./server [port]\n", 1));
  if (check_port(av[1]) == 1)
    return (1);
  if (server(atoi(av[1])) == 1)
    {
      write(2, ERR_HAPPEND, strlen(ERR_HAPPEND));
      return (1);
    }
  return (0);
}
