/*
** client.c for client in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:29:02 2015 Potier Guillaume
** Last update Sun Apr 12 19:01:46 2015 potier_g
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

t_info_client		*init_info_client()
{
  t_info_client		*info;

  if ((info = malloc(sizeof(t_info_client))) == NULL)
    return (NULL);
  info->login = NULL;
  info->channel = NULL;
  info->fd = 0;
  return (info);
}

int			recup_resp(t_info_client *client)
{
  char			*resp;

  if ((resp = my_read(client->fd)) == NULL)
    return (1);
  if (strcmp(resp, "/Disconnect") == 0)
    return (2);
  write(1, resp, strlen(resp));
  return (1);
}

int			recup_sig_serv(t_info_client *client)
{
  if (client->fd > 0 && FD_ISSET(client->fd, &client->readfds))
    {
      if (recup_resp(client) == 2)
	return (2);
      return (1);
    }
  else if (FD_ISSET(0, &client->readfds))
    {
      apply_cmd(client);
      return (-1);
    }
  return (1);
}

int			my_client(t_info_client *client)
{
  int			next;

  next = 0;
  while (next == 0)
    {
      FD_ZERO(&client->readfds);
      if (client->fd > 0)
	FD_SET(client->fd, &client->readfds);
      FD_SET(0, &client->readfds);
      if (select(client->fd + 1, &client->readfds, NULL, NULL, NULL) == -1)
	return (-1);
      if (recup_sig_serv(client) == 2)
	next = 1;
    }
  close(client->fd);
  return (1);
}

int			main()
{
  t_info_client		*client;

  if ((client = init_info_client()) == NULL)
    return (-1);
  my_client(client);
  return (1);
}
