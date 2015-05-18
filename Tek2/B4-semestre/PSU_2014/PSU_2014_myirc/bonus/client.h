/*
** client.h for clinet in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:29:23 2015 Potier Guillaume
** Last update Sun Apr 12 23:36:28 2015 potier_g
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <gtk/gtk.h>

# define HEIGHT		450
# define WIDTH		750

typedef struct		s_gtk
{
  GtkWidget*		win;
  GtkWidget*		win_box;

  GtkWidget*		menu_box;
  GtkWidget*		barmenu;

  GtkWidget*		filemenu;
  GtkWidget*		file;
  GtkWidget*		quit;

  GtkWidget*		channel_box;
  GtkWidget*		channel;
  GtkWidget*		listChannel;

  GtkWidget*		dialog_box;
  GtkWidget*		dialog;
  GtkWidget*		entry;
  GtkWidget*		show;
  GtkWidget*		text_view;

  GtkWidget*		user_box;
  GtkWidget*		user;
  GtkWidget*		listUser;
}			t_gtk;

typedef struct		s_info_client
{
  fd_set		readfds;
  struct sockaddr_in	addr;
  struct sockaddr	addrConnect;
  int			fd;
  char			*login;
  char			*channel;
  t_gtk			*gui;
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
