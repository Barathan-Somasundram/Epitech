/*
** tri.c for my_ls.c in /home/somasu_b/my_files
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Dec  1 19:41:10 2013 a
** Last update Sun Dec  1 19:41:52 2013 a
*/

#include "my_ls.h"

void            tri_alpha(t_list **elem, t_list **files, char *name)
{
  t_list        *tmp;
  t_list        *buf;

  tmp = NULL;
  buf = *files;
  while (buf != NULL && my_strcmp(buf->name, name) <= 0)
    {
      tmp = buf;
      buf = buf->next;
    }
  (*elem)->next = buf;
  if (tmp != NULL)
    tmp->next = *elem;
  else
    *files = *elem;
}

void            tri_time(t_list **elem, t_list **files, struct stat sb)
{
  t_list        *tmp;
  t_list        *buf;

  tmp = NULL;
  buf = *files;
  while (buf != NULL && ((buf->statbuf.st_mtime) - (sb.st_mtime)) >= 0)
    {
      tmp = buf;
      buf = buf->next;
    }
  (*elem)->next = buf;
  if (tmp != NULL)
    tmp->next = *elem;
  else
    *files = *elem;
}
