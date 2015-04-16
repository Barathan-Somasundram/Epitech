/*
** my_checkcharfromstr.c for lemin in /home/song_k/rendu/lemin-2016-song_k/workgit/song_k
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Fri Apr 11 16:06:56 2014 song_k
** Last update Fri Apr 25 13:36:16 2014 song_k
*/

#include "lemin.h"

int	my_checkcharfromstr(char *str, char *lib)
{
  int	i;
  int	ct;

  i = 0;
  while (str && str[i])
    {
      ct = 0;
      while (lib[ct] && lib[ct] != str[i])
	++ct;
      if (lib[ct] == '\0')
	return (-1);
      ++i;
    }
  return (0);
}
