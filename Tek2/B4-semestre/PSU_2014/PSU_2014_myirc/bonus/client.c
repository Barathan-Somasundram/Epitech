/*
** server.c for server in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:32:19 2015 Potier Guillaume
** Last update Sun Apr 12 23:35:34 2015 potier_g
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <pthread.h>
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
  dialog_refresh(client->gui, resp);
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

void*			my_client(void *cli)
{
  int			next;
  t_info_client*	client;

  client = (t_info_client*)cli;
  next = 0;
  while (next == 0)
    {
      FD_ZERO(&client->readfds);
      if (client->fd > 0)
	FD_SET(client->fd, &client->readfds);
      FD_SET(0, &client->readfds);
      if (select(client->fd + 1, &client->readfds, NULL, NULL, NULL) == -1)
	return (NULL);
      if (recup_sig_serv(client) == 2)
	next = 1;
    }
  close(client->fd);
  return (NULL);
}

int			main(int ac, char** av)
{
  t_info_client		*client;
  t_gtk			gui;
  pthread_t		thread;

  gtk_init(&ac, &av);
  if ((client = init_info_client()) == NULL)
    return (-1);
  gdk_threads_init();
  gui_make(&gui);
  client->gui = &gui;
  if (pthread_create(&thread, NULL, &my_client, (void*)client) != 0)
    return (0);
  gdk_threads_enter();
  gtk_main();
  gdk_threads_leave();
  gtk_widget_destroy(gui.win);
  return (1);
}
