/*
** users.c for users in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:31:27 2015 Potier Guillaume
** Last update Sun Apr 12 23:40:52 2015 potier_g
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

int			fnc_nick(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  t_list_user		*tmp;
  char			*nickname;

  if ((nickname = recup_nparam(cmd, 1)) == NULL)
    return (aff_error(0, user->socket, NULL, 431));
  tmp = serv->users;
  while (tmp)
    {
      if (tmp->pseudo != NULL && strcmp(nickname, tmp->pseudo) == 0
	  && user->id != tmp->id)
	return (aff_error(1, user->socket, nickname, 433));
      tmp = tmp->next;
     }
  write(user->socket, "xxx :Nickname changed successfully", 34);
  if (user->pseudo != NULL)
    free(user->pseudo);
  user->pseudo = nickname;
  return (1);
}

int			fnc_users(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  t_list_user		*tmp;

  (void)cmd;
  tmp = serv->users;
  write(user->socket, "List all users", 14);
  while (tmp)
    {
      if (tmp->channel == user->channel)
	{
	  write(user->socket, "\n353 : ", 7);
	  if (!tmp->pseudo)
	    write(user->socket, "***No nickname***", 17);
	  else
	    write(user->socket, tmp->pseudo, strlen(tmp->pseudo));
	}
      tmp = tmp->next;
    }
  write(user->socket, "\n366 #lol :End of /NAMES list", 29);
  return (1);
}

int			fnc_msg(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  char			*nickname;
  char			*msg;
  t_list_user		*tmp;

  if ((nickname = recup_nparam(cmd, 1)) == NULL
      || (msg = recup_nparam(cmd, 2)) == NULL)
    return (aff_error(2, user->socket, "/msg", 461));
  tmp = serv->users;
  while (tmp)
    {
      if (strcmp(tmp->pseudo, nickname) == 0 && tmp->channel == user->channel)
	{
	  write(tmp->socket, "\r\n", 2);
	  if (user->pseudo == NULL)
	    write(tmp->socket, "Anonymous", 9);
	  else
	    write(tmp->socket, user->pseudo, strlen(user->pseudo));
	  write(tmp->socket, " : ", 3);
	  write(tmp->socket, msg, strlen(msg));
	  write(user->socket, "The message has been sent", 25);
	  return (1);
	}
      tmp = tmp->next;
    }
  return (aff_error(3, user->socket, nickname, 401));
}
