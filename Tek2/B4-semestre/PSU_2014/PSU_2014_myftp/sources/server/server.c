/*
** server.c for  in /home/somasu_b/rendu/PSU_2014_myftp/sources/server
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Mar 12 23:24:33 2015 SOMASUNDRAM Barathan
** Last update Fri Mar 13 00:28:13 2015 SOMASUNDRAM Barathan
*/

#include "server.h"

static int	initialize(t_server* server)
{
  if ((server->pe = getprotobyname("TCP")) == NULL)
    return (1);
  if ((server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto)) == -1)
    return (1);
  server->s_in.sin_family = AF_INET;
  server->s_in.sin_port = htons(server->port);
  server->s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(server->fd, (const struct sockaddr*)&(server->s_in),
	   sizeof(server->s_in)) == -1)
    {
      close(server->fd);
      return (1);
    }
  if (listen(server->fd, MAX_CLIENT) == -1)
    {
      close(server->fd);
      return (1);      
    }
  return (0);
}

static int	connect_to_client(t_server* server)
{
  server->client.s_in_size = sizeof(server->client.s_in);
  if ((server->client.fd = accept(server->fd
				  , (struct sockaddr*)&(server->client.s_in)
				  , &(server->client.s_in_size))) == -1)
    {
      close(server->fd);
      return (1);
    }
  sprintf(server->path, ".\0");
  server->root = 1;
  server->client.ip = inet_ntoa(server->client.s_in.sin_addr);
  printf("A client is now connected to the server from %s\n",
	 server->client.ip);
  //TODO: Gestion multi client and handle_client
  return (0);
}

static int     	quit(t_server* server)
{
  close(server->fd);
  close(server->client.fd);
  printf("Thanks to have use my_ftp. Good bye ! :)\n");
  return (0);
}

int		server_ftp(t_server* server)
{
  if (initialize(&server) == 1)
    return (1);

  if (connect_to_client(&server) == 1)	// TODO: Gestion multi client
    return (1);

  if (quit(void) == 1)
    return (1);
  return (0);
}
