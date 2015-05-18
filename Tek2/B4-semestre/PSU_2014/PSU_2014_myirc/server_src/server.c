/*
** server.c for server in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:32:19 2015 Potier Guillaume
** Last update Sun Apr 12 23:35:33 2015 potier_g
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#include "server.h"

static t_info_server	*g_server;

t_info_server		*init_server(int port)
{
  t_info_server		*info;

  if ((info = malloc(sizeof(t_info_server))) == NULL)
    return (NULL);
  info->s_in_size = sizeof(info->s_in_client);
  if ((info->pe = getprotobyname("TCP")) == NULL)
    return (NULL);
  if ((info->fd = socket(AF_INET, SOCK_STREAM,
			 info->pe->p_proto)) == -1)
    return (NULL);
  info->s_in.sin_family = AF_INET;
  info->s_in.sin_port = htons(port);
  info->s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(info->fd, (struct sockaddr *)&info->s_in,
	   sizeof(info->s_in)) == -1)
    return (NULL);
  if (listen(info->fd, 100) == -1)
    return (NULL);
  info->users = NULL;
  info->channels = NULL;
  return (info);
}

int			recup_sig_serv(t_info_server *server)
{
  t_list_user		*tmp;
  int			tmp_fd;

  if (FD_ISSET(server->fd, &server->readfds))
    {
      if ((tmp_fd = accept(server->fd,
			   (struct sockaddr*)&server->s_in_client,
			   &server->s_in_size)) == -1)
	return (-1);
      if (new_user(server, tmp_fd) == -1)
	return (-1);
      connect_ok(tmp_fd);
      return (1);
    }
  tmp = server->users;
  while (tmp)
    {
      if (FD_ISSET(tmp->socket, &server->readfds))
	{
	  if (recup_cmd(server, tmp) == -1)
	    return (-1);
	}
      tmp = tmp->next;
    }
  return (1);
}

void			my_quit(int sig)
{
  (void)sig;
  erase_users_list(g_server);
  erase_channel_list(g_server);
  free(g_server);
  exit(1);
}

int			my_server()
{
  t_list_user		*tmp;

  while (42)
    {
      FD_ZERO(&g_server->readfds);
      FD_SET(g_server->fd, &g_server->readfds);
      tmp = g_server->users;
      signal(SIGINT, &my_quit);
      while (tmp)
	{
	  if (tmp->socket != -1)
	    FD_SET(tmp->socket, &g_server->readfds);
	  tmp = tmp->next;
	}
      if (select(max_sock(g_server) + 1,
		 &g_server->readfds, NULL, NULL, NULL) == -1)
	return (-1);
      recup_sig_serv(g_server);
    }
  return (1);
}

int			main(int ac, char **av)
{
  if (ac != 2)
    return (write(2, "USAGE : /server [port]\n", 23));
  if ((g_server = init_server(atoi(av[1]))) == NULL)
    return (-1);
  my_server();
  return (1);
}
