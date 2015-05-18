/*
** server.h for server in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:29:19 2015 Potier Guillaume
** Last update Sun Apr 12 22:58:18 2015 potier_g
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#include <stdio.h>

typedef struct		s_list_user
{
  int			id;
  int			socket;
  char			*pseudo;
  int			channel;
  int			accept;
  struct s_list_user	*next;
}			t_list_user;

typedef struct		s_list_channel
{
  int			id;
  char			*name;
  struct s_list_channel	*next;
}			t_list_channel;

typedef struct		s_info_server
{
  fd_set		readfds;
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			fd;
  t_list_user		*users;
  t_list_channel	*channels;
}			t_info_server;

typedef struct		s_fptr
{
  char			*cmd;
  int			(*fnc)(char *, t_info_server *, t_list_user *);
}			t_fptr;

int			new_user(t_info_server *server, int sock);
int			max_sock(t_info_server *server);
int			recup_cmd(t_info_server *server, t_list_user *user);

void			connect_ok(int fd);

char			*recup_nparam(char *msg, int pos_param);

int			fnc_nick(char *, t_info_server *, t_list_user *);
int			fnc_list(char *, t_info_server *, t_list_user *);
int			fnc_join(char *, t_info_server *, t_list_user *);
int			fnc_part(char *, t_info_server *, t_list_user *);
int			fnc_users(char *, t_info_server *, t_list_user *);
int			fnc_msg(char *, t_info_server *, t_list_user *);
int			fnc_send_file(char *, t_info_server *, t_list_user *);
int			fnc_accept_file(char *, t_info_server *, t_list_user *);

t_list_channel		*new_channel(char *, t_list_channel *, int *);
int			if_exist(char *name, t_list_channel *channel);
int			send_message(char *, t_info_server *, t_list_user *);

int			delete_user(t_list_user *current_user);

int			aff_error(int error, int fd, char *param, int nb);

void			erase_users_list(t_info_server *info);
void			erase_channel_list(t_info_server *info);

#endif /* !SERVER_H_ */
