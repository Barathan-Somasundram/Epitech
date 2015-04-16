/*
** epur_str.c for corewar in /home/taille_a/Travail/corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Sat Apr  5 13:04:28 2014 taille_a
** Last update Sat Apr  5 13:05:55 2014 taille_a
*/

char		*epur_str(char *str, int n)
{
  int		i;

  i = 0;
  while (str[n])
    {
      str[i] = str[n];
      ++i;
      ++n;
    }
  str[i] = '\0';
  return (str);
}
