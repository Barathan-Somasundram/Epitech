/*
** server.h<2> for  in /home/somasu_b/rendu/PSU_2014_myftp
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Mar 12 23:16:29 2015 SOMASUNDRAM Barathan
** Last update Fri Mar 13 00:27:32 2015 SOMASUNDRAM Barathan
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "my_ftp.h"

int		server_ftp(t_server*);
int		handle_client(t_server*);

char*		get_command(void);

#endif /* !SERVER_H_ */
