/*
** algo.c for  in /home/somasu_b/rendu/elcrypt/sources
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 18:47:26 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:48:32 2015 SOMASUNDRAM Barathan
*/

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "elcrypt.h"

char			*feistel(char *bloc, char *key)
{
  char			*sem1;
  char			*sem2;
  char			*tmp;
  char			*ret;
  int i = 0;

  if ((sem1 = cut_bloc(bloc, 0)) == NULL || (sem2 = cut_bloc(bloc, 1)) == NULL)
    return (NULL);
  if ((ret = malloc(9)) == NULL)
    return (NULL);
  ret[0] = 0;
  tmp = bin32_to_string(convert_or(sem1, key));
  i = -1;
  while (++i < 4)
    ret[i] = tmp[i];
  tmp = bin32_to_string(convert_or(sem2, key));
  i = 3;
  while (++i < 8)
    ret[i] = tmp[i - 4];
  ret[8] = 0;
  return (ret);
}

int			aff_in_file(int fd, char *str)
{
  int			i;
  int			pos;

  pos = 8;
  i = 0;
  while (i < pos)
    {
      write(fd, &(str[i]), 1);
      i++;
    }
  return (0);
}

int			crypt(t_elcrypt *p)
{
  int			s;
  char			*blc;
  int			t;
  char			*crypt;
  int			pad;

  if ((blc = malloc(9)) == NULL)
    return (-1);
  t = 0;
  while ((s = read(p->fd_in, blc, 8)) == 8)
    {
      blc[9] = 0;
      if (!(crypt = feistel(convert_bin(blc, s), rotate_key(p->key_bin, t))))
	return (-1);
      write(p->fd_out, crypt, 8);
      t++;
    }
  pad = 8 - s;
  while (s < 8)
    blc[s++] = pad;
  blc[9] = 0;
  if (!(crypt = feistel(convert_bin(blc, s), rotate_key(p->key_bin, t))))
    return (-1);
  write(p->fd_out, crypt, 8);
  return (0);
}

int			decrypt(t_elcrypt *p)
{
  int			s;
  char			*bloc;
  int			t;
  char			*crypt;

  if ((bloc = malloc(9)) == NULL)
    return (-1);
  t = 0;
  while ((s = read(p->fd_in, bloc, 8)) == 8)
    {
      bloc[s + 1] = 0;
      if (!(crypt = feistel(convert_bin(bloc, s), rotate_key(p->key_bin, t))))
	return (-1);
      aff_in_file(p->fd_out, crypt);
      t++;
    }
  return (0);
}
