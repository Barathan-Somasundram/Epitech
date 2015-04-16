/*
** my_print.c for my_ls in /home/somasu_b/my_files
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Nov 30 00:00:08 2013 a
** Last update Sun Dec  1 20:31:33 2013 a
*/

#include "my_ls.h"

void	date_time(char *info_modif)
{
  int	i;

  i = 3;
  while (i < 16)
    {
      my_putchar(info_modif[i]);
      i = i + 1;
    }
}

char	*strcat_path(char *direct, char *file)
{
  char	*path;
  int	i;
  int	j;

  i = 0;
  j = 0;
  path = malloc(sizeof(char) * (my_strlen(direct) + my_strlen(file) + 2));
  if (path == NULL)
    return (NULL);
  while (j < my_strlen(direct))
    path[i++] = direct[j++];
  if (direct[j - 1] != '/')
    path[i++] = '/';
  j = 0;
  while (j < my_strlen(file))
    path[i++] = file[j++];
  path[i] = '\0';
  return (path);
}

void		my_print_no_data(t_list *files)
{
  t_list	*tmp;

  tmp = files;
  while (tmp != NULL)
    {
      if ((tmp->name)[0] != '.')
	{
	  my_putstr(tmp->name);
	  if (tmp->next != NULL)
	    my_putchar('\n');
	}
      tmp = tmp->next;
    }
  my_putchar('\n');
}

void		l_data(t_list *tmp, struct passwd *pwd, struct group *grp)
{
  my_putchar(fill_type((tmp->statbuf).st_mode));
  my_putstr(fill_rights((tmp->statbuf).st_mode));
  my_putchar(' ');
  my_putnbr((tmp->statbuf).st_nlink);
  my_putchar(' ');
  if ((pwd = getpwuid((tmp->statbuf).st_uid)) != NULL)
    my_putstr(pwd->pw_name);
  my_putchar(' ');
  if ((grp = getgrgid((tmp->statbuf).st_gid)) != NULL)
    my_putstr(grp->gr_name);
  my_putchar(' ');
  my_putnbr((tmp->statbuf).st_size);
  date_time(ctime(&(tmp->statbuf).st_mtime));
  my_putchar(' ');
  my_putstr(tmp->name);
  my_putchar('\n');
}

void		my_print_l_data(t_list *files, int total)
{
  t_list	*tmp;
  struct passwd	*pwd;
  struct group	*grp;

  tmp = files;
  if (total != -1)
    {
      my_putstr("total ");
      my_putnbr(total);
      my_putchar('\n');
    }
  while (tmp != NULL)
    {
      l_data(tmp, pwd, grp);
      tmp = tmp->next;
    }
}
