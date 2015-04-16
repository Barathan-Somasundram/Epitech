/*
** prompt.c for minishell2 in /home/somasu_b/TEST/mysh2/Sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Mar  4 15:46:59 2014 somasu_b
** Last update Sun Mar  9 21:42:17 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../Includes/my_string.h"
#include "../Includes/mysh.h"

static void	free_prompt_util(char *hostname, char *name, char *pwd)
{
  if (hostname != NULL)
    free(hostname);
  if (name != NULL)
    free(name);
  if (pwd != NULL)
    free(pwd);
}

static void	prompt_info(char **hostname, char **name, char **pwd)
{
  *hostname = my_get_hostname();
  *name = my_get_name();
  *pwd = my_get_pwd();
  if (*hostname == NULL)
    {
      free(*hostname);
      *hostname = my_strdup("anonyme");
    }
  if (*name == NULL)
    {
      free(*name);
      *name = my_strdup("anonyme");
    }
  if (*pwd == NULL)
    {
      free(*pwd);
      *pwd = my_strdup("Unknown");
    }
}

void	my_prompt(void)
{
  char	*hostname;
  char	*name;
  char	*pwd;

  prompt_info(&hostname, &name, &pwd);
  my_putstr(B_WHITE "(" B_CYAN);
  my_putstr(name);
  my_putstr(B_WHITE "@" B_RED);
  my_putstr(hostname);
  my_putstr(B_WHITE ") " B_GREEN);
  my_putnbr(g_mysh.counter);
  my_putstr(B_WHITE " :" S_BLUE);
  my_putstr(pwd);
  my_putstr("\n" B_MAGENTA " → " NORMAL);
  free_prompt_util(hostname, name, pwd);
}
