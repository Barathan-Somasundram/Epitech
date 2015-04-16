/*
** write_cor_file.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Apr  3 10:57:37 2014 taille_a
** Last update Sat Apr 12 16:30:57 2014 taille_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "asm.h"

int		search_label(t_list **list, char *label)
{
  int		nbr;
  t_list	*elem;

  elem = *list;
  if (label[0] == LABEL_CHAR)
    label = epur_str(label, 1);
  else
  label = epur_str(label, 2);
  if ((nbr = label_search_down(&elem, label)) >= 0)
    return (nbr);
  if ((nbr = label_search_up(&elem, label)) <= 0)
    return (nbr);
  else
    {
      write(2, "The label ", 10);
      write(2, label, my_strlen(label));
      write(2, " is undefined line ", 19);
      my_putnbr(elem->line);
      my_exit(list, "\n");
    }
  return (0);
}

char		*write_op_code(t_list **list,
			       int *size, char *buff, int line)
{
  t_toke	*elem;
  int		cpt;
  int		mem_set;

  cpt = *size;
  mem_set = *size;
  *size += (*list)->byte_used + 1;
  if ((buff = realloc(buff, ((*size) + 10))) == NULL)
    return (NULL);
  while (mem_set < *size)
    buff[mem_set++] = '\0';
  elem = (*list)->token_list;
  buff[cpt++] = (*list)->op_code;
  if ((*list)->code)
    buff[cpt++] = (*list)->code;
  buff = put_value_to_buffer(list, elem, cpt, buff);
  return (buff);
}

char		*name_the_cor(char *file_name)
{
  char		*file_name_cor;
  int		i;

  i = 0;
  if ((file_name_cor = malloc(sizeof(char) *
			      (my_strlen(file_name) + 5) + 1)) == NULL)
    return (NULL);
  while (file_name[i] != '.' && file_name[i] != '\0')
    ++i;
  file_name_cor = my_strcpy(file_name_cor, file_name);
  file_name_cor[i] = '\0';
  file_name_cor = my_strcat(file_name_cor, ".cor");
  return (file_name_cor);
}

int		write_cor_file(t_list **list,
			       header_t *header, char *file_name)
{
  t_list	*elem;
  int		fd;
  char		*buff;
  char		*file_cor;

  file_cor = name_the_cor(file_name);
  elem = *list;
  buff = NULL;
  while (elem != NULL)
    {
      if (elem->token_list != NULL)
      	if ((buff = write_op_code(&elem, &header->prog_size,
				  buff, elem->line)) == NULL)
	  my_exit(list, "Can't perform malloc\n");
      elem = elem->prev;
    }
  if ((fd = open(file_cor, O_CREAT | O_TRUNC | O_RDWR, RIGHTS)) == -1)
    my_exit(list, "Can't access file");
  header->prog_size = swap_byte(header->prog_size);
  write(fd, header, sizeof(header_t));
  header->prog_size = swap_byte(header->prog_size);
  write(fd, buff, header->prog_size);
  free(file_cor);
  free(buff);
  return (compile_msg(header, file_name, fd));
}
