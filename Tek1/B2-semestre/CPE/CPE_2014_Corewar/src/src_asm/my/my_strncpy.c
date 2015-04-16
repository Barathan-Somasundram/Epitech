/*
** my_strncpy.c for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 13:39:46 2014 taille_a
** Last update Thu Apr  3 19:26:05 2014 taille_a
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

void	my_strncpy(char *dest, char *src, int n, int i)
{
  int	cpt;

  cpt = 0;
  while (n < i && src[n] != '\0')
    {
      dest[cpt] = src[n];
      ++n;
      ++cpt;
    }
  dest[cpt] = '\0';
}
