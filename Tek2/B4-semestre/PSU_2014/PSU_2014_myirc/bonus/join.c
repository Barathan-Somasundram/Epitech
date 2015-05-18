/*
** join.c for join in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:28:49 2015 Potier Guillaume
** Last update Sun Apr 12 21:23:02 2015 potier_g
*/
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

int			fnc_nick(char *cmd, t_info_client *client)
{
  if (client->fd <= 0)
    return (write(2, "Error - Connexion doesn't etablish\n", 35));
  write(client->fd, cmd, strlen(cmd) + 1);
  if (client->login != NULL)
    free(client->login);
  client->login = recup_nparam(cmd, 1);
  return (1);
}

int			fnc_join(char *cmd, t_info_client *client)
{
  if (client->fd <= 0)
    return (write(2, "Error - Connexion doesn't etablish\n", 35));
  write(client->fd, cmd, strlen(cmd) + 1);
  if (client->channel != NULL)
    free(client->channel);
  client->channel = recup_nparam(cmd, 1);
  return (1);
}

int			fnc_part(char *cmd, t_info_client *client)
{
  if (client->fd <= 0)
    return (write(2, "Error - Connexion doesn't etablish\n", 35));
  write(client->fd, cmd, strlen(cmd) + 1);
  if (client->channel != NULL)
    free(client->channel);
  client->channel = NULL;
  return (1);
}
