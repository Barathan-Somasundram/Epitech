/*
** minishell2.c for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 15:54:32 2014 somasu_b
** Last update Tue Mar  4 15:48:11 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "../Includes/my_string.h"
#include "../Includes/mysh.h"

int	minishell(void)
{
  while (42)
    {
      my_signal();
      my_prompt();
      if (cmd_center() == -1)
        {
          my_putstr("\n");
          return (-1);
        }
    }
  return (0);
}
