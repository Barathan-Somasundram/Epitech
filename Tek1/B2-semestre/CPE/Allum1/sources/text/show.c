/*
** show.c for alum-1 in /home/somasu_b/TEST/alum-1/sources/text
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Fri Feb  7 17:44:08 2014 somasu_b
** Last update Tue Feb 11 18:47:59 2014 somasu_b
*/

#include "game.h"

int	opening(void)
{
  my_clear_full_screen();
  if ((texture("../../texture/open.txt")) == -1)
    return (-1);
  my_getchar();
  return (0);
}

static void	show_player2(t_menu *tmp)
{
  if (tmp->cursor == TRUE)
    {
      my_putstr(B_MAGENTA);
      my_putstr(tmp->submenu);
      my_putstr(NORMAL);
    }
  else
    my_putstr(tmp->submenu);
  my_putstr(" : ◄ ");
  if (tmp->mode == FALSE)
    my_putstr(" IA   ►\n\n\n");
  else
    my_putstr("HUMAN ►\n\n\n");
}

static void	show_line(t_menu *tmp)
{
  if (tmp->cursor == TRUE)
    {
      my_putstr(B_MAGENTA);
      my_putstr(tmp->submenu);
      my_putstr(NORMAL);
    }
  else
    my_putstr(tmp->submenu);
  my_putstr(": ◄ ");
  if (tmp->nb_alum < 10)
    my_putstr("0");
  my_putnbr(tmp->nb_alum);
  my_putstr(" ►\n\n\n");
}

static void	show_music(t_menu *tmp)
{
  if (tmp->cursor == TRUE)
    {
      my_putstr(B_MAGENTA);
      my_putstr(tmp->submenu);
      my_putstr(NORMAL);
    }
  else
    my_putstr(tmp->submenu);
  my_putstr(": ◄ ");
  if (tmp->mode == FALSE)
    my_putstr(" ON  ►\n\n\n");
  else
    my_putstr(" OFF ►\n\n\n");
}

int	show_menu(t_menu **menu)
{
  t_menu	*tmp;

  tputs(tgoto(tgetstr("cm", NULL), 40, 25), 1, my_putchar);
  tputs(tgetstr("vi", NULL), 1, my_putchar);
  tmp = (*menu)->next;
  my_putstr(B_GREEN "[PRESS ENTER] to Start\n\n\n" NORMAL);
  tputs(tgoto(tgetstr("cm", NULL), 40, 28), 1, my_putchar);
  show_player2(tmp);
  tmp = tmp->next;
  tputs(tgoto(tgetstr("cm", NULL), 40, 31), 1, my_putchar);
  show_line(tmp);
  tmp = tmp->next;
  tputs(tgoto(tgetstr("cm", NULL), 40, 34), 1, my_putchar);
  show_music(tmp);
  tmp = tmp->next;
  tputs(tgoto(tgetstr("cm", NULL), 40, 37), 1, my_putchar);
  my_putstr(B_RED " [PRESS ESC] to Exit\n" NORMAL);
  return (0);
}
