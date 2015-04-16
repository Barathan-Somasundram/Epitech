/*
** my_ls.c for my_ls in /home/somasu_b/my_files
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Nov 30 00:02:52 2013 a
** Last update Sun Dec  1 20:19:42 2013 a
*/

#include "my_ls.h"

void		recursive(t_list *files, char *directory, char *flag)
{
  struct stat	statbuf;
  char		*path;

  my_putchar('\n');
  while (files != NULL)
    {
      path = strcat_path(directory, files->name);
      if ((lstat(path, &statbuf)) != -1)
	if (fill_type(statbuf.st_mode) == 'd' && ((files->name)[0] != '.'))
	  my_ls(path, flag);
      free(path);
      files = files->next;
    }
}

t_list		*my_put_in_list(t_list *files, struct stat statbuf,
				char *name, char *flag)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    exit(0);
  elem->statbuf = statbuf;
  elem->name = name;
  if (flag[3] == '0')
    tri_alpha(&elem, &files, name);
  else
    tri_time(&elem, &files, statbuf);
  return (files);
}

int		fill_data(struct dirent *dir_list, t_list **files,
			  char *directory, char *flag)
{
  struct stat	statbuf;
  char		*path;

  path = strcat_path(directory, dir_list->d_name);
  if ((lstat(path, &statbuf)) != -1)
    {
      if ((dir_list->d_name)[0] != '.')
	*files = my_put_in_list(*files, statbuf, dir_list->d_name, flag);
    }
  free(path);
  return (statbuf.st_blocks);
}

int	print_choice(t_list *files, char *flag, char *directory, int total)
{
  if (flag[0] == '0')
    my_print_no_data(files);
  else if (flag[0] == '1')
    my_print_l_data(files, (total / 2));
  else
    return (-1);
  if (flag[1] == '1')
    recursive(files, directory, flag);
}

int		my_ls(char *directory, char *flag)
{
  DIR		*dirp;
  struct dirent	*dir_list;
  struct stat	statbuf;
  t_list	*files;
  int		total;

  total = 0;
  files = NULL;
  if (flag[1] == '1')
    {
      my_putstr(directory);
      my_putstr(":\n");
    }
  if ((dirp = opendir(directory)) == NULL)
    return (-1);
  while ((dir_list = readdir(dirp)) != NULL)
    {
      total = total + fill_data(dir_list, &files, directory, flag);
    }
  print_choice(files, flag, directory, total);
  closedir(dirp);
  free(files);
  return (0);
}
