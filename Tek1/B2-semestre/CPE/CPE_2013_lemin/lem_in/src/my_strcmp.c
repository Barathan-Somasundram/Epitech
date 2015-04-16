/*
** my_strcmp.c for my_strcmp in /home/song_k/rendu/Piscine-C-lib/my
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Tue Oct 22 18:37:12 2013 song_k
** Last update Thu May  1 16:59:09 2014 song_k
*/

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (!s1 && s2)
    return (0 - s2[0]);
  else if (s1 && !s2)
    return (s1[0]);
  while ((s1 && s2) && (s1[i] || s2[i]))
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      ++i;
    }
  return (0);
}
