/*
** new_user.c for new_user in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:32:14 2015 Potier Guillaume
** Last update Sun Apr 12 16:35:02 2015 Potier Guillaume
*/

#include <unistd.h>
#include <stdlib.h>

#include "server.h"

int			use_free_place(t_info_server *server, int sock)
{
  t_list_user		*tmp;
  int			prev_id;

  tmp = server->users;
  prev_id = 1;
  while (tmp != NULL)
    {
      if (tmp->id > 0 && tmp->pseudo == NULL && tmp->socket == -1)
	{
	  tmp->id = prev_id;
	  tmp->socket = sock;
	  return (1);
	}
      prev_id = tmp->id;
      tmp = tmp->next;
    }
  return (0);
}

void			init_new(t_list_user *new, int sock)
{
  new->socket = sock;
  new->pseudo = NULL;
  new->channel = 0;
  new->accept = 0;
  return ;
}

int			new_user(t_info_server *server, int sock)
{
  t_list_user		*new;
  t_list_user		*tmp;

  if (use_free_place(server, sock) == 1)
    return (1);
  if ((new = malloc(sizeof(t_list_user))) == NULL)
    return (-1);
  new->next = NULL;
  tmp = server->users;
  if (server->users == NULL)
    {
      server->users = new;
      new->id = 1;
    }
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      new->id = tmp->id + 1;
    }
  init_new(new, sock);
  return (1);
}

int			max_sock(t_info_server *server)
{
  int			max;
  t_list_user		*tmp;

  tmp = server->users;
  max = 0;
  while (tmp != NULL)
    {
      if (max < tmp->socket)
	max = tmp->socket;
      tmp = tmp->next;
    }
  if (max < server->fd)
    max = server->fd;
  return (max);
}

int			delete_user(t_list_user *current_user)
{
  close(current_user->socket);
  current_user->socket = -1;
  if (current_user->pseudo != NULL)
    free(current_user->pseudo);
  current_user->pseudo = NULL;
  current_user->channel = -1;
  return (1);
}
