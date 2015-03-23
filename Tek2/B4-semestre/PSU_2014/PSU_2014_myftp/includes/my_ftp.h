/*
** my_ftp.h for  in /home/somasu_b/rendu/PSU_2014_myftp/sources/server
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Mar 10 22:03:24 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 22 12:35:33 2015 SOMASUNDRAM Barathan
*/

#ifndef MY_FTP_H_
# define MY_FTP_H_

# include <sys/types.h>
# include <sys/socket.h>

# define MSG_WELCOME		"Welcome ! To the FTP Server\n"

# define USAGE_SERVER		"Usage: ./server [port]"
# define USAGE_CLIENT		"Usage: ./client [hostname] [port]"

# define ERR_PORT		"Error: port number is not correct\n"
# define ERR_HAPPEND		"Error: Something has occured\n"
# define ERR_CLOSE		"Error: Cannot close fd\n"
# define ERR_LISTEN		"Error: While listening...\n"
# define ERR_BIND		"Error: While binding ...\n"
# define ERR_SOCKET		"Error: Cannot create socket\n"
# define ERR_PROTO		"Error: Cannot get protocol number\n"
# define ERR_ACCEPT		"Error: Cannot accept client\n"

# define RFC_120		"Service ready in nnn minutes."
# define RFC_125		"Data connection already open; transfer starting."
# define RFC_150		"File status okay; about to open data connection."
# define RFC_200		"Command okay."
# define RFC_214		("Help message.\nOn how to use the server or the meaning of a particular\n"
				"non-standard command. This reply is useful only to the\nhuman user.")
# define RFC_220		"Service ready for new user."
# define RFC_221		"Service closing control connection.\nogged out if appropriate."
# define RFC_226		"Closing data connection.\nRequested file action successful" // or failure
# define RFC_230		"User logged in, proceed"
# define RFC_250		"Requested file action okay, completed."
# define RFC_257		"\"PATHNAME\" created."
# define RFC_331		"User name okay, need password."
# define RFC_332		"Need account for login."
# define RFC_xxx		"Error: "

# define PROMPT			"my_ftp[%s][%s]>"
# define MAX_CLIENT		10
# define PATH_SIZE		4096

typedef struct protoent		t_proto;
typedef struct sockaddr_in	t_socket;

typedef struct	s_client
{
  int		fd;
  char*		ip;
  t_socket	s_in;
  socklen_t	s_in_size;
  int		id;
  int		port;
}		t_client;

typedef struct	s_server
{
  int		port;
  t_proto*	pe;
  int		fd;
  t_socket	s_in;
  t_client	client;

  char		path[PATH_SIZE];
  int		timeout;
  int		root;
}		t_server;

#endif /* !MY_FTP_H_ */
