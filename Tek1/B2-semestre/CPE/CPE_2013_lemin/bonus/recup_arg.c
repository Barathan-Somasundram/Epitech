/*
** recup_arg.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sat Apr 26 17:04:09 2014 potier_g
** Last update Sun May  4 22:55:04 2014 potier_g
*/

#include <stdlib.h>
#include "struct.h"

char	*recup_line(char *file, int nb_line)
{
  int	line_act;
  int	pos;
  int	pos_tmp;
  int	a;
  char	*new_line;

  line_act = 0;
  pos = 0;
  a = 0;
  while (file[pos] != '\0' && line_act < nb_line)
    if (file[pos++] == '\n')
      line_act++;
  if (file[pos] == '\0')
    return (NULL);
  pos_tmp = pos;
  while (file[pos_tmp] != '\0' && file[pos_tmp] != '\n')
    pos_tmp++;
  if ((new_line = my_malloc((pos_tmp - pos) + 2)) == NULL)
    return (NULL);
  while (file[pos] != '\0' && file[pos] != '\n')
    new_line[a++] = file[pos++];
  new_line[a] = '\0';
  return (new_line);
}

char    *recup_word(char *line, int nb_word)
{
  char  *new_word;
  int   word_act;
  int   pos;
  int   pos_tmp;
  int   a;

  word_act = 0;
  pos = 0;
  a = 0;
  while (line[pos] != '\0' && word_act < nb_word)
    if (line[pos++] == ' ' || line[pos - 1] == '-')
      word_act++;
  if (line[pos] == '\0')
    return (NULL);
  pos_tmp = pos;
  while (line[pos_tmp] != '\0' && line[pos_tmp] != '\n')
    pos_tmp++;
  if ((new_word = my_malloc((pos_tmp - pos) + 2)) == NULL)
    return (NULL);
  while (line[pos] != '\0' && line[pos] != '\n'
         && line[pos] != ' ' && line[pos] != '-')
    new_word[a++] = line[pos++];
  new_word[a] = '\0';
  return (new_word);
}
