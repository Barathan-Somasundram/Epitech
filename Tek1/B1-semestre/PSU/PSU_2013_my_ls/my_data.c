/*
** my_data.c for my_ls in /home/somasu_b/my_files
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Nov 30 00:46:44 2013 a
** Last update Sun Dec  1 19:28:58 2013 a
*/

#include "my_ls.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_strlowcase(char *s1)
{
  int		compare;

  compare = 0;
  while (s1[compare] != '\0')
    {
      if (s1[compare] >= 'A' && s1[compare] <= 'Z')
	s1[compare] = 32 + s1[compare];
      compare = compare + 1;
    }
  return (s1);
}

int		my_strcmp(char *s1, char *s2)
{
  int		compare;
  char		*length;
  char		*s1bis;
  char		*s2bis;

  s1bis = malloc(sizeof(char) * my_strlen(s1) + 1);
  s1bis = my_strcpy(s1bis, s1);
  s1bis[my_strlen(s1)] = '\0';
  s2bis = malloc(sizeof(char) * my_strlen(s2) + 1);
  s2bis = my_strcpy(s2bis, s2);
  s2bis[my_strlen(s2)] = '\0';
  s1bis = my_strlowcase(s1bis);
  s2bis = my_strlowcase(s2bis);
  length = (my_strlen(s1bis) < my_strlen(s2bis)) ? (s1bis) : (s2bis);
  compare = 0;
  while (s1bis[compare] == s2bis[compare] && length[compare] != '\0')
    compare = compare + 1;
  compare = s1bis[compare] - s2bis[compare];
  free(s1bis);
  free(s2bis);
  return (compare);
}

char            fill_type(mode_t s_type)
{
  if (S_ISDIR(s_type))
    return ('d');
  else if (S_ISCHR(s_type))
    return ('c');
  else if (S_ISBLK(s_type))
    return ('b');
  else if (S_ISLNK(s_type))
    return ('l');
  else if (S_ISFIFO(s_type))
    return ('p');
  else if (S_ISSOCK(s_type))
    return ('s');
  else if (S_ISREG(s_type))
    return ('-');
}

char            *fill_rights(mode_t s_rights)
{
  char  *filled_rights;

  filled_rights = malloc(sizeof(char) * 10);
  filled_rights[0] = (s_rights & S_IRUSR) ? ('r') : ('-');
  filled_rights[1] = (s_rights & S_IWUSR) ? ('w') : ('-');
  filled_rights[2] = (s_rights & S_IXUSR) ? ('x') : ('-');
  filled_rights[2] = (s_rights & S_ISUID) ? ('s') : (filled_rights[2]);
  filled_rights[3] = (s_rights & S_IRGRP) ? ('r') : ('-');
  filled_rights[4] = (s_rights & S_IWGRP) ? ('w') : ('-');
  filled_rights[5] = (s_rights & S_IXGRP) ? ('x') : ('-');
  filled_rights[5] = (s_rights & S_ISGID) ? ('s') : (filled_rights[5]);
  filled_rights[6] = (s_rights & S_IROTH) ? ('r') : ('-');
  filled_rights[7] = (s_rights & S_IWOTH) ? ('w') : ('-');
  filled_rights[8] = (s_rights & S_IXOTH) ? ('x') : ('-');
  filled_rights[8] = (s_rights & S_ISVTX) ? ('t') : (filled_rights[8]);
  filled_rights[9] = '\0';
  return (filled_rights);
}
