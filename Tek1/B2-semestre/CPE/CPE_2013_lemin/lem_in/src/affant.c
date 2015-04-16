/*
** affant.c for lemin in /home/somasu_b/prog_elem/song_k
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun May  4 23:23:45 2014 somasu_b
** Last update Sun May  4 23:23:53 2014 somasu_b
*/

#include "lemin.h"

void		affant(int id, char *name)
{
  my_putstr("P", 1);
  my_putnbr(id);
  my_putstr("-", 1);
  my_putstr(name, 1);
  my_putstr(" ", 1);
}
