/*
** compile_msg.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Apr 10 00:17:45 2014 taille_a
** Last update Sat Apr 12 15:48:59 2014 taille_a
*/

#include <unistd.h>
#include "op.h"
#include "my.h"

int		compile_msg(header_t *header, char *file_name, int fd)
{
  write(1, "Compiled ", 9);
  write(1, file_name, my_strlen(file_name));
  write(1, ":\n", 2);
  write(1, "\t\t", 2);
  write(1, header->prog_name, my_strlen(header->prog_name));
  write(1, "\n", 1);
  write(1, "\t\t", 2);
  write(1, header->comment, my_strlen(header->comment));
  write(1, "\n", 1);
  close(fd);
  return (0);
}
