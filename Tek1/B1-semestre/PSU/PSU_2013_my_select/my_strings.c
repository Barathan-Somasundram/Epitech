/*
** my_strings.c for my_select in /home/somasu_b/TEST/select
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Jan 18 13:50:52 2014 somasu_b
** Last update Sat Jan 18 18:26:56 2014 a
*/

#include "my_select.h"

void	my_fd_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

int	tputchar(int c)
{
  int	fd;

  if ((fd = open("/dev/tty", O_WRONLY)) == -1)
    exit(0);
  write(fd, &c, 1);
  if (close(fd) == -1)
    exit(0);
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	i = i + 1;
    }
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	{
	  my_fd_putchar(str[i], 1);
	  i = i + 1;
	}
    }
}

void	my_tty_str(char *str)
{
  int	fd;
  int	i;

  i = 0;
  if ((fd = open("/dev/tty", O_WRONLY)) == -1)
    exit(0);
  while (str[i] != '\0')
    {
      my_fd_putchar(str[i], fd);
      i = i + 1;
    }
  if (close(fd) == -1)
    exit(0);
}
