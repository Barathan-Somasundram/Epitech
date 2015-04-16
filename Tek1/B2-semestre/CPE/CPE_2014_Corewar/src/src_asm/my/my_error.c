/*
** my_error.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Apr  3 17:42:47 2014 taille_a
** Last update Sat Apr 12 13:57:53 2014 taille_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "asm.h"

int		error_main(char *file_name)
{
  write(2, "Usage: ./Asm ", 13);
  if (file_name != NULL)
    write(2, file_name, my_strlen(file_name));
  else
    write(2, "file_name", 9);
  return (write(2, "[.s]\n", 6));
}

int		error_invalid_file(int line, char *msg)
{
  write(2, msg, my_strlen(msg));
  write(2, " ", 1);
  my_putnbr(line);
  write(2, "\n", 1);
  return (INVALID_FILE);
}

int		fct_msg_error(char *str, int ret_val)
{
  write(2, str, my_strlen(str));
  if (ret_val > 0)
    return (ret_val);
  else
    exit(1);
}

int		fct_err_line(int line, char *m_line, int type)
{
  write(2, "Error at line #", 15);
  my_putnbr(line);
  if (type == 1)
    write(2, " : Syntax error\n", 16);
  else
    write(2, " : Unknown directive\n", 21);
  write(2, m_line, my_strlen(m_line));
  write(2, "\n", 1);
  return (INVALID_FILE);
}
