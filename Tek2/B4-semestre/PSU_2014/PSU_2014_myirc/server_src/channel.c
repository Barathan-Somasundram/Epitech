/*
** channel.c for channel in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:32:04 2015 Potier Guillaume
** Last update Sun Apr 12 23:40:03 2015 potier_g
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

int			find_str(char *str1, char *str2)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (str1[i])
    {
      while (str1[i] != str2[j] && str1[i])
	i++;
      while (str1[i] == str2[j] && str1[i])
	{
	  i++;
	  j++;
	  if (str2[j] == 0)
	    return (1);
	}
      if (str2[j] == 0)
	return (1);
      j = 0;
    }
  return (0);
}

int			fnc_list(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  t_list_channel	*tmp;
  char			*string;

  string = recup_nparam(cmd, 1);
  tmp = serv->channels;
  if (!string)
    write(user->socket, "321 Channel :Users Name\n", 24);
  else
    {
      write(user->socket, "321 List channels ", 18);
      write(user->socket, string, strlen(string));
      free(string);
    }
  while (tmp)
    {
      if ((string && find_str(tmp->name, string) == 1) || !string)
	{
	  write(user->socket, "\n322 ", 5);
	  write(user->socket, tmp->name, strlen(tmp->name));
	}
      tmp = tmp->next;
    }
  write(user->socket, "\n323 :End of /LIST", 18);
  return (1);
}

int			fnc_join(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  char			*name;
  int			id;

  if ((name = recup_nparam(cmd, 1)) == NULL)
    return (aff_error(2, user->socket, "/join", 461));
  if ((id = if_exist(name, serv->channels)) == 0)
    {
      if ((serv->channels = new_channel(name, serv->channels, &id)) == NULL)
	return (aff_error(2, user->socket, name, 461));
    }
  write(user->socket, "331 ", 4);
  write(user->socket, name, strlen(name));
  write(user->socket, " :No topic set\n", 15);
  write(user->socket, "353 ", 4);
  write(user->socket, name, strlen(name));
  write(user->socket, " : ", 3);
  if (user->pseudo)
    write(user->socket, user->pseudo, strlen(user->pseudo));
  else
    write(user->socket, "Anonymous", 9);
  write(user->socket, "\n", 1);
  user->channel = id;
  free(name);
  return (1);
}

int			fnc_part(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  char			*name;
  int			id;

  if ((name = recup_nparam(cmd, 1)) == NULL)
    return (aff_error(2, user->socket, "/part", 461));
  if ((id = if_exist(name, serv->channels)) == 0)
    return (aff_error(3, user->socket, name, 403));
  if (id != user->channel)
    return (aff_error(4, user->socket, name, 403));
  write(user->socket, "331 ", 4);
  write(user->socket, name, strlen(name));
  write(user->socket, " :No topic set\n", 15);
  write(user->socket, "353 ", 4);
  write(user->socket, name, strlen(name));
  write(user->socket, " : ", 3);
  if (user->pseudo)
    write(user->socket, user->pseudo, strlen(user->pseudo));
  else
    write(user->socket, "Anonymous", 9);
  write(user->socket, "\n", 1);
  user->channel = -1;
  free(name);
  return (1);
}

int			send_message(char *cmd,
				     t_info_server *serv,
				     t_list_user *user)
{
  t_list_user		*tmp;

  tmp = serv->users;
  while (tmp)
    {
      if (tmp->channel == user->channel && tmp->id != user->id)
	{
	  write(tmp->socket, "\r\n", 2);
	  if (user->pseudo)
	    write(tmp->socket, user->pseudo, strlen(user->pseudo));
	  else
	    write(tmp->socket, "Anonymous", 9);
	  write(tmp->socket, " : ", 3);
	  write(tmp->socket, cmd, strlen(cmd));
	  write(tmp->socket, "\n", 1);
	}
      tmp = tmp->next;
    }
  write(user->socket, "xxx - The message has been sent", 31);
  return (1);
}
