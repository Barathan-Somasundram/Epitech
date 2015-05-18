/*
** client.h for clinet in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:29:23 2015 Potier Guillaume
** Last update Sun Apr 12 21:42:11 2015 potier_g
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

typedef struct		s_info_client
{
  fd_set		readfds;
  struct sockaddr_in	addr;
  struct sockaddr	addrConnect;
  int			fd;
  char			*login;
  char			*channel;
}			t_info_client;

typedef struct		s_fptr
{
  char			*cmd;
  int			(*fnc)(char *, t_info_client *);
}			t_fptr;

int			recup_resp(t_info_client *client);
int			apply_cmd(t_info_client *client);
char			*recup_nparam(char *msg, int pos_param);

char			*my_read(int fd);

int			connect_server(char *cmd, t_info_client *client);
int			fnc_nick(char *cmd, t_info_client *client);
int			fnc_join(char *cmd, t_info_client *client);
int			fnc_part(char *cmd, t_info_client *client);
int			fnc_send_file(char *cmd, t_info_client *client);
int			fnc_accept_file(char *cmd, t_info_client *client);

#endif /* !CLIENT_H_ */
