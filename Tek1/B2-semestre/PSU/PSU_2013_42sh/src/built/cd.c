/*
** cd.c for  in /home/sam_t/Workstation/PSU_2013_42sh/sam_t
**
** Made by sam_t
** Login   <sam_t@epitech.net>
**
** Started on  Sun May 25 15:38:07 2014 sam_t
** Last update Sun Jun  1 23:04:25 2014 a
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

static int	shcdaccess(char *pathname)
{
  if (access(pathname, F_OK) == -1)
    {
      fprintf(stderr, "42sh: cd: %s: No such file or directory\n", pathname);
      return (-1);
    }
  if (access(pathname, R_OK) == -1 || access(pathname, X_OK) == -1)
    {
      fprintf(stderr, "42sh : cd: %s: Permission denied\n", pathname);
      return (-1);
    }
  return (0);
}

static int	shcdhome(t_42 *sh)
{
  char		*home;
  char		*old_pwd;
  char		*new_pwd;

  if ((home = my_getvar(sh, "HOME")) == NULL)
    return (0);
  if ((old_pwd = my_getpwd()) == NULL)
    return (-1);
  if (shcdaccess(home) == -1)
    return (0);
  if (chdir(home) == -1)
    {
      fprintf(stderr, "42sh: cd: An error has happened\n");
      return (0);
    }
  if ((new_pwd = my_getpwd()) == NULL)
    return (-1);
  if (change_env(sh, old_pwd, "OLDPWD") == -1
      || change_env(sh, new_pwd, "PWD") == -1)
    return (-1);
  return (1);
}

static int	shcdreturn(t_42 *sh)
{
  char		*old_pwd;
  char		*new_pwd;

  if ((old_pwd = my_getpwd()) == NULL)
    return (-1);
  if ((new_pwd = my_getvar(sh, "OLDPWD")) == NULL)
    return (-1);
  if (shcdaccess(new_pwd) == -1)
    return (0);
  if (chdir(new_pwd) == -1)
    {
      fprintf(stderr, "42sh: cd: %s: No such file or directory\n", new_pwd);
      fprintf(stderr, "42sh: cd: An error has happened\n");
      return (0);
    }
  if (change_env(sh, old_pwd, "OLDPWD") == -1
      || change_env(sh, new_pwd, "PWD") == -1)
    return (-1);
  return (1);
}

static int	shcdnormal(t_42 *sh, t_tok *tmp_cmd)
{
  char		*old_pwd;
  char		*new_pwd;

  if ((old_pwd = my_getpwd()) == NULL)
    return (-1);
  if (shcdaccess(tmp_cmd->cmd) == -1)
    return (0);
  if (chdir(tmp_cmd->cmd) == -1)
    {
      fprintf(stderr, "42sh: cd: An error has happened\n");
      return (0);
    }
  if ((new_pwd = my_getpwd()) == NULL)
    return (-1);
  if (change_env(sh, old_pwd, "OLDPWD") == -1
      || change_env(sh, new_pwd, "PWD") == -1)
    return (-1);
  return (1);
}

int		sh_cd(t_42 *sh, t_tok *cmd)
{
  t_tok		*tmp_cmd;
  int		ret;

  if ((tmp_cmd = cmd->next->next) == cmd)
    {
      if ((ret = shcdhome(sh)) == -1 || ret == 0)
	return (ret);
    }
  else if (strcmp("-", tmp_cmd->cmd) == 0)
    {
      if ((ret = shcdreturn(sh)) == -1 || ret == 0)
	return (ret);
    }
  else
    if ((ret = shcdnormal(sh, tmp_cmd)) == -1 || ret == 0)
      return (ret);
  return (1);
}
