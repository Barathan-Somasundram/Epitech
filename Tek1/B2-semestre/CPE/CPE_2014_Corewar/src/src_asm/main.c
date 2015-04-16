/*
** main.c for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 10:37:36 2014 taille_a
** Last update Sun Apr 13 17:29:19 2014 a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "asm.h"
#include "op.h"
#include "my.h"

int		read_file(char *buff, t_list **list)
{
  t_list	*elem;
  char		*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if ((tmp = my_epurstr(buff)) == NULL)
    return (-1);
  if (tmp[0] == COMMENT_CHAR || tmp[0] == '\0')
    {
      free(tmp);
      return (2);
    }
  elem->buff = tmp;
  elem->ne_buff = buff;
  elem->next = *list;
  elem->token_list = NULL;
  if ((*list)!= NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

int		search_file(int fd, t_list **list)
{
  char		*buff;
  int		i;
  int		verif;

  i = 0;
  while ((buff = get_next_line(fd)) != NULL)
    {
      if ((verif = read_file(buff, list)) == -1)
	return (-2);
      else if (verif != 2)
	(*list)->line = i + 1;
      if ((*list) != NULL)
	init_value_in_list(list);
      ++i;
    }
  if ((*list) == NULL)
    return (-1);
  (*list)->prev = NULL;
  while ((*list)->next != NULL)
    (*list) = (*list)->next;
  close(fd);
  return (0);
}

int		verif_file(char *file_name, t_list **list)
{
  int		fd;
  char		*file_name_s;

  if ((file_name_s = my_strcat(file_name, ".s")) == NULL)
    return (fct_msg_error("Can't perform malloc\n", -1));
  if ((fd = open(file_name_s, O_RDONLY)) == -1)
    {
      if (file_name[my_strlen(file_name) - 2] != '.' ||
	  file_name[my_strlen(file_name) - 1] != 's')
	{
	  write(2, "File ", 5);
	  write(2, file_name_s, my_strlen(file_name_s));
	  return (fct_msg_error(" not accessible\n", -1));
	}
      if ((fd = open(file_name, O_RDONLY)) == -1)
	{
	  write(2, "File ", 5);
	  write(2, file_name, my_strlen(file_name));
	  return (fct_msg_error(" not accessible\n", -1));
	}
    }
  free(file_name_s);
  if ((search_file(fd, list)) < -1)
    return (fct_msg_error("Can't perform malloc\n", -1));
  return (0);
}

void		init_header(header_t *header, t_list **list, int *is_name)
{
  (*list) = NULL;
  header->magic = COREWAR_EXEC_MAGIC;
  header->magic = swap_byte(header->magic);
  header->prog_size = 0;
  *is_name = 0;
}

int		main(int ac, char **av)
{
  t_list	*list;
  header_t	header;
  int		i;
  int		is_name;

  i = 1;
  if (ac < 2)
    return (error_main(av[1]));
  while (av[i])
    {
      init_header(&header, &list, &is_name);
      if ((verif_file(av[i], &list)) == -1)
	return (-1);
      if ((parse_code(&list, &header)) != 0)
	return (0);
      else
	is_name = 1;
      if ((parse_comment(&list, &header, is_name)) != 0)
      	return (INVALID_FILE);
      if ((parser_command(&list)) != 0)
	return (0);
      write_cor_file(&list, &header, av[i++]);
     }
  free_all(&list);
  return (0);
}
