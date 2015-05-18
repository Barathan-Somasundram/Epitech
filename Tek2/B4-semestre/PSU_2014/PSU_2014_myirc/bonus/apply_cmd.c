/*
** server.c for server in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:32:19 2015 Potier Guillaume
** Last update Sun Apr 12 23:35:34 2015 potier_g
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

const t_fptr		tab_cmd[6] = {{"/server", &connect_server},
				      {"/nick", &fnc_nick},
				      {"/join", &fnc_join},
				      {"/part", &fnc_part},
				      {"/send_file", &fnc_send_file},
				      {"/accept_file", &fnc_accept_file}};

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

char			*my_read(int fd)
{
  char			*buffer;
  int			size;

  if ((buffer = malloc(512)) == NULL)
    return (NULL);
  if ((size = read(fd, buffer, 511)) <= 0)
    return (NULL);
  if (fd == 0)
    buffer[size - 1] = 0;
  return (buffer);
}

int			apply_cmd(t_info_client *client)
{
  char			*cmd;
  int			i;

  if ((cmd = my_read(0)) == NULL || strlen(cmd) == 0)
    return (1);
  i = 0;
  while (i < 6)
    {
      if (strncasecmp(cmd, tab_cmd[i].cmd, strlen(tab_cmd[i].cmd)) == 0)
	{
	  tab_cmd[i].fnc(cmd, client);
	  return (1);
	}
      i++;
    }
  if (client->fd > 0)
    return (write(client->fd, cmd, strlen(cmd) + 1));
  return (write(2, "Error - Connexion doesn't etablish\n", 35));
}
