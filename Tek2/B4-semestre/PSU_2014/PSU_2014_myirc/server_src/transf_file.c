/*
** transf_file.c for transf in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:31:32 2015 Potier Guillaume
** Last update Sun Apr 12 22:59:02 2015 potier_g
*/

#include <string.h>
#include "server.h"

int			fnc_send_file(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  (void)cmd;
  (void)serv;
  (void)user;
  return (1);
}

int			fnc_accept_file(char *cmd,
				 t_info_server *serv,
				 t_list_user *user)
{
  char			*name;
  t_list_user		*tmp;
  int			acc;

  if ((name = recup_nparam(cmd, 1)) == NULL)
    return (aff_error(2, user->socket, "/accept_file", 461));
  tmp = serv->users;
  acc = 0;
  while (tmp && acc == 0)
    {
      if (tmp->pseudo && strcmp(tmp->pseudo, name) == 0
	  && tmp->channel == user->channel)
	{
	  acc = 1;
	  user->accept = tmp->id;
	}
      if (acc == 0)
	tmp = tmp->next;
    }
  if (acc == 0)
    return (aff_error(3, user->socket, name, 461));
  return (1);
}
