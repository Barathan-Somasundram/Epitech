/*
** serv_cmd.c for serv in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:31:36 2015 Potier Guillaume
** Last update Sun Apr 12 16:53:29 2015 Potier Guillaume
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

const t_fptr		tab_cmd[8] = {{"/nick", &fnc_nick},
				      {"/list", &fnc_list},
				      {"/join", &fnc_join},
				      {"/part", &fnc_part},
				      {"/users", &fnc_users},
				      {"/msg", &fnc_msg},
				      {"/send_file", &fnc_send_file},
				      {"/accept_file", &fnc_accept_file}};

char			*my_read(int fd)
{
  char			*buffer;
  int			size;

  if ((buffer = malloc(512)) == NULL)
    return (NULL);
  if ((size = read(fd, buffer, 511)) <= 0)
    return (NULL);
  buffer[size - 1] = 0;
  return (buffer);
}

char			*cut_str(char *msg, int start, int end)
{
  char			*ret;
  int			i;

  if ((ret = malloc((end - start) + 2)) == NULL)
    return (NULL);
  i = 0;
  while (start <= end)
    {
      ret[i] = msg[start];
      i++;
      start++;
    }
  ret[i] = 0;
  return (ret);
}

char			*recup_nparam(char *msg, int pos_param)
{
  int			pos;
  int			nb_param;
  int			start;
  int			end;

  nb_param = 0;
  pos = 0;
  while (nb_param < pos_param && msg[pos])
    {
      if (msg[pos] == ' ' || msg[pos] == '\t')
	{
	  nb_param++;
	  while ((msg[pos] == ' ' || msg[pos] == '\t') && msg[pos])
	    pos++;
	}
      pos++;
    }
  if (msg[pos] == 0)
    return (NULL);
  start = pos - 1;
  end = start;
  while (msg[end] != ' ' && msg[end] != '\t' && msg[end])
    end++;
  return (cut_str(msg, start, end - 1));
}

char			*rewrite_cmd(char *msg)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (msg[i] != '\0' && (msg[i] == ' ' || msg[i] == '\t'))
    i++;
  while (msg[i] != '\0')
    {
      msg[j] = msg[i];
      i++;
      j++;
    }
  msg[j] = 0;
  return (msg);
}

int			recup_cmd(t_info_server *server, t_list_user *current_user)
{
  int			i;
  char			*msg;

  i = 0;
  if ((msg = my_read(current_user->socket)) == NULL)
    return (delete_user(current_user));
  msg = rewrite_cmd(msg);
  if (!msg || strlen(msg) == 0)
    return (1);
  while (i < 8)
    {
      if (strncasecmp(msg, tab_cmd[i].cmd, strlen(tab_cmd[i].cmd)) == 0)
	{
	  tab_cmd[i].fnc(msg, server, current_user);
	  write(current_user->socket, "\r\n", 2);
	  free(msg);
	  return (1);
	}
      i++;
    }
  send_message(msg, server, current_user);
  write(current_user->socket, "\r\n", 2);
  free(msg);
  return (1);
}
