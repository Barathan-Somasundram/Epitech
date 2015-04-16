/*
** my_strlen.c for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 16:19:06 2014 taille_a
** Last update Sat Apr 12 13:03:38 2014 taille_a
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}
