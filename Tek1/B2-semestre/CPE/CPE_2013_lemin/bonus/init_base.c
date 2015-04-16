/*
** init_base.c for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sat Apr 26 18:12:43 2014 potier_g
** Last update Sun May  4 19:51:02 2014 potier_g
*/

#include <stdlib.h>
#include "struct.h"

char		*my_strdup(char *str)
{
  int		a;
  int		len;
  char		*cp;

  a = 0;
  len = my_strlen(str);
  if (str == NULL)
    return (NULL);
  if ((cp = malloc(len + 1)) == NULL)
    return (NULL);
  while (str[a] != '\0')
    cp[a] = str[a++];
  cp[a] = 0;
  return (cp);
}

int		my_strcmp(char *str1, char *str2)
{
  int		a;
  int		len1;
  int		len2;

  a = 0;
  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  if (str1 == NULL || str2 == NULL)
    return (0);
  while (a < len1 && a < len2)
    {
      if (str1[a] != str2[a])
	return (0);
      a++;
    }
  if (a == len1 && a < len2)
    return (0);
  if (a == len2 && a < len1)
    return (0);
  return (1);
}

t_base		*init_base(char *file, int line_s, int line_e, t_param *p)
{
  t_base        *base;
  int		line_act;
  char		*line;
  int		len;
  int		pos;

  pos = 0;
  len = line_e - line_s - 1;
  p->size_base = len;
  if ((base = malloc(sizeof(*base) * len)) == NULL)
    return (NULL);
  line_act = line_s;
  while (pos < len)
    {
      line = recup_line(file, line_act);
      if (line[0] != '#')
	{
	  base[pos].name = recup_word(line, 0);
	  base[pos].x = my_get_nbr(recup_word(line, 1));
	  base[pos].y = my_get_nbr(recup_word(line, 2));
	  pos++;
	}
      line_act++;
    }
  return (base);
}
