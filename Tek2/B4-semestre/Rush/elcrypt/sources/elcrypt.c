/*
** elcrypt.c for  in /home/somasu_b/rendu/elcrypt/sources
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 18:17:28 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:50:48 2015 SOMASUNDRAM Barathan
*/

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "elcrypt.h"

int			recup_arg(int ac, char **av, t_elcrypt *param)
{
  int			arg;
  int			incr;

  arg = 1;
  while (arg < ac)
    {
      if ((incr = flag_action(av, arg, param)) == -1)
	return (-1);
      else if (incr == 0 && (incr = flag_file(ac, av, arg, param)) == -1)
	return (-1);
      else if (incr == 0 && (incr = flag_key(ac, av, arg, param)) == -1)
	return (-1);
      arg += incr;
    }
  if (param->action == -1 || !param->in || !param->out || !param->key)
    return (-1);
  return (1);
}

char			*cut_bloc(char *block, int part)
{
  char			*semi;
  int			i;
  int			more;

  i = 0;
  if ((semi = malloc(33)) == NULL)
    return (NULL);
  more = part * 32;
  while (i < 32)
    {
      semi[i] = block[more];
      i++;
      more++;
    }
  semi[32] = 0;
  return (semi);
}

char			*convert_or(char *bloc_32, char *key)
{
  int			pos;
  char			*ret;

  if ((ret = malloc(33)) == NULL)
    return (NULL);
  pos = 0;
  while (pos < 32)
    {
      ret[pos] = ((bloc_32[pos] - 48) ^ (key[pos] - 48)) + 48;
      pos++;
    }
  ret[pos] = 0;
  printf("%s ^ %s = %s\n", bloc_32, key, ret);
  return (ret);
}

int			elcrypt(t_elcrypt *param)
{
  if ((param->fd_in = open(param->in, O_RDONLY)) == -1)
    {
      fprintf(stderr, "Bad file %s\n", param->in);
      return (-1);
    }
  if ((param->fd_out = creat(param->out, S_IRWXU)) == -1)
    return (-1);
  if ((param->key_dec = get_key(param->key)) == -1)
    return (-1);
  param->key_bin = convert_key_bin(param->key_dec);
  if (param->action == 0)
    decrypt(param);
  else if (param->action == 1)
    crypt(param);
  close(param->fd_in);
  close(param->fd_out);
  return (0);
}

int			main(int ac, char **av)
{
  t_elcrypt		param;

  param.action = -1;
  param.in = NULL;
  param.out = NULL;
  param.key = NULL;
  if (recup_arg(ac, av, &param) == -1)
    {
      write(2, "Usage : =>\n", 11);
      return (-1);
    }
  elcrypt(&param);
  return (1);
}
