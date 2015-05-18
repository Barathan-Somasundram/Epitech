/*
** connect.c for join in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:28:49 2015 Potier Guillaume
** Last update Sun Apr 12 21:38:43 2015 potier_g
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

char			*recup_ip(char *param)
{
  int			pos;

  pos = 0;
  while (param[pos] && param[pos] != ':')
    pos++;
  param[pos] = 0;
  return (param);
}

int			recup_port(char *param)
{
  int			pos;

  pos = 0;
  while (param[pos] && param[pos] != ':')
    pos++;
  if (param[pos] == 0)
    return (0);
  pos++;
  return (atoi(param + pos));
}

struct sockaddr		change_addr(char *host, u_short port)
{
  struct sockaddr_in	addr;
  struct sockaddr	addrRet;
  u_long		ip;

  memset((char*)&addr, 0, sizeof(addr));
  ip = inet_addr(host);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = ip;
  addr.sin_port = htons((u_short)port);
  memcpy((char *)&addrRet, (char *)&addr, sizeof(addrRet));
  return addrRet;
}

int			connect_server(char *cmd, t_info_client *info)
{
  char			*ip;
  int			port;
  int                   sock;

  if ((ip = recup_nparam(cmd, 1)) == NULL)
    return (write(2, "Usage : /server ip:port\n", 24));
  port = recup_port(ip);
  if ((ip = recup_ip(ip)) == NULL)
    return (write(2, "Bad Ip Parameter\n", 17));
 if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (write(2, "socket() error\n", 16));
  info->addr.sin_family = AF_INET;
  info->addr.sin_addr.s_addr = htonl (INADDR_ANY);
  info->addr.sin_port = htons((unsigned short)0);
  if (bind(sock, (struct sockaddr *)&info->addr, sizeof(info->addr)) == -1)
    return (write(2, "bind() error\n", 13));
  info->addrConnect = change_addr(ip, (u_short)port);
  if (connect(sock, &info->addrConnect, sizeof(info->addrConnect)) == -1)
    return (write(2, "Server not connected\n", 21));
  info->fd = sock;
  return (1);
}
