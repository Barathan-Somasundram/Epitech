/*
** quit.c for quit in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:35:50 2015 Potier Guillaume
** Last update Sun Apr 12 22:22:45 2015 potier_g
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void		erase_users_list(t_info_server *info)
{
  t_list_user		*tmp_user;
  t_list_user		*tmp_user_nxt;

  tmp_user = info->users;
  while (tmp_user)
    {
      tmp_user_nxt = tmp_user->next;
      write(tmp_user->socket, "/Disconnect", 11);
      close(tmp_user->socket);
      if (tmp_user->pseudo)
	free(tmp_user->pseudo);
      free(tmp_user);
      tmp_user = tmp_user_nxt;
    }
  return ;
}

void		erase_channel_list(t_info_server *info)
{
  t_list_channel	*tmp_channel;
  t_list_channel	*tmp_channel_nxt;

  tmp_channel = info->channels;
  while (tmp_channel)
    {
      tmp_channel_nxt = tmp_channel->next;
      if (tmp_channel->name)
	free(tmp_channel->name);
      free(tmp_channel);
      tmp_channel = tmp_channel_nxt;
    }
  return ;
}

void		connect_ok(int fd)
{
  write(fd, "375 :- IRC Server Message of the day -\n", 39);
  write(fd, "372 :- Friendship is Magic\n", 27);
  write(fd, "376 :End of /MOTD command\n", 26);
  write(fd, "251 :There are 1 users on 1 servers\n", 36);
  return ;
}
