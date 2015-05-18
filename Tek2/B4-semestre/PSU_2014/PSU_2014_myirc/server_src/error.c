/*
** error.c for error in /run/media/potier_g/0711b939-2396-441a-9f27-d84bc95200be/home/potier_g/rendu/PSU_2014_myirc
** 
** Made by Potier Guillaume
** Login   <potier_g@epitech.net>
** 
** Started on  Sun Apr 12 16:32:10 2015 Potier Guillaume
** Last update Sun Apr 12 23:34:27 2015 potier_g
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

const char		*tab_nb[6] = {"431 ",
				      "433 ",
				      "461 ",
				      "403 ",
				      "403 ",
				      "403 "};

const char		*tab_error[6] = {":No nickname given",
					 " :Nickname is already in use",
					 " :Not enough parameters",
					 " :No such nick/channel",
					 " :You're not on that channel",
					 " :Error happened during the creation"};

int			aff_error(int error, int fd, char *param, int nb)
{
  (void)nb;
  write(fd, tab_nb[error], 4);
  if (error > 0)
    {
      write(fd, param, strlen(param));
      write(fd, tab_error[error], strlen(tab_error[error]));
    }
  else
    write(fd, tab_error[error], strlen(tab_error[error]));
  return (1);
}
