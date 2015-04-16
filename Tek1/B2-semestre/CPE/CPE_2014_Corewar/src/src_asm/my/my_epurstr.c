/*
** my_epurstr.c for corewar in /home/sam_t/Workstation/CPE_2014_corewar/sam_t
**
** Made by sam_t
** Login   <sam_t@epitech.net>
**
** Started on  Sun Mar 30 13:37:43 2014 sam_t
** Last update Fri Apr 11 16:52:39 2014 taille_a
*/

#include <stdlib.h>

void	s_info(char *s, int *space_nbr, int *char_nbr)
{
  int	i;

  *space_nbr = 0;
  *char_nbr = 0;
  i = 0;
  while (s[i])
    {
      while (s[i] && (s[i] == ' ' || s[i] == '\t'))
	++i;
      if (s[i] && *char_nbr != 0)
	++*space_nbr;
      while (s[i] && s[i] != ' ' && s[i] != '\t')
	{
	  ++i;
	  ++*char_nbr;
	}
    }
}

char	*epuring_str(char *s, int space_nbr, int char_nbr)
{
  char	*new_s;
  int	i;
  int	j;

  if ((new_s = malloc(sizeof(char) * (space_nbr + char_nbr + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s[i])
    {
      while (s[i] && (s[i] == ' ' || s[i] == '\t'))
	++i;
      if (j != 0)
	new_s[j++] = ' ';
      while (s[i] && s[i] != ' ' && s[i] != '\t')
	new_s[j++] = s[i++];
    }
  new_s[j] = '\0';
  return (new_s);
}

char	*my_epurstr(char *s)
{
  int	space_nbr;
  int	char_nbr;
  char	*new_s;

  if (s == NULL)
    return (NULL);
  s_info(s, &space_nbr, &char_nbr);
  new_s = epuring_str(s, space_nbr, char_nbr);
  return (new_s);
}
