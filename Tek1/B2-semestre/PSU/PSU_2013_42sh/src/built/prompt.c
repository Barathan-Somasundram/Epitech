/*
** prompt.c for 42sh in /home/somasu_b/rendu/mysh/src/built
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu May 15 21:26:09 2014 somasu_b
** Last update Fri May 30 15:32:46 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sh.h"

static void	my_putnbr(int nb)
{
  char		tmp;

  if (nb < 0)
    nb = -nb;
  if (nb < 10)
    {
      tmp = nb + '0';
      write(STDOUT_FILENO, &tmp, 1);
    }
  else
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
}

static void	putstr_prompt(char *str)
{
  write(STDOUT_FILENO, str, strlen(str));
}

static void	prompt_info(t_42 *sh, char **login, char **host, char **pwd)
{
  t_env		*tmp;

  if ((*pwd = my_getpwd()) == NULL)
    *pwd = strdup("Unknown");
  tmp = sh->env->next;
  while (tmp != sh->env && strcmp(tmp->var, "LOGNAME") != 0)
    tmp = tmp->next;
  if (tmp == sh->env || tmp->contents == NULL)
    *login = "Unknown";
  else
    *login = tmp->contents;
  tmp = sh->env->next;
  while (tmp != sh->env && strcmp(tmp->var, "HOST") != 0)
    tmp = tmp->next;
  if (tmp == sh->env || tmp->contents == NULL)
    *host = "Unknown";
  else
    *host = tmp->contents;
}

int	sh_prompt(t_42 *sh)
{
  char	*login;
  char	*mail;
  char	*pwd;

  prompt_info(sh, &login, &mail, &pwd);
  putstr_prompt(B_WHITE "(" B_CYAN);
  putstr_prompt(login);
  putstr_prompt(B_WHITE "@" B_RED);
  putstr_prompt(mail);
  putstr_prompt(B_WHITE ") " B_GREEN);
  my_putnbr(sh->counter);
  putstr_prompt(B_WHITE " :" S_BLUE);
  putstr_prompt(pwd);
  putstr_prompt(B_MAGENTA "\n → " NORMAL);
  if (pwd != NULL)
    free(pwd);
  return (0);
}
