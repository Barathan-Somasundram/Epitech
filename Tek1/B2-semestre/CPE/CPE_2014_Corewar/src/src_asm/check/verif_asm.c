/*
** verif_asm.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Thu Mar 27 10:20:29 2014 taille_a
** Last update Sun Apr 13 15:33:20 2014 taille_a
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

int		verif_existing_label(t_list **list, char *label)
{
  t_list	*elem;

  elem = (*list);
  if (elem == NULL)
    return (0);
  elem = elem->next;
  while (elem != NULL)
    {
      if (elem->is_a_label != NULL)
	if (my_strcmp(label , elem->is_a_label) == 0)
	  return (INVALID_FILE);
      elem = elem->next;
    }
  return (0);
}

int		verif_label(char *buff)
{
  int		i;
  int		cpt;

  i = 0;
  if (buff == NULL)
    return (INVALID_FILE);
  while ((buff[i] == ' ' || buff[i] == '\t' ||
	  buff[i] == '-') && buff[i] != '\0')
    ++i;
  while (buff[i] && buff[i] != ':')
    {
      cpt = 0;
      while (LABEL_CHARS[cpt] != buff[i] && LABEL_CHARS[cpt] != '\0')
	cpt++;
      if (LABEL_CHARS[cpt] == '\0')
	return (INVALID_FILE);
      ++i;
    }
  return (0);
}

int		verif_register(char *buff)
{
  int		i;

  if (buff == NULL)
    return (INVALID_FILE);
  i = 0;
  while (buff[i] == ' ' || buff[i] == '\t' || buff[i] == '-')
    ++i;
  if (buff[i] != 'r')
      return (INVALID_FILE);
  ++i;
  while (buff[i] != '\0')
    {
      if (buff[i] > '9' || buff[i] < '0')
	  return (INVALID_FILE);
      ++i;
    }
  return (0);
}

int		verif_indirect(char *buff)
{
  int		i;

  i = 0;
  if (buff == NULL)
    return (INVALID_FILE);
  while (buff[i] == ' ' || buff[i] == '\t' || buff[i] == '-')
    ++i;
  while (buff[i] != '\0')
    {
      if (buff[i] > '9' || buff[i] < '0')
	return (INVALID_FILE);
      ++i;
    }
  return (0);
}

int		verif_direct(char *buff)
{
  int		verif;

  verif = 0;
  if (buff == NULL)
    return (INVALID_FILE);
  if (buff[0] != DIRECT_CHAR)
    return (INVALID_FILE);
  if (buff[1] == LABEL_CHAR)
    verif = 1;
  if (verif == 0)
    {
      if ((verif_direct2(buff)) == INVALID_FILE)
	return (INVALID_FILE);
    }
  else
    {
      if ((verif_label_in_dir(buff)) == INVALID_FILE)
	return (INVALID_FILE);
    }
  return (0);
}
