/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/somasu_b/
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Jan 22 18:55:40 2013 somasu_b
** Last update Sun Mar  9 21:32:47 2014 somasu_b
*/

#include <unistd.h>
#include <stdlib.h>

int	is_word(int c, char *sep)
{
  int	i;

  i = 0;
  while (sep[i] != '\0' && c != sep[i])
    ++i;
  if (sep[i] == '\0' && c != '\0')
    return (1);
  return (0);
}

int	count_word(char *str, char *sep)
{
  int	i;
  int	word;

  i = 0;
  word = 0;
  while (is_word(str[i], sep) == 0 && str[i] != '\0')
    ++i;
  while (str[i] != '\0')
    {
      while (is_word(str[i], sep) == 1)
	++i;
      ++word;
      while (is_word(str[i], sep) == 0 && str[i] != '\0')
	++i;
    }
  return (word);
}

int	my_getlen(char *str, char *sep, int pos)
{
  int	i;
  int	size;
  int	word;

  i = 0;
  word = 0;
  while (is_word(str[i], sep) == 0 && str[i] != '\0')
    ++i;
  while (str[i] != '\0' && word < pos)
    {
      size = 0;
      while (is_word(str[i], sep) == 1)
	{
	  ++i;
	  ++size;
	}
      ++word;
      while (is_word(str[i], sep) == 0 && str[i] != '\0')
	++i;
    }
  return (size);
}

char	**my_gettab(char *str, char *sep)
{
  char	**wordtab;
  int	i;
  int	word_size;
  int	tab_size;

  tab_size = count_word(str, sep) + 1;
  if ((wordtab = malloc(sizeof(wordtab) * tab_size)) == NULL)
    return (NULL);
  i = 1;
  while (i < tab_size)
    {
      word_size = my_getlen(str, sep, i);
      if ((wordtab[i - 1] = malloc(sizeof(*wordtab) * word_size)) == NULL)
	return (NULL);
      ++i;
    }
  wordtab[i - 1] = NULL;
  return (wordtab);
}

char	**my_str_to_wordtab(char *str, char *sep)
{
  char	**wordtab;
  int	word;
  int	i;
  int	pos;

  if (str == NULL)
    return (NULL);
  i = 0;
  word = 0;
  if ((wordtab = my_gettab(str, sep)) == NULL)
    return (NULL);
  while (is_word(str[i], sep) == 0 && str[i] != '\0')
    ++i;
  while (str[i] != '\0')
    {
      pos = 0;
      while (is_word(str[i], sep) == 1)
	wordtab[word][pos++] = str[i++];
      wordtab[word++][pos] = '\0';
      while (is_word(str[i], sep) == 0 && str[i] != '\0')
	++i;
    }
  return (wordtab);
}
