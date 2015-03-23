/*
** command.c for  in /home/somasu_b/rendu/PSU_2014_myftp/sources/client
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 22 20:27:17 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 22 20:32:28 2015 SOMASUNDRAM Barathan
*/

#include "client.h"

int			my_ls(t_client* client, char* arg)
{
  char			buffer[BUFFER_SIZE + 1];
  int			ret;

  write(client->fd, "ls", 2);
  if ((ret = read()
}

int		client_read_sock(int sock_dest, char *buf, int size)
{
  int		ret;

  memset(buf, 0, size);
  ret = read(sock_dest, buf, size);
  return ((ret >= 0) ? ret : IWARNING);
}
