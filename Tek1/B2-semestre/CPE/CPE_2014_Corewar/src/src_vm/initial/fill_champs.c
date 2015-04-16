/*
** fill_champs.c for corewar in /home/somasu_b/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri Apr  4 17:29:55 2014 somasu_b
** Last update Sun Apr 13 18:40:51 2014 a
*/

#include "vm.h"
#include "my_strings.h"

int		fill_champs_header(header_t *header, const int fd)
{
  unsigned char	buffer_magic[MAGIC_SIZE];
  unsigned char	buffer_size[PROG_SIZE_LENGTH + 1];
  char		nothing_todo[4];
  int		ret;

  if ((ret = read(fd, buffer_magic, MAGIC_SIZE)) == -1)
    return (-1);
  header->magic = ((buffer_magic[0] * 256 + buffer_magic[1])
		   * 256 + buffer_magic[2]) * 256 + buffer_magic[3];
  if ((ret = read(fd, header->prog_name, PROG_NAME_LENGTH)) == -1)
    return (-1);
  header->prog_name[ret + 1] = '\0';
  if ((ret = read(fd, buffer_size, PROG_SIZE_LENGTH)) == -1)
    return (-1);
  buffer_size[ret + 1] = '\0';
  ret = -1;
  header->prog_size = 0;
  while (++ret < PROG_SIZE_LENGTH)
    header->prog_size = (header->prog_size * 256) + buffer_size[ret];
  if ((ret = read(fd, header->comment, COMMENT_LENGTH)) == -1)
    return (-1);
  header->comment[ret + 1] = '\0';
  if ((ret = read(fd, nothing_todo, 4)) == -1)
    return (-1);
  return (0);
}

int		fill_champs_code(t_champs **elem, const int fd)
{
  unsigned char	buffer[READ_SIZE + 1];
  int		total;
  int		ret;
  int		i;

  total = 0;
  ret = 0;
  while ((ret = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[ret + 1] = '\0';
      i = 0;
      if (total + ret > MAX_PROG_SIZE)
	return (my_perror("Error : Champion is too big\n", NULL));
      while (i < ret)
	{
	  (*elem)->commands[total] = buffer[i];
	  ++total;
	  ++i;
	}
    }
  (*elem)->commands[total] = '\0';
  if (total != (*elem)->header.prog_size)
    return (my_perror("Error : Wrong prog_size\n", NULL));
  return (0);
}

int		check_champs_header(header_t *header)
{
  if (header->magic != COREWAR_EXEC_MAGIC)
    return (my_perror("Error : wrong magic code\n", NULL));
  if (header->prog_size < 0)
    return (my_perror("Error : prog_size cannot be negativ\n", NULL));
  if (header->prog_size > MAX_PROG_SIZE)
    return (my_perror("Error : Champion file is too big\n", NULL));
  return (0);
}

int		fill_champs_data(t_champs **elem, int number, int address, int fd)
{
  int		i;

  i = 0;
  (*elem)->address = address;
  (*elem)->my_number = number;
  (*elem)->my_father = 0;
  (*elem)->carry = 0;
  while (i < REG_NUMBER)
    (*elem)->registers[i++] = 0;
  (*elem)->registers[REG_01] = number;
  (*elem)->cycle_to_live = 0;
  (*elem)->cycle_to_exec = 0;
  (*elem)->if_live = 1;
  if (fill_champs_header(&((*elem)->header), fd) == -1)
    return (-1);
  if (check_champs_header(&((*elem)->header)) == -1)
    return (-1);
  if (fill_champs_code(elem, fd) == -1)
    return (-1);
  return (0);
}
