/*
** client.h for  in /home/somasu_b/rendu/PSU_2014_myftp/includes
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Mar 13 00:26:09 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 22 20:25:42 2015 SOMASUNDRAM Barathan
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "my_ftp.h"

typedef struct	s_func
{
  char*		cmd;
  int		(*function)(t_client*, char*);
}		t_func;

t_func		command[7] = 
  {
    {"help", &my_help},
    {"quit", &my_quit},
    {"ls", &my_ls},
    {"pwd", &my_pwd},
    {"cd" &my_cd},
    {"get", &my_get},
    {"put", &my_put}
  };

#endif /* !CLIENT_H_ */
