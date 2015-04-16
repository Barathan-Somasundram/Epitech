/*
** shows.c for alum-1 in /home/somasu_b/TEST/alum-1/sources
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sat Feb  8 14:18:29 2014 somasu_b
** Last update Sun Feb 16 21:29:39 2014 somasu_b
*/

#include <signal.h>
#include "../../includes/bonus.h"

void	show_smiley(t_alum *tmp_al, int line)
{
  t_line	*tmp_li;
  int		i;

  i = 0;
  tmp_li = tmp_al->line->next;
  while (i++ <= line)
    my_putstr(" ");
  while (tmp_li != tmp_al->line)
    {
      if (tmp_li->cursor == TRUE)
	tputs(tgetstr("mr", NULL), 1, my_putchar);
      if (tmp_li->select == TRUE)
	my_putstr(B_CYAN "☻" NORMAL);
      else
	my_putstr(B_RED "☻" NORMAL);
      tputs(tgetstr("me", NULL), 1, my_putchar);
      tmp_li = tmp_li->next;
    }
  my_putstr("\n");
}

void	show_tige(t_alum *tmp_al, int line)
{
  t_line	*tmp_li;
  int		i;

  tmp_li = tmp_al->line->next;
  i = 0;
  while (i++ <= line)
    my_putstr(" ");
  while (tmp_li != tmp_al->line)
    {
      if (tmp_li->cursor == TRUE)
	tputs(tgetstr("mr", NULL), 1, my_putchar);
      my_putstr(B_YELLOW);
      my_putstr(tmp_li->match);
      my_putstr(NORMAL);
      tputs(tgetstr("me", NULL), 1, my_putchar);
      tmp_li = tmp_li->next;
    }
  my_putstr("\n");
}

void		my_show(t_alum **alum, int line)
{
  t_alum	*tmp_al;
  t_line	*tmp_li;
  int		i;

  tmp_al = (*alum)->next;
  while (tmp_al != *alum)
    {
      show_smiley(tmp_al, line);
      show_tige(tmp_al, line);
      tmp_al = tmp_al->next;
      line = line - 1;
    }
}
