/*
** my_strcat.c for corewar in /home/sam_t/Workstation/CPE_2014_corewar/sam_t/ASM
**
** Made by sam_t
** Login   <sam_t@epitech.net>
**
** Started on  Sun Mar 30 15:21:11 2014 sam_t
** Last update Sat Apr 12 13:06:42 2014 taille_a
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *s1, char *s2)
{
  char	*scat;
  int	i;
  int	j;

  if (s1 == NULL || s2 == NULL)
    return (NULL);
  if ((scat = malloc(sizeof(char) *
		     (my_strlen(s1) + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s1[i])
    scat[j++] = s1[i++];
  i = 0;
  while (s2[i])
    scat[j++] = s2[i++];
  scat[j] = '\0';
  return (scat);
}
